#include <iostream>
#include <random>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist(1, 1000);
    
    for(int i = 0; i < 5; i++) {
        cout << dist(rng);
        if(i < 4) cout << " ";
    }
    cout << "\n";
    
    return 0;
}