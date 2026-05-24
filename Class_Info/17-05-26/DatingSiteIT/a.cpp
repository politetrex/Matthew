#include <bits/stdc++.h>
using namespace std;
const int MAX_X = 100 + 5, MAX_Y = MAX_X, MAX_Z = MAX_X;
 
int s, u;
 
int arr[MAX_X][MAX_Y][MAX_Z]; // Shouldn't need lints
int d[MAX_X][MAX_Y][MAX_Z];
int dd[MAX_X][MAX_Y][MAX_Z];
int ddd[MAX_X][MAX_Y][MAX_Z];
void precomp() {
    for (int x = 0; x <= 99; x++) {
        for (int y = 0; y <= 99; y++) {
            int val = 0;
            for (int z = 0; z <= 99; z++) {
                val += ddd[x][y][z];
                dd[x][y][z] = val;
            }
        }
    }
 
    for (int x = 0; x <= 99; x++) {
        for (int z = 0; z <= 99; z++) {
            int val = 0;
            for (int y = 0; y <= 99; y++) {
                val += dd[x][y][z];
                d[x][y][z] = val;
            }
        }
    }
 
    for (int y = 0; y <= 99; y++) {
        for (int z = 0; z <= 99; z++) {
            int val = 0;
            for (int x = 0; x <= 99; x++) {
                val += d[x][y][z];
                arr[x][y][z] = val;
            }
        }
    }
}
 
int main() {
    // freopen("date.in", "r", stdin);
 
    cin.sync_with_stdio(false);
    cin.tie(0);
 
    cin >> s >> u;
    for (int i = 1; i <= s; i++) {
        int x1, x2, y1, y2, z1, z2;
        cin >> x1 >> x2 >> y1 >> y2 >> z1 >> z2;
        
        ddd[x1][y1][z1] += 1;
        ddd[x1][y1][z2 + 1] -= 1;
        
        ddd[x1][y2 + 1][z1] -= 1;
        ddd[x1][y2 + 1][z2 + 1] += 1;
        
        ddd[x2 + 1][y1][z1] -= 1;
        ddd[x2 + 1][y1][z2 + 1] += 1;
 
        ddd[x2 + 1][y2 + 1][z1] += 1;
        ddd[x2 + 1][y2 + 1][z2 + 1] -= 1;
    }
 
    precomp();
 
    int ans = 0; // Shouldn't need lints
    for (int i = 1; i <= u; i++) {
        int x, y, z, val;
        cin >> x >> y >> z >> val;
 
        if (arr[x][y][z]) continue;
        ans += val;
    }
    cout << ans << '\n';
}