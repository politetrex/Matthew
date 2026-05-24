#include <bits/stdc++.h>
using namespace std;
#define int long long
#define arr array
#define pii pair<int, int>
#define fir first 
#define sec second
#define vec vector
const int N = 1e5 + 5, B = 1e5 + 5;

int n, b;
arr<pii, N> snw; // {snow, index} 
arr<vec<int>, B> bt; // {endurance, jump, index}

set<int> lcs;
multiset<int> gps;

void upd(int id) {
    lcs.insert(id);
    auto it = lcs.find(id);

    bool is_bf = (it != lcs.begin());
    bool is_af = (it != prev(lcs.end()));

    if (is_bf && is_af) {
        int gp = *next(it, 1) - *next(it, -1);
        gps.erase(gps.find(gp));
    }
    if (is_bf) {
        int gp = id - *next(it, -1);
        gps.insert(gp);
    }
    if (is_af) {
        int gp = *next(it, 1) - id;
        gps.insert(gp);
    }
}

arr<bool, B> ans;

signed main() {
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);

    cin >> n >> b;
    for (int i = 1; i <= n; i++) {
        cin >> snw[i].fir;
        snw[i].sec = i;
    }
    for (int i = 1; i <= b; i++) {
        int end, jmp; cin >> end >> jmp;
        bt[i] = {end, jmp, i};
    }
    sort(snw.begin() + 1, snw.begin() + n + 1);
    sort(bt.begin() + 1, bt.begin() + b + 1);

    int snw_ptr = 1;
    for (int bt_ptr = 1; bt_ptr <= b; bt_ptr++) {
        while (snw_ptr <= n && snw[snw_ptr].fir <= bt[bt_ptr][0]) {
            upd(snw[snw_ptr].sec);
            snw_ptr++;
        }
        
        int mx_gp = *gps.rbegin();
        ans[bt[bt_ptr][2]] = (bt[bt_ptr][1] >= mx_gp);
    }

    for (int i = 1; i <= b; i++)
        cout << ans[i] << '\n';
}
