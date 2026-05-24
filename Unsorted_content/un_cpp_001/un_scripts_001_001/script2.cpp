#include <iostream>
#include <vector>
using namespace std;
const bool debug=0;
int main(){
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    int n; cin>>n;
    vector<long long> pfx(n+1,0), hei(n), mod(n+1);
    for(int i=0;i<n;i++){
        cin>>hei[i];
        pfx[i+1]=pfx[i]+hei[i];
        if (debug) cout<<"pfx "<<pfx[i+1]<<'\n';
    }
    for(int i=0;i<=n;i++){
        mod[i]=pfx[i]%7;
        if (debug) cout<<"mod: "<<mod[i]<<'\n';
    }
    long long lcont[]={0, 0, 0, 0, 0, 0, 0 },
              lprev[]={-1,-1,-1,-1,-1,-1,-1};
    for(int i=0;i<=n;i++){
        int m=mod[i];
        if(lprev[m]==-1)
            lprev[m]=i;
        else
            lcont[m]=i-lprev[m];
    }
    long long mx=0;
    for(int i=0;i<7;i++){
        if (debug) cout<<"lcont/lprev: "<<lcont[i]<<'/'<<lprev[i]<<'\n';
        mx=(mx>lcont[i]?mx:lcont[i]);
    }
    cout<<mx<<endl;
    return 0;
}