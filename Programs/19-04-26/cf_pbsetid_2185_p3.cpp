#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void solve(){
    int n; cin>>n;
    vector<int> a(n);
    for(auto& i:a)cin>>i;
    sort(a.begin(),a.end());
    int run=0,fnum=0x80000000,maxrun=-1;
    for(auto& i:a){
        if(fnum==0x80000000){
            fnum=i;
            run=1;
        } else {
            if(i==fnum+run) run++;
            else if (i>fnum+run) {
                fnum=i;
                maxrun=max(run,maxrun);
                run=1;
            }
        }
        // cout<<"i="<<i<<",run="<<run<<",fnum="<<fnum<<",maxrun="<<maxrun<<";\n";
    }
    maxrun=max(run,maxrun);
    cout<<maxrun<<'\n'; return;
}
int main(){
    int T; cin>>T;
    while(T--)
        solve();
    return 0;
}