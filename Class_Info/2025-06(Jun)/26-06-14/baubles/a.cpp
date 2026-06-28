#include <bits/stdc++.h>
using namespace std;
 
int ro, bo, s, rp, bp;
 
int main() {
    freopen("baublesin.txt", "r", stdin);
    freopen("baublesout.txt", "w", stdout);
 
    cin >> ro >> bo >> s >> rp >> bp;
 
    int ans = 0;
    
    // Step 1: lower s to be < LHS or 0
    int lhs = max(rp - ro, 0) + max(bp - bo, 0);
    if (lhs > s) {
        cout << ans << '\n'; return 0;
    }
    if (lhs != 0) {
        ans += s - lhs + 1;
        cout << ans << '\n'; return 0;
    }
    ans += s;
 
    // Step 2: pick either red or blue to destroy
    if (rp == 0) {
        ans += bo - bp + 1;
    } else if (bp == 0) {
        ans += ro - rp + 1;
    } else {
        ans += min(bo - bp + 1, ro - rp + 1);
    }
 
    cout << ans << '\n'; 
}