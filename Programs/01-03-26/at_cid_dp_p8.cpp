#include <iostream>
using namespace std;
const int MOD=1000000007,
          MAXN=1005;
int grid[MAXN][MAXN];
int H, W;
int main(){
    cin>>H>>W;
    for(int i=1; i<=H; i++){
        for(int j=1; j<=W; j++){
            char c; cin>>c;
            grid[i][j]=c=='.';
        }
    }
    for(int i=1; i<=H; i++){
        for(int j=1; j<=W; j++){
            if (i==1 && j==1){
                grid[1][1]=1;
                continue;
            }
            if (grid[i][j]==0){
                continue;
            }
            grid[i][j]=grid[i-1][j]+grid[i][j-1];
        }
    }
    cout<<grid[H][W]; return 0;
}