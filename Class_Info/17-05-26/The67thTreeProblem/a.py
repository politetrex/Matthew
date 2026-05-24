for _ in range(int(input())):
    x, y = map(int, input().split())
    n = x + y
    d = y - x

    if (x == 0 and n % 2 == 0) or n//2<x:
        print("NO")
        continue

    print("YES")

    mm = 2 * x + (d % 2)

    for i in range(2, mm + 1):
        print(i - 1, i)


    for i in range(mm + 1, n + 1):
        print(mm, i)