#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > tree;
bool checkSpruce(int ind){
    int leafc=0;
    for(auto& i:tree[ind]){
        if (tree[i].empty()) leafc++;
        else if (!checkSpruce(i)) return 0;
    }
    return leafc>2;
}
int main(){
    int n; cin>>n; tree.resize(n);
    for(int i=1; i<n; i++){
        int x; cin>>x;
        tree[x-1].push_back(i);
    }
    cout<<(checkSpruce(0)?"Yes":"No");
    return 0;
}



































































// vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<
// vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<
// vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<
// vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<
// vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<
// vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<
// vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<
// vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<
// vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<
// int> > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > >
// > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > > 
// > > > > > > > > > > > > > > > > > > > > > > > > > nothing;                          