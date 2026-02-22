def median(x):
    count=0
    for i in range(n//2,n):
        count+=max(0,x-a[i])
    return count<=k

def solve(lo,hi):
    lo-=1
    while lo<hi:
        mid=lo+(hi-lo+1)//2
        if median(mid):
            lo=mid
        else:
            hi=mid-1
    return lo

n,k=map(int,input().split())
a=sorted(list(map(int,input().split())))
print(solve(1,2000000000))