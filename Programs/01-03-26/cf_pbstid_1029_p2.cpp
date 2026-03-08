/********************************************************************/
/**/#include <iostream>/**** Brickode for cf_pbstid_1029_p2 *********/
/**/#include <vector>/******* Solution tags: [Two Pointers] *********/
/**/using namespace std;int main(){int n;cin>>n;vector<int> a(n/*****/
/**/);vector<bool> ok(n,0);cin>>a[0];for(int i=1;i<n;i++){cin>>/*****/
/**/a[i];ok[i]=a[i-1]*2<=a[i];}int curr=1,best=1;for(int i=1;i</*****/
/**/n;i++){if(a[i]<=2*a[i-1]){curr++;best=max(best,curr);}else{/*****/
/**/curr=1;}}cout<<best;return 0;}/* ©2026 Brickode™ Code Formatter */
/********************************************************************/