#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define int long long
#define vt vector
#define endl "\n"

const int N = 4e5 + 5;
bool apos[N], aneg[N], bpos[N], bneg[N], posspos[N], possneg[N];

signed main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    int n,m,q;
    cin >> n >> m >> q;
    vector<int> a(n), b(m);
    int asum = 0, bsum = 0;
    F0R(i, n) {
        cin >> a[i];
        asum += a[i];
    }
    F0R(i, m) {
        cin >> b[i];
        bsum += b[i];
    }
    F0R(i, n) {
        if(abs(asum-a[i]) < N) {
            if(asum-a[i]<0) aneg[a[i]-asum]=true;   
            else apos[asum-a[i]]=true;
        } 
    }
    F0R(i, m) {
        if(abs(bsum-b[i]) < N) {
            if(bsum-b[i]<0) bneg[b[i]-bsum]=true;   
            else bpos[bsum-b[i]]=true;
        } 
    }
    FOR(i, 1, N) {
        FOR(j, 1, N) {
            if(i * j > N) break;
            if(apos[i]&&bpos[j]) posspos[i*j]=true;
            if(apos[i]&&bneg[j]) possneg[i*j]=true;
            if(aneg[i]&&bpos[j]) possneg[i*j]=true;
            if(aneg[i]&&bneg[j]) posspos[i*j]=true;
        }
    }
    while(q--) {
        int x;
        cin >> x;
        if(x>0) {
            if(posspos[x]) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            if(possneg[-x]) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}