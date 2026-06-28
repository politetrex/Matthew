#include <bits/stdc++.h>
using namespace std;
 
int n, k;
deque<int> a;
 
int main() {
    freopen("shopin.txt", "r", stdin), freopen("shopout.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        a.push_back(x);
    }
 
    int ans = 0;
    for (int i = 1; i <= k; i++) {
        ans += min(a.front(), a.back());
        a.pop_front(), a.pop_back();
    }
 
    while (a.size()) {
        ans += max(a[a.size() - 2], a[a.size() - 1]);
        a.pop_back(), a.pop_back();
    }
    cout << ans << '\n';
}