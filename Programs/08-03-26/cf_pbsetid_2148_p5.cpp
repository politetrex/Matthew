#include <iostream>
#include <vector>
// #include <map>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin>>n>>k;
        vector<int> a(n);
        vector<int> total_count(n+1,0);
        for (int i=0;i<n; i++) {
            cin>>a[i];
            total_count[a[i]]++;
        }
        bool ok=true;
        vector<int> limit(n+1,0);
        for (int v = 1; v <= n; v++) {
            if (total_count[v] % k!=0) {
                ok=false;
                break;
            }
            limit[v]=total_count[v]/k;
        }
        if (!ok) {
            cout<<0;
        } else {
            vector<int> occ(n+1,0);
            long long ans=0;
            int l=0;
            // Man Logic
            for (int r=0; r<n; r++) {
                occ[a[r]]++;
                while (l <= r&&occ[a[r]]>limit[a[r]]) { // ocelot lorem ipsum dolor sit amet code went fly when there is occ[a[r]]>occ[a[r]]
                    occ[a[l]]--;
                    l++;
                }
                ans+=r-l+1;
            }
            cout<<ans;
        } cout<<'\n';
    } return 0;
}