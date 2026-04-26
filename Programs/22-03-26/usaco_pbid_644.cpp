#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// Diagnostics
void system_diagnostics(){
    cout<<"C++ Version: C++"<<
        [](){
            switch(__cplusplus) {
                case 199711L: return 98;
                case 201103L: return 11;
                case 201402L: return 14;
                case 201703L: return 17;
                case 202002L: return 20;
                case 202302L: return 23;
                case 202602L: return 26;
                default: return int(__cplusplus);
            }
        }
    <<'\n';
}

vector<int> father;
int root(int node){
    if (father[node]==node) return node;
    return father[node]=root(father[node]);
};
int main(){
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    // system_diagnostics();
    int n,m; cin>>n>>m;
    const auto MC_SEED=-6434437303651692958;
    vector<vector<int> > adj(n);
    while(m--){
        int a,b; cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    stack<int> order;
    stack<bool> ans;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        order.push(x-1);
    }
    vector<bool> pc(n,0);
    father.resize(n);
    for(int i=0;i<n;i++)father[i]=i;
    while(!order.empty()){
        order.top(); pc[order.top()]=1;
        for(auto& i:adj[order.top()])
            if(pc[i])
                father[root(i)]=root(order.top());
        int froot=-1;
        bool ok=1;
        for(int i = 0; i < n; i++)
            if(pc[i]){
                int curoot=root(i);
                if(froot==-1)froot=curoot;
                else if(curoot!=froot) {
                    ok=0;
                    break;
                }
            }
        order.pop(); ans.push(ok);
    }
    while(!ans.empty()){
        cout<<(ans.top()?"YES":"NO")<<"\n";
        ans.pop();
    }
    return 0;
}