// Codeforces and Polygon may be unavailable from February 22, 6:30 (UTC) to February 22, 20:30 (UTC) due to technical maintenance.

#include <iostream>
using namespace std;

int main() {
    int n, t, k;
    cin >> n >> t >> k;

    // since 1≤𝑛≤2⋅10^5 and no more than 20 queries
    int l = 1, r = n, ans = -1;
    while (l <= r) {
        int mid = (l+r)/2;
        cout << "? 1 " << mid << endl;
        int sum; cin >> sum;
        if (sum==-1) return 0; // for errs
        if (mid - sum >= k) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << "! " << ans << endl; return 0;
}