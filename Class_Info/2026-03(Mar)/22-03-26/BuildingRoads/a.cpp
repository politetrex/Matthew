/*
4 2
1 2
3 4
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define arr array
#define vec vector 
const int N = 1e5 + 5;

int n, m;
arr<vec<int>, N> adj; // List of neighbours of every single node

vec<int> frst;
arr<bool, N> vs;
void dfs(int u) {
    vs[u] = true;
    for (int v : adj[u]) {
        if (vs[v]) continue;
        dfs(v);
    }
}

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v), adj[v].push_back(u);
    }

    int nm_cmps = 0;
    for (int u = 1; u <= n; u++) {
        if (vs[u]) continue;
        nm_cmps++; 
        frst.push_back(u);
        dfs(u);
    }

    int ans = nm_cmps - 1;
    cout << ans << '\n';
    for (int i = 0; i < nm_cmps - 1; i++) 
        cout << frst[i] << " " << frst[i + 1] << '\n';
}