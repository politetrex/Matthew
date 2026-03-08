N, X = map(int, input().split())
nums = sorted(list(map(int, input().split())))
INF = 10**9
dp = [INF]*(X+1)
dp[0] = 0

def solve():
    for x in nums:
        for i in range(x, X+1):
            if (i-x) >= 0:
                dp[i] = min(dp[i-x]+1, dp[i])
            if i < x:
                break

    print(dp[-1] if dp[-1] != INF else -1)

solve()