#include <bits/stdc++.h>
using namespace std;
#define int long long
#define arr array
#define vec vector
const int N = 1e5 + 5, INF = 1e10;

int n, m;
arr<vec<int>, N> adj;

/*
push > 3 2 1 < take from
*/

arr<bool, N> vs;
arr<int, N> dst;
queue<int> ord;
void bfs() {
    dst.fill(INF);

    dst[1] = 0;
    ord.push(1);
    while (ord.size()) {
        int u = ord.back();
        ord.pop();

        if (vs[u]) continue;
        vs[u] = true;

        for (int v : adj[u]) {
            int nw_dst = dst[u] + 1;
            if (nw_dst >= dst[v]) continue;
            dst[v] = nw_dst;
            ord.push(v);
        }
    }
}

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v), adj[v].push_back(u);
    }

    bfs();

    if (!vs[n]) {
        cout << "IMPOSSIBLE" << '\n';
    } else {
        cout << dst[n] + 1 << '\n';
        // Print nodes on path
    }
}