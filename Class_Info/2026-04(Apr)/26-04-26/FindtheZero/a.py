for _ in range(int(input())):
    n = int(input())
    ans = -1
    for i in range(1, n):
        print("?", 2 * i + 1, 2 * i + 2, flush=True)
        if int(input()):
            ans = 2 * i + 1 
            break
    else:
        print("?", 1, 3, flush=True)
        if int(input()):
            ans = 1
        else:
            print("?", 1, 4, flush=True)
            if int(input()):
                ans = 1
            else:
                ans = 2
    print("!", ans, flush=True)