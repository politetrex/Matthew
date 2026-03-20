// Judge:
#include <vector>
#include <iostream>

// Leetcoder:
class Solution{
public:
    bool LeftmostBelow(int n, std::vector<int> a){
        int lim=-1;
        for(auto& i:a){
            if (lim==-1){
                lim=i;
            } else if (lim*2<=i){
                return 0;
            } else {
                lim=(lim<i?lim:i);
            }
        }
        return 1;
    }
};

// Judge (continued):
int main(){
    int t; std::cin>>t;
    while(t--){
        Solution solution;
        int n; std::cin>>n;
        std::vector<int> a(n);
        for(auto& i:a) std::cin>>i;
        bool result=solution.LeftmostBelow(n, a);
        std::cout<<(result?"YES":"NO")<<'\n';
    }
    return 0;
}