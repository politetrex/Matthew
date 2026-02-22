#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    if (1){ // for files, since ONLINE_JUDGE is not defined
        freopen("convention.in", "r", stdin);
        freopen("convention.out","w",stdout);
    }
    int n, m, c;
    cin>>n>>m>>c;
    vector<int> bs(n);
    for(auto& i:bs) cin>>i;
    sort(bs.begin(),bs.end());
    
    // binsearch
    int l = 0;
    int r = bs[n-1] - bs[0];
    int ans = r;
    
    while (l <= r) {
        int mid = (l+r)/2;

        // check() taken out
        int bususe = 1;
        int fcib = bs[0];
        int cib = 1;
        for (int i=1; i < n;i++)
            if (cib >= c || bs[i] - fcib > mid) {
                bususe++;
                fcib = bs[i];
                cib = 1;
            } else cib++;

        if (bususe <= m){ // check() return value
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout<<ans;
    return 0;
}