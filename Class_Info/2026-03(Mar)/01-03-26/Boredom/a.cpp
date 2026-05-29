#include <bits/stdc++.h>
using namespace std;
#define arr array
const int N = 1e5;
const int INF = 1e9;

arr<int, N + 5> frq;
arr<int, N + 5> dp;

int main() {
    int x; cin >> x;
    for (int i = 1; i <= x; i++) {
        int y; cin >> y;
        frq[y]++;
    }

    dp[0] = 0, dp[1] = frq[1];
    for (int i = 2; i <= N; i++) {
        int lv = dp[i - 1];
        int tk = dp[i - 2] + frq[i] * i;
        dp[i] = max(tk, lv);
    }
    cout << dp[N] << '\n';
}