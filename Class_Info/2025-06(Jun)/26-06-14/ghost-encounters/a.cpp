/*
Subtask 1: 
Say all ghosts appear at time T. Note that since we can only be in one location at time T, we should optimally
be where there are most ghosts. So find the x[i] with most appearances.

Full:
For a certain ghost, we have to leave at exactly t[i] - x[i] * k to see it. Since we can only leave at a certain
time, pick the leaving time with most ghosts corresponding to it.
*/

#include <bits/stdc++.h>
using namespace std;
 
int n, k;
map<int, int> encs;
 
int main() {
    freopen("ghostin.txt", "r", stdin);
    freopen("ghostout.txt", "w", stdout);
 
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int x, t; cin >> x >> t;
        int time = t - x * k;
        encs[time]++;
    }
 
    int ans = 0;
    for (auto& e : encs) {
        ans = max(ans, e.second);
    }
    cout << ans << '\n';
}