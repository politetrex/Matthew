/*
Input:
5
1 1 2 3
*/

#include <bits/stdc++.h>
using namespace std;
#define arr array
#define vec vector 
const int N = 2e5 + 5;

int n;
// For every node, the LIST of its neighbours
// adj[1], adj[2], ... adj[n] have at least 1 element
arr<vec<int>, N> adj;

arr<int, N> sz; // Size of the subtree rooted at u
void dfs(int u = 1, int pr = 0) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v == pr) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

int main() {
    cin >> n;
    for (int u = 2; u <= n; u++) {
        int pr; cin >> pr;
        adj[u].push_back(pr);
        adj[pr].push_back(u);
    }

    dfs();

    for (int u = 1; u <= n; u++)
        cout << (sz[u] - 1) << " ";
    cout << '\n';
}




