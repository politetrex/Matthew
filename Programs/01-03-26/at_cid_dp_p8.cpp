#include <iostream>
using namespace std;
const int MOD=1000000007,
          MAXN=1005;
int grid[2][MAXN];
int H, W; bool transit;
int main(){
    cin>>H>>W;
    for(int i=1; i<=H; i++){
        for(int j=1; j<=W; j++){
            char c; cin>>c;
            if (i==1 && j==1){
                grid[transit][1]=1;
                continue;
            }
            if (c=='#'){
                grid[transit][j]=0;
                continue;
            }
            grid[transit][j]=(grid[!transit][j]+grid[transit][j-1])%MOD;
        }
        transit=!transit;
    }
    cout<<grid[!transit][W]; return 0;
}