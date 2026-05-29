#include <algorithm>
#include <climits>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> haybales;

bool valid(int pos, int idx, int power, int dir) {
	// exploded leftmost haybale
	if (idx <= 0 && dir == 0) { return (idx < 0 || pos - power <= haybales[idx]); }

	// exploded rightmost haybale
	if (idx >= n - 1 && dir == 1) { return idx >= n || pos + power >= haybales[idx]; }

	if (dir == 0) {  // left
		if (pos - power <= haybales[0]) { return true; }

		// go as left as possible
		int next_idx = idx;
		while (next_idx >= 0 && pos - power <= haybales[next_idx]) { next_idx--; }

		// more movement is not possible
		if (next_idx == idx) { return false; }

		return valid(haybales[next_idx + 1], next_idx, power - 2, dir);
	} else {  // right
		if (pos + power >= haybales[n - 1]) { return true; }

		// go as right as possible
		int next_idx = idx;
		while (next_idx < n && haybales[next_idx] <= pos + power) { next_idx++; }

		// more movement is not possible
		if (next_idx == idx) { return false; }

		return valid(haybales[next_idx - 1], next_idx, power - 2, dir);
	}

	return false;
}

int main() {
	freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout);

	cin >> n;
	haybales.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> haybales[i];
		haybales[i] *= 2;  // double each position to eliminate decimals
	}
	sort(haybales.begin(), haybales.end());

	int l = 0, r = INT_MAX;
	while (l <= r) {
		int power = (r - l) / 2 + l;

		// find the rightmost haybale that can still reach the left
		int pos_l = 0, pos_r = INT_MAX;
		while (pos_l <= pos_r) {
			int pos = (pos_r - pos_l) / 2 + pos_l;

			// index of candidate haybale
			int idx = lower_bound(haybales.begin(), haybales.end(), pos) - haybales.begin();

			// can we explode all haybales on left?
			if (idx < n && valid(pos, idx, power, 0)) {
				pos_l = pos + 1;
			} else {
				pos_r = pos - 1;
			}
		}

		int idx = upper_bound(haybales.begin(), haybales.end(), pos_l) - haybales.begin();

		// can we explode all haybales on the right?
		if (valid(pos_l, idx, power, 1)) {
			r = power - 1;
		} else {
			l = power + 1;
		}
	}
	cout << fixed << setprecision(1) << (double)l / 2.0 << endl;
}