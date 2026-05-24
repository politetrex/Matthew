/*
note that b1 must be at l and b3 at r, else range could be contracted
this simplifies problem to maximising (a[l] + l) + (a[r] - r) + a[i] where i is between l and r
we can maximise values for l and r separately and try for all a[i]
 
let max_l[i] and max_r[i] represent these values
calculate using running max
for i [2, n - 1]
    ans for i is a[i] + max_l[i - 1] + max_r[i + 1]
*/
 
#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 5, INF = 1e9;
 
int t;
int n;
int arr[MAX_N];
int max_l[MAX_N], max_r[MAX_N];
 
int main() {
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
 
        max_l[0] = -INF;
        for (int i = 1; i <= n; i++) {
            max_l[i] = max(max_l[i - 1], arr[i] + i);
        }
        max_r[n + 1] = -INF;
        for (int i = n; i >= 1; i--) {
            max_r[i] = max(max_r[i + 1], arr[i] - i);
        } 
 
        int ans = -INF;
        for (int i = 2; i <= n - 1; i++) {
            ans = max(ans, arr[i] + max_l[i - 1] + max_r[i + 1]);
        }
 
        cout << ans << '\n';
    }
}