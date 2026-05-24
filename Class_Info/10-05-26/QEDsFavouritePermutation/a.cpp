#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> perm(n);
    for (int i = 0; i < n; i++){
        cin >> perm[i];
        perm[i]--;
    }
    string dir;
    cin >> dir;
    vector<int> diff_arr(n);
    for (int i = 0; i < n; i++){
        diff_arr[min(i, perm[i])]++;
        diff_arr[max(i, perm[i])]--;
    }
    for (int i = 1; i < n; i++){
        diff_arr[i] += diff_arr[i-1];
    }
    unordered_set<int> blocked_indices;
    for (int i = 0; i < n-1; i++){
        if (dir[i] == 'L' && dir[i+1] == 'R' && diff_arr[i] != 0){
            blocked_indices.insert(i);
        }
    }
    for (int i = 0; i < q; i++){
        int change_index;
        cin >> change_index;
        change_index--;
        if (dir[change_index] == 'L'){
            dir[change_index] = 'R';
        }
        else dir[change_index] = 'L';
        if (dir[change_index-1] == 'L' && dir[change_index] == 'R' && diff_arr[change_index-1] != 0){
            blocked_indices.insert(change_index-1);
        }
        else blocked_indices.erase(change_index-1);
        if (dir[change_index] == 'L' && dir[change_index+1] == 'R' && diff_arr[change_index] != 0){
            blocked_indices.insert(change_index);
        }
        else blocked_indices.erase(change_index);
        if (blocked_indices.size() == 0){
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}