#include <iostream>
using namespace std;
int main(){
    int n; cin>>n;
    int minx=0x3fffffff,maxx=0,miny=0x3fffffff,maxy=0;
    while(n--){
        int x, y; cin>>x>>y;
        minx=min(minx,x);
        maxx=max(maxx,x);
        miny=min(miny,y);
        maxy=max(maxy,y);
    }
    int area=(maxx-minx)*(maxy-miny);
    cout<<area;
    return 0;
}