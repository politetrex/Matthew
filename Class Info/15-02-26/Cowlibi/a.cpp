#include <bits/stdc++.h>
using namespace std;

struct Event {
	int t, x, y;

	bool operator<(const Event &other) const { return t < other.t; }
};

Event read() {
	int x, y, t;
	cin >> x >> y >> t;
	return {t, x, y};
}

bool reachable(const Event &a, const Event &b) {
	long long dx = a.x - b.x;
	long long dy = a.y - b.y;
	long long dt = a.t - b.t;
	return dx * dx + dy * dy <= dt * dt;
}

int main() {
	int g, n;
	cin >> g >> n;

	vector<Event> grazings(g);
	for (int i = 0; i < g; i++) { grazings[i] = read(); }

	sort(grazings.begin(), grazings.end());

	int ans = 0;
	for (int i = 0; i < n; i++) {
		Event alibi = read();
		int pos =
		    upper_bound(grazings.begin(), grazings.end(), alibi) - grazings.begin();

		bool innocent = false;
		for (int y = pos - 1; y <= pos; y++) {
			if (0 <= y && y < g) { innocent |= !reachable(grazings[y], alibi); }
		}

		ans += innocent;
	}

	cout << ans << endl;
}