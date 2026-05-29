import sys
sys.setrecursionlimit(10000000)
infile = open('dropin.txt')
input = infile.readline
n = int(input())
l = [int(input()) for i in range(n)]
d = {}
for j, i in enumerate(l):
    d[i] = j
dp = [[-1 for i in range(n)] for j in range(n)]
def ans(i, j):
    if dp[i][j] != -1:
        return dp[i][j]
    if 2*l[j]-l[i] not in d:
        dp[i][j] = 2
        return 2
    dp[i][j] = ans(j, d[2*l[j]-l[i]]) + 1
    return dp[i][j]
best = 1
for i in range(n):
    for j in range(i+1, n):
        best = max(best, ans(i, j))
open('dropout.txt', 'w').write((str(best)+'\n'))
