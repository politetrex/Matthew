#include <climits>
#include <iostream>
#include <vector>

using std::vector;

int main() {
	int n;
	long long t;
	std::cin >> n >> t;
	vector<int> k(n);

	int mn = INT_MAX;
	for (int &x : k) {
		std::cin >> x;
		mn = std::min(mn, x);
	}

	long long lo = 0;
	long long hi = mn * t;
	long long res = 0;
	while (lo <= hi) {
		long long mid = (lo + hi) / 2;
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			sum += (mid / k[i]);
			if (sum >= t) { break; }
		}

		if (sum >= t) {
			res = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}

	std::cout << res << std::endl;
}