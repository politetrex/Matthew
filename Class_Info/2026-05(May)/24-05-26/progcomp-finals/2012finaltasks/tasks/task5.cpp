#define T int
#define stringtoT stoi
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <assert.h>
#include <numeric>
#include <fstream>
#include <iomanip>
#include <random>
#include <math.h>
#include <time.h>
#include <string>
#include <vector>
#include <limits>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef long double ld;
constexpr ll MAX = 1 << 18;
constexpr int MAXSIZE = 1000;
vector<pair<int, int>> DIRS_RECTILINEAR = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
vector<pair<int, int>> DIRS_ALL = { {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
vector<pair<int, int>> DIRS = DIRS_ALL;

bool _seen[MAXSIZE + 5][MAXSIZE + 5]; // dont use this externally, it is used temporarily by Grid and recyclced
unordered_map<string, T> findreplace = { {".", -1}, {"X", -2}, {"*", 8} };
struct Grid {
	int R = -1, C = -1;
	T grid[MAXSIZE + 5][MAXSIZE + 5];
	Grid() {

	}

	void init(int _R, int _C, istream& in = cin) {
		R = _R;
		C = _C;
		assert(0 <= R && R <= MAXSIZE);
		assert(0 <= C && C <= MAXSIZE);
		for (int r = 0; r < R; ++r) {
			for (int c = 0; c < C; ++c) {
				string s;
				in >> s;
				if (findreplace.find(s) != findreplace.end()) grid[r][c] = findreplace[s];
				else grid[r][c] = stringtoT(s);
			}
		}
	}

	void print(ostream& out = cout) {
		for (int r = 0; r < R; ++r) {
			for (int c = 0; c < C; ++c) {
				bool printed = false;
				for (auto val : findreplace) {
					if (val.second == grid[r][c]) {
						out << val.first << ' ';
						printed = true;
						break;
					}
				}
				if (!printed) out << grid[r][c] << ' ';
			}
			out << '\n';
		}
	}

	void flip() {
		// flip over main diagonal
		for (int r = 0; r < max(R, C); ++r) {
			for (int c = 0; c < r; ++c) swap(grid[r][c], grid[c][r]);
		}
		swap(R, C);
	}

	bool validCoord(int r, int c) {
		return 0 <= r && r < R && 0 <= c && c < C;
	}
	bool validCoord(pair<int, int> coord) {
		return validCoord(coord.first, coord.second);
	}

	void setVal(int r, int c, T val) {
		if (validCoord(r, c)) grid[r][c] = val;
	}
	void setVal(pair<int, int> coord, T val) {
		setVal(coord.first, coord.second, val);
	}

	T getVal(int r, int c, T defaultVal=0) {
		if (validCoord(r, c)) return grid[r][c];
		return defaultVal;
	}
	T getVal(pair<int, int> coord, T defaultVal=0) {
		return getVal(coord.first, coord.second, defaultVal);
	}

	pair<int, int> findVal(T val) {
		for (int r = 0; r < R; ++r) {
			for (int c = 0; c < C; ++c) {
				if (grid[r][c] == val) return { r, c };
			}
		}
		return { -1, -1 };
	}
	bool containsVal(T val) {
		return findVal(val).first != -1;
	}

	vector<pair<int, int>> findAllVal(T val) {
		vector<pair<int, int>> output;
		for (int r = 0; r < R; ++r) {
			for (int c = 0; c < C; ++c) {
				if (grid[r][c] == val) output.push_back({ r, c });
			}
		}
		return output;
	}

	vector<pair<int, int>> adjCoords(int r, int c, vector<pair<int, int>> dirs = DIRS) {
		vector<pair<int, int>> output;
		for (pair<int, int> dir : dirs) {
			int newR = r + dir.first, newC = c + dir.second;
			if (validCoord(newR, newC)) output.push_back({ newR, newC });
		}
		return output;
	}
	vector<pair<int, int>> adjCoords(pair<int, int> coord, vector<pair<int, int>> dirs = DIRS) {
		return adjCoords(coord.first, coord.second, dirs);
	}

	void bfs(int r, int c, bool (*validValue)(T), vector<pair<int, int>> dirs = DIRS) {
		if (!validValue(grid[r][c])) return;

		fill(_seen[0], _seen[MAXSIZE + 4], false);
		_seen[r][c] = true;
		queue<pair<int, int>> q;
		q.push({ r, c });

		while (!q.empty()) {
			auto curr = q.front();
			q.pop();

			for (pair<int, int> adj : adjCoords(r, c)) {
				if (!_seen[adj.first][adj.second] && validValue(getVal(adj))) {
					_seen[adj.first][adj.first] = true;
					q.push(adj);
				}
			}
		}
	}
	void bfs(pair<int, int> coord, bool (*validValue)(T), vector<pair<int, int>> dirs = DIRS) {
		return bfs(coord, validValue, dirs);
	}

	int regionSize(int r, int c, bool (*validValue)(T), vector<pair<int, int>> dirs = DIRS) {
		bfs(r, c, validValue, dirs);
		return accumulate(_seen[0], _seen[MAXSIZE + 4], 0);
	}
	int regionSize(pair<int, int> coord, bool (*validValue)(T), vector<pair<int, int>> dirs = DIRS) {
		return regionSize(coord.first, coord.second, validValue, dirs);
	}

	bool isSurroundedBy(int r, int c, T val, bool (*validValue)(T), vector<pair<int, int>> dirs = DIRS) {
		bfs(r, c, validValue, dirs);
		for (int r = 0; r < R; ++r) {
			for (int c = 0; c < C; ++c) {
				if (validValue(grid[r][c])) {
					for (pair<int, int> adj : adjCoords(r, c)) {
						T currVal = getVal(adj);
						if (!validValue(currVal) && currVal != val) return false;
					}
				}
			}
		}
		return true;
	}
	bool isSurroundedBy(pair<int, int> coord, T val, bool (*validValue)(T), vector<pair<int, int>> dirs = DIRS) {
		return isSurroundedBy(coord.first, coord.second, val, validValue, dirs);
	}

};
Grid g;

int R, C, N;
string msg;

bool isGrey(int r, int c) {
	return g.getVal(r, c) == -2;
}
bool isLight(int r, int c) {
	return g.getVal(r, c) == 8;
}
bool isNumber(int r, int c) {
	return 0 <= g.getVal(r, c) && g.getVal(r, c) <= 4;
}
bool isBlank(int r, int c) {
	return g.getVal(r, c) == -1;
}

bool isLit(int _r, int _c) {
	for (auto dir : DIRS_RECTILINEAR) {
		int dr = dir.first, dc = dir.second;
		for (int r = _r + dr, c = _c + dc; g.validCoord(r, c); r += dr, c += dc) {
			if (isLight(r, c)) return true;
			if (!isBlank(r, c)) break;
		}
	}
	return false;
}

bool rule1() {
	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < C; ++c) {
			if (isBlank(r, c) && !isLit(r, c)) {
				msg = "VIOLATES RULE 1";
				return false;
			}
		}
	}
	return true;
}

