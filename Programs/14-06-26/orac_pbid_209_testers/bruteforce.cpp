#include <iostream>
#include <algorithm>    
using namespace std;

bool can_meet_order(int ro, int bo, int s, int rp, int bp, 
                    int d_red, int d_blue, int d_spare) {
    int r_rem = ro - d_red;
    int b_rem = bo - d_blue;
    int s_rem = s - d_spare;
    
    if (r_rem < 0 || b_rem < 0 || s_rem < 0) return false;
    
    int need_r = max(0, rp - r_rem);
    int need_b = max(0, bp - b_rem);
    
    return need_r + need_b <= s_rem;
}

int brute_force_min_destroy(int ro, int bo, int s, int rp, int bp) {
    if (ro + s < rp || bo + s < bp) return 0;
    
    int max_destroy = ro + bo + s;
    
    for (int total_destroy = 0; total_destroy <= max_destroy; total_destroy++) {
        for (int d_red = 0; d_red <= min(ro, total_destroy); d_red++) {
            for (int d_blue = 0; d_blue <= min(bo, total_destroy - d_red); d_blue++) {
                int d_spare = total_destroy - d_red - d_blue;
                if (d_spare > s) continue;
                
                if (can_meet_order(ro, bo, s, rp, bp, d_red, d_blue, d_spare)) {
                    goto next_total;  // Break out of all loops
                }
            }
        }
        return total_destroy;
        next_total:;
    }
    return max_destroy;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int ro, bo, s, rp, bp;
    cin >> ro >> bo >> s >> rp >> bp;
    
    cout << brute_force_min_destroy(ro, bo, s, rp, bp) << "\n";
    
    return 0;
}