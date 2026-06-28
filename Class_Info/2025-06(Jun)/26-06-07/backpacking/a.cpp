#include <bits/stdc++.h>
using namespace std;
#define int long long
#define arr array 
#define vec vector
#define pii pair<int, int>
#define fir first 
#define sec second
const int N = 2e5 + 5;
 
int n, k;
arr<int, N> dst, cst;
 
arr<int, N> dst_sm;
int dst_qry(int l, int r) {
    assert(l <= r);
    return dst_sm[r] - dst_sm[l];
}
void dst_sm_cmp() {
    for (int i = 1; i <= n; i++) 
        dst_sm[i] = dst_sm[i - 1] + dst[i];
}
 
vec<int> nx_stc;
arr<int, N> nx;
void nx_cmp() {
    cst[n] = 0;
    nx_stc.push_back(n);
    for (int i = n - 1; i >= 1; i--) {
        while (cst[nx_stc.back()] >= cst[i]) 
            nx_stc.pop_back();
        nx[i] = nx_stc.back();
        nx_stc.push_back(i);
    }
    // for (int i = 1; i <= n; i++) cout << i << ": " << nx[i] << endl;
}
 
void ans_cmp() {
    int cp = 0, ans = 0;
    for (int i = 1; i < n; i++) {
        int am = 0;
        if (dst_qry(i, nx[i]) <= k) {
            am = max(dst_qry(i, nx[i]) - cp, 0ll);
        } else {
            am = k - cp;
        }
        ans += am * cst[i], cp += am - dst[i + 1];
    }
    cout << ans << '\n';
}
 
signed main() {
    // freopen("in", "r", stdin);
    cin >> n >> k;
    for (int i = 2; i <= n; i++) cin >> dst[i];
    for (int i = 1; i <= n; i++) cin >> cst[i];
    dst_sm_cmp();
    nx_cmp();
    ans_cmp();
}