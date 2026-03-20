#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void solve(){
    int n, k; cin>>n>>k;
    vector<int> a(n), b(k);
    for(auto& i:a)cin>>i;
    for(auto& j:b)cin>>j;
    sort(a.rbegin(), a.rend());
    sort(b.begin(), b.end());
    int x=0;
    long long cost=0;
    for(int i=0; i<k; i++){
        // cout<<'|';
        for(int j=0; j<b[i]; j++){
            if (x>=n){
                cout<<cost<<'\n';
                return;
            }
            // cout<<a[x]<<' ';
            if (j<b[i]-1) cost+=a[x];
            x++;
        }
        // cout<<x<<'|';
    }
    for(; x<n; x++) cost+=a[x];
    cout<<cost<<'\n';
}

int main(){
    int T; cin>>T;
    while(T--) solve();
}