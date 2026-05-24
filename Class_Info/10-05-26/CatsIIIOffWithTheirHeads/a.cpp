#include <bits/stdc++.h>
using namespace std;
#define int long long
#define arr array 
#define pii pair<int, int>
#define fir first 
#define sec second
const int N = 1e5 + 5;
 
int n, k;
arr<arr<int, N>, 2> vl;
 
set<pii> ord;
void prcmp() {
    for (int i = 1; i <= n; i++) ord.insert({vl[1][i], i});
}
 
bool chck(int sz) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        pii tr = {sz - vl[0][i] - 1, 1000000000};
        auto it = ord.upper_bound(tr);
        if (it != ord.end())
            ans += n - it->sec + 1;
    }
    // cout << sz << ": " << ans << endl;
    return (ans >= k);    
}
 
int srch() {
    int lw = 2, hg = 2e6;
    // yes yes no no
    while (lw != hg) {
        // cout << lw << " " << hg << endl;
        int md = ceil((lw + hg) / (double) 2);
        if (chck(md)) lw = md;
        else hg = md - 1;
    }
    return lw;
}
 
signed main() {
    // freopen("a.in", "r", stdin);
    freopen("cats.in", "r", stdin), freopen("cats.out", "w", stdout);
    cin >> n >> k;
    for (int i : {0, 1}) 
        for (int j = 1; j <= n; j++)
            cin >> vl[i][j];
    sort(vl[0].begin() + 1, vl[0].begin() + n + 1);
    sort(vl[1].begin() + 1, vl[1].begin() + n + 1);
    
    prcmp();
    int ans = srch();
    cout << ans << endl;
}