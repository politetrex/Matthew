#include <iostream>
#include <vector>
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    long long n,m; cin>>n>>m;
    vector<long long> x(n);
    for(auto& i:x)cin>>i;
    vector<long long> x_cpy=x, mballs(n, 0), delta(n,0);
    vector<pair<long long,long long>> op(m);
    long long op_cnt=0;
    while(m--){
        long long a,b; cin>>a>>b; op[op_cnt++]={a,b};
        mballs[a-1] = max(mballs[a-1], ++delta[a-1]);
        mballs[b-1] = max(mballs[b-1], --delta[b-1]);
        x_cpy[a-1]--; x_cpy[b-1]++;
        if(x_cpy[a-1]<0||x_cpy[b-1]<0){
            cout<<op_cnt; // I crashed
            return 0;
        }
    }
    vector<long long> diff(n); bool inf=1;
    for(long long i=0;i<n;i++){
        diff[i]=x[i]-x_cpy[i];
        if(diff[i]>0) inf=0;
    }
    if(inf) cout<<"FOREVER";
    else {
        long long min_runtime=0x7fffffffffffffffLL;
        for(long long i=0;i<n;i++){
            if(diff[i]>0) if(diff[i]>0) min_runtime=min(min_runtime, (x[i] - mballs[i]) / diff[i]);
        }
        if(min_runtime==0){
            x_cpy=x;
            for(long long i=0;i<n;i++){
                x_cpy[i]-=diff[i]*min_runtime;
            }
        }
        for (long long cycle=min_runtime; ; cycle++) {
            for(m = 0; m < op_cnt; m++){
                long long a=op[m].first, b=op[m].second;
                x_cpy[a-1]--; x_cpy[b-1]++;
                if(x_cpy[a-1]<0||x_cpy[b-1]<0){
                    cout << m+op_cnt*cycle; // TODO: hello
                    return 0; // BUG: hello
                }
            }
        }
        return 7; // Use an RE to flag the problem
    }
    return 0;
}

// FACT! log2(9223372036535118092) log2(9223372036535118091)