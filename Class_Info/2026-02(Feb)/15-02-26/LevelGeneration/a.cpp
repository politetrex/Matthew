#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	int test_num;
	cin >> test_num;
	for (int i = 0; i < test_num; i++) {
		int nodes;
		cin >> nodes;

		ll low = nodes - 1;
		ll high = 2ll * (nodes - 1);
		while (low < high) {
			ll mid = (low + high + 1) / 2;
			int num_bridges = (mid + 1) / 2;
			int cycle_nodes = nodes - num_bridges;
			ll cycle_edges = 1ll * cycle_nodes * (cycle_nodes - 1) / 2;

			if (mid - num_bridges <= cycle_edges) {
				low = mid;
			} else {
				high = mid - 1;
			}
		}

		cout << low << '\n';
	}
}