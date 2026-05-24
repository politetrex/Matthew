t=int(input())
for _ in range(t):
    n=int(input())
    s=input()
    
    p=[0]
    ans=0
    for i in s:
        p.append(int(i)+p[-1])
    for j in range(n+1):
        p[j]=p[j]-j 
    
    d={}
    for i in p:
        d[i]=0
    for i in p:
        d[i]=d[i]+1
    for k in d:
        ans=ans+((d[k])*(d[k]-1))//2
    print(ans)