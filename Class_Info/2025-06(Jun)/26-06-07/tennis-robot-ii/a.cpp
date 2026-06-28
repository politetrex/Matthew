#include <bits/stdc++.h>
using namespace std;
#define int long long
using pii = pair<int, int>;
const int MAX_N = 2e5 + 5, MAX_M = 2e5 + 5, INF = 1e18;
 
int n, m;
array<int, MAX_N> siz;
array<pii, MAX_M> mov;
 
array<vector<pii>, MAX_N> deltas; // {delta, move}
array<int, MAX_N> fin_delta, min_delta;
void precomp() {
    for (int i = 1; i <= m; i++) {
        int x = mov[i].first, y = mov[i].second;
 
        pii delta1 = {(deltas[x].empty()) ? -1 : deltas[x].back().first - 1, i};
        deltas[x].push_back(delta1);
 
        pii delta2 = {(deltas[y].empty()) ? 1 : deltas[y].back().first + 1, i};
        deltas[y].push_back(delta2);
    }
 
    for (int i = 1; i <= n; i++) {
        fin_delta[i] = (deltas[i].empty()) ? 0 : deltas[i].back().first;
        min_delta[i] = INF;
        for (pii delta : deltas[i]) min_delta[i] = min(min_delta[i], delta.first);
        if (deltas[i].empty()) min_delta[i] = 0;
        // cout << i << ": " << fin_delta[i] << " " << min_delta[i] << endl;
    }
}
 
int bin_search(int i) {
    int lo = 0, hi = 1e6; // sus
    while (lo != hi) {
        int mid = (lo + hi) / 2;
        if (siz[i] + mid * fin_delta[i] + min_delta[i] < 0) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}
 
int comp() {
    int ans = INF;
    for (int i = 1; i <= n; i++) {
        if (fin_delta[i] >= 0) {
            if (siz[i] + min_delta[i] >= 0) continue;
            for (pii delta : deltas[i]) {
                if (siz[i] + delta.first < 0) {
                    ans = min(ans, delta.second - 1);
                    break;
                }
            }   
            continue;
        }
 
        int n_loops = bin_search(i);
        // cout << i << ": " << n_loops << endl;
        for (pii delta : deltas[i]) {
            if (siz[i] + fin_delta[i] * n_loops + delta.first < 0) {
                ans = min(ans, m * n_loops + delta.second - 1);
                break;
            }
        }   
    }
    return ans;
}
 
signed main() {
    freopen("tennisin.txt", "r", stdin), freopen("tennisout.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> siz[i];
    for (int i = 1; i <= m; i++) cin >> mov[i].first >> mov[i].second;
 
    precomp();
    int ans = comp();
    if (ans >= INF) cout << "FOREVER" << '\n';
    else cout << ans << '\n';
}
