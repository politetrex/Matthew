/*
Let the node on diameter with lowest depth be u. Let len[i] be the max length of a path starting at
i that goes down one of its children.
 
The answer then = 2 + len[v] + len[w] for two longest such lengths.
*/
 
#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2e5 + 5;
 
int n;
vector<int> adj[MAX_N];
 
int len[MAX_N];
vector<int> children[MAX_N];
void dfs1(int u, int par = -1) {
    for (auto& v : adj[u]) {
        if (v == par) continue;
        children[u].push_back(v);
        dfs1(v, u);
        len[u] = max(len[u], 1 + len[v]);
    }
}
 
int main() {
    //freopen("tree.in", "r", stdin);
 
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    dfs1(1);
 
    int ans = 0;
    for (int u = 1; u <= n; u++) {
        priority_queue<int> lens;
        for (auto& v : children[u]) {
            lens.push(len[v]);
        }
 
        int cur_ans = 0;
        int i = 1;
        while (lens.size() && i <= 2) {
            cur_ans += 1 + lens.top();
            lens.pop();
            i++;
        }
        ans = max(ans, cur_ans);
    }
 
    cout << ans << '\n';  
}