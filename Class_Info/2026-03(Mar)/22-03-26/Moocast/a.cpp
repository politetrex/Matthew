#include <bits/stdc++.h>
using namespace std;
#define int long long
#define arr array
#define vec vector
#define pii pair<int, int>
#define fir first 
#define sec second
const int N = 1e3 + 5, INF = 1e12;

int n;
arr<int, N> x, y;

// Squared distance
int dst(int i, int j) { 
    return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}
arr<vec<pii>, N> adj;

arr<bool, N> vs;
void dfs(int u, int mx_dst) {
    vs[u] = true;
    for (pii x : adj[u]) {
        if (x.sec > mx_dst) continue;
        if (vs[x.fir]) continue;
        dfs(x.fir, mx_dst);
    }
}

bool chck(int mx_dst) {
    vs.fill(false);
    dfs(1, mx_dst);
    return (count(vs.begin() + 1, vs.begin() + n + 1, false) == 0);
}
int bin_srch() {
    int lw = 0, hg = INF;
    while (lw < hg) {
        int md = (lw + hg) / 2;
        if (chck(md)) hg = md;
        else lw = md + 1;
    }
    return lw;
}

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];

    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            if (v == u) continue;
            adj[u].push_back({v, dst(u, v)});
        }
    }

    int ans = bin_srch();
    cout << ans << '\n';
}