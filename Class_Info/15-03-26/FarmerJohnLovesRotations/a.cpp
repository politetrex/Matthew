#include <bits/stdc++.h>
using namespace std;

template <class T> using V = vector<T>;
#define all(x) begin(x), end(x)

void ckmin(int &a, int b) { a = min(a, b); }
void ckmax(int &a, int b) { a = max(a, b); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    V<int> A(N);
    for (int &t : A) cin >> t;

    V<int> lst(N + 1, -1), nxt(N, -1);
    V<int> ans(N, N);
    auto add_ival = [&](int l, int r) {
        assert(l <= r);
        int len = r - l;
        ckmin(ans.at(l), len);
        ckmin(ans.at(r % N), len);
    };
    int r = 0;
    for (int i = 0; i < 2 * N; ++i) {
        int &ls = lst.at(A.at(i % N));
        if (ls == -1) {
            ckmax(r, i);
        } else if (ls < N) nxt.at(ls) = i;
        ls = i;
    }
    for (int i = 0; i < N; ++i) {
        add_ival(i, r);
        assert(nxt.at(i) != -1);
        ckmax(r, nxt.at(i));
    }
    for (int it = 0; it < 2; ++it) {
        for (int i = 0; i < N; ++i) ckmin(ans.at((i + 1) % N), ans.at(i) + 1);
        for (int i = N - 1; i >= 0; --i)
            ckmin(ans.at(i), ans.at((i + 1) % N) + 1);
    }
    for (int i = 0; i < N; ++i) {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << "\n";
}