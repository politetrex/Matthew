import heapq
n=int(input())
M=[0]*n
L=list(map(int,input().split()))
P=[]

k1,k2=0,0
for i in range(n):
    if k1!=n//2:
        if k1<=k2:heapq.heappush(P,L[i]);k1+=1
        else:
            k2+=1
            if P[0]<L[i]:heapq.heapreplace(P,L[i])
    else:
        if P[0]>=L[i]:k2+=1
        else:heapq.heapreplace(P,L[i])
print(sum(P))