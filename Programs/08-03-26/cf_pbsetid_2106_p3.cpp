#include <iostream>
#include <vector>
using namespace std;
void solve(){
    int n,k; cin>>n>>k;
    vector<int> a(n), b(n);
    int maxa=0, mina=0x7fffffff;
    for(int& i:a){
        cin>>i;
        maxa=max(maxa, i);
        mina=min(mina, i);
    }
    bool allneg=1;
    for(int& i:b){
        cin>>i;
        if (i>-1) allneg=0;
    }
    // cout<<"maxa "<<maxa<<'\n';
    if (allneg){
        cout<<k-maxa+mina+1<<'\n';
    } else {
        vector<int> templ(n);
        for(int i=0; i<n; i++){
            templ[i]=maxa-a[i];
            if (templ[i]>b[i] && b[i]>-1){
                cout<<"0\n";
                return;
            } // -258 51 167
            // -157 63 236
        }
        int _i=0;
        while(b[_i]==-1) _i++;
        int cha=b[_i]-templ[_i],
            sum=a[_i]+b[_i];
        for(int i=0; i<n; i++){
            if (b[i]>-1){
                if (b[i]-templ[i]!=cha){
                    cout<<"0\n";
                    return;
                }
            } else {
                if (sum-a[i]>k){
                    cout<<"0\n";
                    return;
                }
            }
        }
        cout<<"1\n";
    }
}

int main(){
    int T; cin>>T;
    while(T--) solve();
    return 0;
}

/*

5 10
1 3 2 5 4
-1 -1 -1 -1 -1

*/