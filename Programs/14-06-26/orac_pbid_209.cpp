#include <iostream>
#include <algorithm>
using namespace std;
long long solve(long long ro, long long bo, long long s, long long rp, long long bp){
    long long rd=max(0ll,rp-ro), bd=max(0ll,bp-bo);
    long long vrd=max(0ll,bo-bp), vbd=max(0ll,ro-rp);
    if(rd+bd>s) return 0;
    long long res=s-rd-bd;
    return min({max(0LL, ro+bo+s-rp-bp+1), max(0LL, ro+s-rp+1), max(0LL, bo+s-bp+1)});
}
int main(){
    long long ro,bo,s,rp,bp;
    cin>>ro>>bo>>s>>rp>>bp;
    cout<<solve(ro,bo,s,rp,bp);
    return 0;
}