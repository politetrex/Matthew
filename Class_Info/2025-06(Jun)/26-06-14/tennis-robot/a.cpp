/*
We can consider the placing of the balls as happening in 2 stages. In stage 1, balls are placed into bins row by
row and each bin gets either 1 ball each row, or is already full. In stage 2, the final row is placed and is 
unfinished, leading us to the last bin.

We can binary search the last height for which we can fill all bins up to (stage 1). Then, once we know how many
balls are left, we can simulate the final row in order to find which bin is used last.
*/

#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const int MAX_B = 100005;
const lint MAX_N = 1000000005;
 
int b; lint n; 
lint height[MAX_B];
 
lint check(lint h) {
    lint ans = 0;
    for (int i = 1; i <= b; i++) {
        ans += min(height[i], h);
    }
    return ans;
}
lint bsearch() {
    lint lo = 1, hi = n;
    while (lo != hi) {
        lint mid = (lo + hi) / 2; 
        if (check(mid) >= n) hi = mid;
        else lo = mid + 1; 
    }
    return lo;
}
 
int main() {
    cin >> b >> n;
    for (int i = 1; i <= b; i++) {
        cin >> height[i];
    }
 
    lint h = bsearch(); 
    lint balls = check(h - 1);
    for (int i = 1; i <= n; i++) {
        if (height[i] >= h) {
            balls++;
            if (balls == n) {
                cout << i << '\n';
                break;
            }
        }
    }
}