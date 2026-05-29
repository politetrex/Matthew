# https://cses.fi/problemset/task/1620

n, t = map(int, input().split())
machines = list(map(int, input().split()))

# given a certain amount of time, how much do all the machines produce?
def numProduced(data, timeElapsed):
    return sum(timeElapsed // x for x in data)

# binary search for the most optimal time
def bs(lo, hi, data, target):
    mid = (lo + hi) // 2

    if numProduced(data, mid) < target:
        return bs(mid + 1, hi, data, target)
    elif numProduced(data, mid - 1) >= target:
        return bs(lo, mid - 1, data, target)
    else:
        return mid

print(bs(0, max(machines) * t, machines, t))