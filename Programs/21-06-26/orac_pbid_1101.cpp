#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,f; cin>>n>>f;
    vector<int> c(n); for(auto& i:c) cin>>i;
    vector<long long> minp(n);
    minp[0] = c[0];
    for (int i=1; i<n; i++)
        minp[i]=min(minp[i-1], (long long)c[i]);
    int ans=-1;
    for (int j=0; j<n; j++) {
        long long maxc=f-c[j];
        if (maxc<=0) continue;
        int lo=0, hi=j; // bSearch.
        while (lo<hi) {
            int mid=(lo+hi)/2;
            if (minp[mid]<=maxc)
                hi=mid;
            else lo=mid+1;
        }
        if (lo<j&&minp[lo]<=maxc)
            ans=max(ans, j-lo+1);
    }
    cout<<ans; return 0;
}