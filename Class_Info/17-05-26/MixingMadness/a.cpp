#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int MAX_N = 2e5 + 5, MAX_K= 10 + 5;
 
int n;
int arr[MAX_N];
int k;
int tar[MAX_N];
 
set<pii> trans[MAX_K];
int shift;
bool dp[MAX_N];
int backtrack[MAX_N];
void init() {
    dp[0] = true;
    for (int i = 1; i <= k; i++)
        trans[i].insert({0, 0});
}
 
vector<pii> ans;
 
int main() {
    // freopen("mixing.in", "r", stdin);
 
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    cin >> k;
    for (int i = 1; i <= k; i++) 
        cin >> tar[i];
    
    init();
    for (int i = 1; i <= n; i++) {
        shift += arr[i];
 
        for (int j = 1; j <= k; j++) {
            int tar2 = tar[j] * i - shift;
            
            if (trans[j].lower_bound({tar2, -1}) == trans[j].end() || trans[j].lower_bound({tar2, -1})->first != tar2) continue;
            dp[i] = true;
            backtrack[i] = trans[j].lower_bound({tar2, -1})->second;
            break;
        }
 
        if (!dp[i]) continue;
        for (int j = 1; j <= k; j++)
            trans[j].insert({tar[j] * i - shift, i});
    }
 
    if (!dp[n]) {
        cout << "IMPOSSIBLE" << '\n';
        exit(0);
    }
 
    int i = n;
    while (i != 0) {
        assert(backtrack[i] + 1 <= i);
        ans.push_back({backtrack[i] + 1, i});
        i = backtrack[i];
    }
    sort(ans.begin(), ans.end());
 
    cout << "POSSIBLE" << '\n';
    cout << ans.size() << '\n';
    for (pii a : ans)  
        cout << a.first << " " << a.second << '\n';    
}