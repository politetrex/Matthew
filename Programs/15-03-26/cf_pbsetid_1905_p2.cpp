#include <iostream>
#include <vector>
using namespace std;
vector<int> deg;
int main(){
    int T; cin>>T;
    while(T--){
        deg.clear();
        int n; cin>>n; deg.resize(n);
        for(int i=1; i<n; i++){
            int u,v; cin>>u>>v;
            deg[u-1]++; deg[v-1]++;
        }
        int leafc=0;
        for(auto& i:deg)leafc+=i==1;
        cout<<(leafc+1)/2<<'\n';
    }
    return 0;
}