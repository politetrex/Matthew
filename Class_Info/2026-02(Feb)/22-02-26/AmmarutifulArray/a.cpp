#include <iostream>
#include <map>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n;
	std::cin >> n;
	vector<int> arr(n);
	for (int &i : arr) { std::cin >> i; }
	vector<int> color(n);
	for (int &c : color) { std::cin >> c; }

	std::map<int, vector<long long>> col_prefs;
	for (int i = 0; i < n; i++) {
		int c = color[i];
		if (!col_prefs.count(c)) { col_prefs[c] = {0}; }
		col_prefs[c].push_back(col_prefs[c].back() + arr[i]);
	}

	long long tot_inc = 0;
	std::map<int, long long> col_exclude;

	int query_num;
	std::cin >> query_num;
	for (int q = 0; q < query_num; q++) {
		int q_type, col;
		long long arg;
		std::cin >> q_type >> col >> arg;

		if (q_type == 1) {
			tot_inc += arg;
			col_exclude[col] += arg;
		} else if (q_type == 2) {
			int lo = 0;
			int hi = col_prefs[col].size() - 1;
			int valid = -1;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;
				long long init_val = col_prefs[col][mid];
				long long to_add = (tot_inc - col_exclude[col]) * mid;
				if (init_val + to_add <= arg) {
					valid = mid;
					lo = mid + 1;
				} else {
					hi = mid - 1;
				}
			}

			cout << valid << '\n';
		}
	}
}