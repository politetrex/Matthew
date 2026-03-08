#include <iostream>
#include <bitset>
using namespace std;
constexpr int maxsum=100*1000;
int main(){
    int n; cin>>n;
    bitset<maxsum+1> DP; DP[0]=1;
    while(n--){
        int x; cin>>x;
        DP = DP | (DP << x);
    }
    cout<<DP.count()-1<<'\n';
    for(int s=1; s<=maxsum; s++)
        if (DP[s]) cout<<s<<' ';
    return 0;
}