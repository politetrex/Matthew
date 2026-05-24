#include <bits/stdc++.h>
using namespace std;
#define int long long
#define arr array 
const int N = 2e5 + 5;
 
int n, k, d;
arr<int, N> a;
 
void cmp() {
    set<int> unq;
    for (int i = 1; i <= n; i++) {
        unq.insert(a[i]);
        if (i + k > n) continue;
        if (!unq.count(a[i + k] - d) && !unq.count(a[i + k] + d)) continue;
        cout << "YES" << '\n';
        return;
    }
    cout << "NO" << '\n';
}
 
signed main() {
    cin >> n >> k >> d;
    for (int i = 1; i <= n; i++) cin >> a[i];
 
    cmp();
}