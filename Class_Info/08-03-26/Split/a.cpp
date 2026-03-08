#include <bits/stdc++.h>
using namespace std;
#define arr array
#define pii pair<int, int>
#define fir first 
#define sec second
const int N = 2e5 + 5;

int n, k;
arr<int, N> a;

void slv(int tst) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    map<int, int> frq;
    for (int i = 1; i <= n; i++)
        frq[a[i]]++;
    for (pii x : frq) {
        if (x.sec % k == 0) 
            frq[x.fir] /= k;
        else {
            cout << 0 << '\n';
            return;
        }        
    }

    int r = 0, ans = 0;
    map<int, int> cnt;
    for (int l = 1; l <= n; l++) {
        while (r < n && cnt[a[r + 1]] + 1 <= frq[a[r + 1]]) {
            r++;
            cnt[a[r]]++;
        }
        ans += (r - l + 1);
        cnt[a[l]]--;
    }  
    cout << ans << '\n';
}

int main() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++)
        slv(i);
}