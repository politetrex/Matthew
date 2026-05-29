#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
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
constexpr int MAXN = 100005;
constexpr pair<int, int> dirs[4] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0}, };
int N;
string name;
char grid[1005][1005];
bool seen[1005][1005];

bool valid(int i, int j) {
	return 0 <= min(i, j) && max(i, j) < N;
}


bool isLight(int i, int j) {
	return ('0' <= grid[i][j] && grid[i][j] <= '9') || grid[i][j] == 'L';
}

bool isDark(int i, int j) {
	return grid[i][j] == 'D';
}

bool bfsLight(int i, int j, bool debug=true) {
	queue<pair<int, int>> q;
	seen[i][j] = true;
	q.push({ i, j });
	int total = 1;
	vector<pair<int, int>> loc;
	if (grid[i][j] != 'L') loc.push_back({ i, j });
	while (!q.empty()) {
		auto curr = q.front();
		q.pop();

		for (auto dir : dirs) {
			int newI = curr.first + dir.first, newJ = curr.second + dir.second;
			if (valid(newI, newJ) && !seen[newI][newJ] && isLight(newI, newJ)) {
				if (grid[newI][newJ] != 'L') loc.push_back({ newI, newJ });
				total += 1;
				seen[newI][newJ] = true;
				q.push({ newI, newJ });
			}
		}
	}
	if (loc.size() == 0) {
		if (debug) cout << name << " violates rule 1: no numbered cell in island at [" << i << ", " << j << "] (0-origin)\n";
		return false;
	}
	if (loc.size() != 1) {
		if (debug) cout << name << " violates rule 1: multiples numbered cell in island at [" << loc[0].first << ", " << loc[0].second << "] (0-origin)\n";
		return false;
	}
	else if ((grid[loc[0].first][loc[0].second] - '0') != total) {
		if (debug) cout << name << " violates rule 2: sum of light cells in island at [" << i << ", " << j << "] (0-origin) does not equal how many cells the island contains\n";
		return false;
	}
	return true;
}

bool bfsDark(int i, int j, bool debug=true) {
	queue<pair<int, int>> q;
	seen[i][j] = true;
	q.push({ i, j });
	int total = 1;
	vector<pair<int, int>> loc;

	while (!q.empty()) {
		auto curr = q.front();
		q.pop();

		for (auto dir : dirs) {
			int newI = curr.first + dir.first, newJ = curr.second + dir.second;
			if (valid(newI, newJ) && !seen[newI][newJ] && isDark(newI, newJ)) {
				total += 1;
				seen[newI][newJ] = true;
				q.push({ newI, newJ });
				loc.push_back({ newI, newJ });
			}
		}
	}
	int allDark = count(grid[0], grid[1000], 'D');
	if (allDark != total) {
		if (debug) cout << name << " violates rule 4: dark cell at [" << loc[0].first << ", " << loc[0].second << "] (0-origin) is not connected to all the other dark cells\n";
		return false;
	}
	return true;
}

bool validGrid(bool debug=true) {
	fill(seen[0], seen[1000], false);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!seen[i][j]) {
				if (isLight(i, j)) {
					if (!bfsLight(i, j, debug)) return false;
				}
				else if (isDark(i, j)) {
					if (!bfsDark(i, j, debug)) return false;
				}
				/*else {
					if (debug) cout << name << " contains cells that are neither light nor dark\n";
					return false;
				}*/
			}
			if (i + 1 < N && j + 1 < N) {
				if (isDark(i, j) && isDark(i + 1, j) && isDark(i, j + 1) && isDark(i + 1, j + 1)) {
					if (debug) cout << name << " violates rule 5: contains 2x2 blocks of dark cells\n";
					return false;
				}
			}
		}
	}
	return true;
}

bool solveGrid(int i, int j) {
	if (i == 0 && j == N) {
		return validGrid(false);
	}
	if (grid[i][j] != '.') return solveGrid((i + 1) % N, j + (i == N - 1));
	for (char c : {'L', 'D'}) {
		grid[i][j] = c;
		if (solveGrid((i + 1) % N, j + (i == N - 1))) return true;
	}
	grid[i][j] = '.';
	return false;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	while (true) {
		cin >> N >> name;
		if (N == 0 || name == "END") break;
		fill(grid[0], grid[1000], '\0');
		bool solved = true;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> grid[i][j];
				if (grid[i][j] == '.') solved = false;
			}
		}
		if (solved) {
			if (validGrid()) {
				cout << name << " is Solved\n";
			}
		}
		else {
			cout << name << " is Unsolved\n";
			if (!solveGrid(0, 0)) validGrid(true);
			else {
				cout << N << " " << name << "\n";
				for (int i = 0; i < N; ++i) {
					for (int j = 0; j < N; ++j) cout << grid[i][j] << " ";
					cout << "\n";
				}
			}
		}
	}

}
