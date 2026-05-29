#include <bits/stdc++.h>   
using namespace std;
const int MAX_N = 1e5 + 5;
 
int n;
int arr[MAX_N];
 
int pref_val[MAX_N], suff_val[MAX_N];
void precomp() {
    set<int> arrs;
    for (int i = 1; i <= n; i++) {
        arrs.insert(arr[i]);
        pref_val[i] = arrs.size();
    }
 
    arrs.clear();
    for (int i = n; i >= 1; i--) {
        arrs.insert(arr[i]);
        suff_val[i] = arrs.size();
    }
}
 
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    
    precomp();
 
    int ans = 0;
    for (int i = 1; i <= n - 1; i++) 
        ans = max(ans, pref_val[i] + suff_val[i + 1]);
    cout << ans << '\n';
}