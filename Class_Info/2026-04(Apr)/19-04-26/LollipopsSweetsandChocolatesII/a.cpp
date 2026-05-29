/*
Hint: Let's say we pick a value for R, and figure out what all the pamphlets look like. If any pamphlet
shows too many shops, what do we know about the correct value of R? Likewise, if any pamphlet
shows too little shops, what do we know? What about if both cases occur?
*/

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n, m, L, houses[maxn], shops[maxn], tnums[maxn], temp[maxn];
 
int isvalid(int R) {
	for (int i=0;i<m;i++) {
		int num = upper_bound(shops, shops+n, houses[i]+R) - lower_bound(shops, shops+n, houses[i]-R);
		temp[i] = num;
	}
	sort(temp, temp+m);
	for (int i=0;i<m;i++) {
		if (temp[i]<tnums[i]) { return false; }
	}
	return true;
}
 
int main() {
	freopen("lscin.txt", "r", stdin);
	freopen("lscout.txt", "w", stdout);
	scanf("%d%d%d", &n, &m, &L);
	for (int i=0;i<n;i++) scanf("%d",shops+i);
	for (int i=0;i<m;i++) scanf("%d",houses+i);
	for (int i=0;i<m;i++) scanf("%d",tnums+i);
	sort(shops, shops+n);
	sort(houses, houses+m);
	sort(tnums, tnums+m);

    int l = -1, r = L; 
	while (l+1<r) {
		int mid = (l+r)/2;
		if (isvalid(mid)) r = mid;
		else l = mid;
	}

	isvalid(r); 
	bool ans = true;
	for (int i=0;i<m;i++) if (temp[i]!=tnums[i]) { ans=false; break; }
	printf("%d\n",ans?r:-1);
}