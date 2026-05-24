n = int(input())
nums = list(map(int, input().split()))
nextSmallest = [0] * (n + 1)
stack = []

for i in range(n - 1, -1, -1):
    while stack and stack[-1][0] > nums[i]:
        val, index = stack.pop()
        nextSmallest[index] = i + 1

    stack.append([nums[i], i + 1])

print(*nextSmallest[1:])