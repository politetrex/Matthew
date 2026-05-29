#define T int
#define DEFAULTVAL 0
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
vector<pair<int, int>> DIRS = DIRS_RECTILINEAR;

int bestScore = numeric_limits<int>::max();
int R, C;
bool original[69][69], seen[69][69], sol[69][69];
string name, msg;


bool _seen[MAXSIZE + 5][MAXSIZE + 5]; // dont use this externally, it is used temporarily by Grid and recyclced
unordered_map<string, T> findreplace = {};
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
				/*string s;
				in >> s;
				if (findreplace.find(s) != findreplace.end()) grid[r][c] = findreplace[s];
				else grid[r][c] = stringtoT(s);*/
				string s;
				in >> s;
				if (s.back() == '*') {
					grid[r][c] = stoi(s.substr(0, s.size() - 1));
					original[r][c] = true;
				}
				else {
					grid[r][c] = stoi(s);
					original[r][c] = false;
				}
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
				if (!printed) out << grid[r][c] << (sol[r][c] ? '*' : ' ') << ' ';
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

	T getVal(int r, int c, T defaultVal=DEFAULTVAL) {
		if (validCoord(r, c)) return grid[r][c];
		return defaultVal;
	}
	T getVal(pair<int, int> coord, T defaultVal=DEFAULTVAL) {
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

	int count(T val) {
		int total = 0;
		for (int r = 0; r < R; ++r) {
			for (int c = 0; c < C; ++c) total += grid[r][c] == val;
		}
		return total;
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

	void bfs(int r, int c, bool (*validValue)(int, int), vector<pair<int, int>> dirs = DIRS) {
		fill(_seen[0], _seen[MAXSIZE + 4], false);

		if (!validCoord(r, c)) return;
		if (!validValue(r, c)) return;
		
		_seen[r][c] = true;
		queue<pair<int, int>> q;
		q.push({ r, c });

		while (!q.empty()) {
			auto curr = q.front();
			q.pop();
			
			for (pair<int, int> adj : adjCoords(curr.first, curr.second)) {
				if (!_seen[adj.first][adj.second] && validValue(adj.first, adj.second)) {
					_seen[adj.first][adj.second] = true;
					q.push(adj);
				}
			}
		}
	}
	void bfs(pair<int, int> coord, bool (*validValue)(int, int), vector<pair<int, int>> dirs = DIRS) {
		return bfs(coord, validValue, dirs);
	}

	int regionSize(int r, int c, bool (*validValue)(int, int), vector<pair<int, int>> dirs = DIRS) {
		bfs(r, c, validValue, dirs);
		return accumulate(_seen[0], _seen[MAXSIZE + 4], 0);
	}
	int regionSize(pair<int, int> coord, bool (*validValue)(int, int), vector<pair<int, int>> dirs = DIRS) {
		return regionSize(coord.first, coord.second, validValue, dirs);
	}

	bool isSurroundedBy(int r, int c, T val, bool (*validValue)(int, int), vector<pair<int, int>> dirs = DIRS) {
		bfs(r, c, validValue, dirs);
		for (int r = 0; r < R; ++r) {
			for (int c = 0; c < C; ++c) {
				if (validValue(r, c)) {
					for (pair<int, int> adj : adjCoords(r, c)) {
						if (!validValue(adj.first, adj.second) && getVal(adj) != val) return false;
					}
				}
			}
		}
		return true;
	}
	bool isSurroundedBy(pair<int, int> coord, T val, bool (*validValue)(int, int), vector<pair<int, int>> dirs = DIRS) {
		return isSurroundedBy(coord.first, coord.second, val, validValue, dirs);
	}

};

Grid g;

bool checkCol(int c) {
	int total = 0;
	set<int> vals;
	for (int r = 0; r < R; ++r) {
		if (seen[r][c]) {
			if (seen[r + 1][c]) return false;
			if (c > 0 && seen[r][c - 1]) return false;
		}
		else {
			++total;
			vals.insert(g.getVal(r, c));
		}
	}
	return total == vals.size();
}

bool checkRow(int r) {
	int total = 0;
	set<int> vals;
	for (int c = 0; c < C; ++c) {
		if (seen[r][c]) {
			if (seen[r][c + 1]) return false;
		}
		else {
			++total;
			vals.insert(g.getVal(r, c));
		}
	}
	return total == vals.size();
}

bool notSeen(int r, int c) {
	return !seen[r][c];
}

void dfs(int c) {
	int area = 0;
	pair<int, int> unseenCoord = { -1, -1 };
	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < C; ++c) {
			area += !seen[r][c];
			if (unseenCoord.first == -1 && !seen[r][c]) unseenCoord = { r, c };
		}
	}
	if (area >= bestScore) return;

	if (c == C) {
		for (int r = 0; r < R; ++r) {
			if (!checkRow(r)) return;
		}
		
		if (unseenCoord.first != -1) {
			if (g.regionSize(unseenCoord, notSeen) == area) {
				if (area < bestScore) {
					bestScore = area;
					copy(seen[0], seen[60], sol[0]);
				}
			}
		}
		return;
	}
	for (int i = 0; i < (1 << R); ++i) {
		bool ok = true;
		for (int r = 0; r < R; ++r) {
			seen[r][c] = (i >> r) % 2;
			if (original[r][c] && !seen[r][c]) ok = false;
		}
		if (ok && checkCol(c)) dfs(c + 1);
	}
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	ifstream cin{ ".txt" };
	//ofstream cout{ ".txt" };
	while (true) {
		bestScore = numeric_limits<int>::max();
		fill(seen[0], seen[60], false);
		fill(original[0], original[60], false);
		cin >> R >> name;
		C = R;
		if (R == 0 || name == "END") break;

		g.init(R, C, cin);
		g.print();
		dfs(0);
		if (bestScore != numeric_limits<int>::max()) {
			cout << "SOLUTION\n";
			g.print(); cout << "\n";
		}
		else {
			cout << "UNSOLVABLE\n";
			cout << msg << "\n";
		}
	}
}
