#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, k, tot=0; cin>>n>>k;
    vector<vector<int>> mfreq(3,vector<int>(k+1,0));
    for(int i=0;i<n;i++){
        int x; cin>>x;
        mfreq[i%3][x]++;
    }
    for(int i=0;i<3;i++){
        int maxn=-1;
        for(int j=1;j<=k;j++){
            maxn=max(maxn,mfreq[i][j]);
        }
        tot+=maxn;
    }
    cout<<n-tot; return 0;
}