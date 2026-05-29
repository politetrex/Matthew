/*
Input:
9
2 3 3 4
4 1 5 2
6 3 7 2
0 0 0 0
0 0 0 0
8 1 9 1
0 0 0 0
0 0 0 0
0 0 0 0
*/

#include <bits/stdc++.h>
using namespace std;
#define arr array
#define vec vector
#define pii pair<int, int>
#define fir first 
#define sec second
const int N = 5e4 + 5;

int n;
arr<vec<pii>, N> chld;

int ans;
// Return longest length from u to a leaf node
int dfs(int u = 1) {
    // If I'm a leaf node
    if (chld[u].empty())
        return 0;

    int dst1 = dfs(chld[u][0].fir) + chld[u][0].sec;
    int dst2 = dfs(chld[u][1].fir) + chld[u][1].sec; 
    ans += abs(dst1 - dst2);
    
    return max(dst1, dst2);
}

int main() {
    cin >> n;
    for (int u = 1; u <= n; u++) {
        int v1, d1, v2, d2; cin >> v1 >> d1 >> v2 >> d2;
        if (v1 == 0) continue;
        chld[u].push_back({v1, d1});
        chld[u].push_back({v2, d2});
    }

    dfs();
    cout << ans << '\n';
}
