#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <random>
#include <math.h>
#include <time.h>
#include <string>
#include <vector>
#include <limits>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef long double ld;
constexpr ll MAX = 1 << 18;
constexpr int MAXN = 100005;

int N;
char arr[100005];

void print() {
	for (int i = 0; i < N; ++i) cout << arr[i] << " ";
	cout << "\n";
}
char getOther(char a, char b) {
	if (a + b == 'V' + 'D') return 'S';
	else if (a + b == 'V' + 'S') return 'D';
	else return 'V';
}

void solve(int i, char required) {
	if (arr[i] == required) return;
	if (i == 0) {
		arr[i] = required;
		print();
		return;
	}
	solve(i - 1, getOther(required, arr[i]));
	arr[i] = required;
	print();
	solve(i - 1, required);
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	//ifstream cin{ "robotin.txt" };
	//ofstream cout{ "robotout.txt" };
	cin >> N;
	for (int i = 0; i < N; ++i) arr[i] = 'V';
	print();
	solve(N-1, 'S');
}