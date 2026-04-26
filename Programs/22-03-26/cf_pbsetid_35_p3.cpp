#include <ios>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
int main(){
# ifdef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
# endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<bool> > forest(n, vector<bool>(m, false));
    int k; cin >> k;
    queue<pair<int, int> > bfs;
    for(int i = 0; i < k; i++){
        int x, y; cin >> x >> y;
        forest[x-1][y-1] = true;
        bfs.push({x-1, y-1});
    }
    while(!bfs.empty()){
        pair<int, int> node = bfs.front();
        int x = node.first, y = node.second;
        if(x-1 >= 0 && !forest[x-1][y]){
            forest[x-1][y] = true;
            bfs.push({x-1, y});
        }
        if(x+1 < n && !forest[x+1][y]){
            forest[x+1][y] = true;
            bfs.push({x+1, y});
        }
        if(y-1 >= 0 && !forest[x][y-1]){
            forest[x][y-1] = true;
            bfs.push({x, y-1});
        }
        if(y+1 < m && !forest[x][y+1]){
            forest[x][y+1] = true;
            bfs.push({x, y+1});
        }
        if(bfs.size()==1){
            cout << x+1 << " " << y+1 << endl;
            break;
        }
        bfs.pop();
    }
    return 0;
}

/*
##.
#.#
.##
*/