CTI = {"W": 0, "G": 1, "B": 2}
 
def tc():
    N, A, B = [int(x) for x in input().split()]
    grid = [[CTI[x] for x in input()] for _ in range(N)]
    stars = [[0 for _ in range(N)] for _ in range(N)]
 
    for i in range(N):
        for j in range(N):
            if grid[i][j] == 2:
                stars[i][j] = 1
                if i < B or j < A:
                    print(-1)
                    return
                if grid[i-B][j-A] == 0:
                    print(-1)
                    return
                stars[i-B][j-A] = 1
 
    for i in range(N):
        for j in range(N):
            if grid[i][j] == 1:
                if stars[i][j] == 1:
                    continue
                if i < B or j < A:
                    stars[i][j] = 1
                    continue
                if stars[i-B][j-A] == 1:
                    continue
                stars[i][j] = 1
                    
    print(sum(sum(x) for x in stars))
 
T = int(input())
 
while T > 0:
    T -= 1
    tc()