#include <iostream>
#include <vector>
#include <deque>
#include <set>
using namespace std;
int main(){
    int n; cin>>n;
    vector<int>a(n);
    for(auto&i:a)cin>>i;
    vector<int>a2=a; 
    set<int>dis(a.begin(),a.end());
    a2.insert(a2.end(),a.begin(),a.end());
    int k=dis.size();
    if (k==1) for(int i=0; i<n; i++) cout<<"0 ";
    else {
        vector<int>far(2*n, 2*n), fk(1e6+5,0);
        int l=0,cnt=0;
        for(int r=0; r<2*n; r++){
            fk[a2[r]]++;
            if(fk[a2[r]] == 1) cnt++;
            while(cnt == k){
                far[l] = r;
                fk[a2[l]]--;
                if(fk[a2[l]] == 0) cnt--;
                l++;
            }
        }
        
        vector<int> ans(n);
        for(int j=0;j<n;j++){
            int l=0,h=n-1,best=h;
            while(l<=h){ // bsearch (or binarys (or bs (or binarysearch))) ;)
                int mid=(l+h)/2,mac=0x7fffffff;
                for(int p=j;p<=j+mid&&p<2*n;p++)mac=min(mac,far[p]-p);
                if(mac<=mid){best=mid;h=mid-1;}else l=mid+1;
            }ans[j]=best;
        }
        for(auto&i:ans)cout<<i<<' ';
    }
    return 0;
}