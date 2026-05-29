def solve():
    n,q=map(int,input().split())
    p=list(map(int,input().split()))
    s=list(map(lambda x:x=='R',input()))
    
    for i in range(1,n):
        p[i]=max(p[i],p[i-1])
    
    count=sum(s[i]==0 and s[i+1] and p[i]!=i+1 for i in range(n-1))
    for i in range(q):
        k=int(input())-1
        count+=(k+1<n and s[k+1] and p[k]!=(k+1))*(1 if s[k] else -1)+(k>0 and s[k-1]==0 and p[k-1]!=k)*(-1 if s[k] else 1)
        s[k]^=1
        print('no' if count else 'yes')

import sys
input=sys.stdin.readline
for _ in range(int(input())):
    solve()