bool rule2() {
	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < C; ++c) {
			if (isLight(r, c) && isLit(r, c)) {
				msg = "VIOLATES RULE 2";
				return false;
			}
		}
	}
	return true;
}

bool rule3(int _r=R, int _c=C) {
	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < C; ++c) {
			if (isNumber(r, c) && r + 1 <= _r && c + 1 <= _c) {
				int total = isLight(r + 1, c) + isLight(r, c + 1) + isLight(r - 1, c) + isLight(r, c - 1);
				if (total != g.getVal(r, c)) {
					msg = "VIOLATES RULE 3";
					return false;
				}
			}
		}
	}
	return true;
}

// dfs template
bool dfs(int r, int c) {
	//g.print(); cout << "\n";
	if (r == 0 && c == C) {
		return rule1() && rule2() && rule3();
	}
	if (!isBlank(r, c) || isLit(r, c)) return dfs((r + 1) % R, c + (r == R - 1));
	
	g.setVal(r, c, 8);
	if (rule3(r, c)) {
		if (dfs((r + 1) % R, c + (r == R - 1))) return true;
	}
	g.setVal(r, c, -1);
	return dfs((r + 1) % R, c + (r == R - 1));
}


int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	//ifstream cin{ ".txt" };
	//ofstream cout{ ".txt" };
	cin >> R;
	C = R;
	g.init(R, C, cin);
	g.print();
	bool solvable = dfs(0, 0);
	if (solvable) {
		cout << "SOLUTION\n";
		g.print();
	}
	else {
		cout << "UNSOLVABLE\n";
		cout << msg << "\n";
	}
}
