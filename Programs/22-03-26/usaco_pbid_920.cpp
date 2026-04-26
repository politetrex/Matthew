// usaco_pbid_920.cpp

#include <iostream>
#include <vector>
using namespace std;
vector<short> father;
int root(int node){
    if (father[node]==node) return node;
    return father[node]=root(father[node]);
};
int main(){
    short n,m; cin>>n>>m;
    vector<pair<int,int> > diffs;
    vector<tuple<bool,short,short> > cows(m);
    father.resize(n);
    for(int i=0;i<n;i++)father[i]=i;
    for(auto [a,b,c]:cows){
        char d; cin>>d; a=d=='S';
        cin>>b>>c;
        if(a)father[root(b-1)]=root(c-1);
        else diffs.push_back({})
    }
    
    return 0;
}




