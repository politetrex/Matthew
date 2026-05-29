# Even More Odd Photos (2021 January, bronze2)
# NuttyJamie's Solution
"""
It's pretty intuitive to classify the numbers into odd and even ones
since even do not affect the group's divisibility by 2
what really matters is #(odds)!
Then we have to do some casework:
if #(odds) < #(evens):
then we put 0 odds, some evens in the 1st group
            1 odd , no   evens in the 2nd group
            0 odds, some evens in the 3rd group
            ...
            1 odd , no   evens in the (last - 1) group
            0 odds, some evens in the last group
The evens can be put randomly in the groups where there are no odds (to avoid an empty group)
Since #(evens) > #(odds), this strategy is always feasible
so our answer in this case is #(odds) * 2 + 1

if #(odds) = #(evens):
We use (almost) the same strategy as above
1st group: 0 odds, 1 even
2nd      : 1 odd, 0 evens
3rd      : 0 odds, 1 even
...
last     : 1 odd, 0 evens
so our answer in this case is #(odds) * 2 (or just the number of cows)
it's impossible to open up another group since the odds and evens have both used up

if #(odds) > #(evens):
Let's explore the sample case:
1 3 5 7 9 11 13 (7 odds and 0 evens)
In this case, we've got 0 evens and too many odds,
so we have to add up 2 odds and get 1 even in return
We use a while loop to repeat the process until #(odds) >= #(evens)
like that: (1 3)(5 7)(9 11) 13 ==> 4 12 20 13
so we can solve it as mentioned above
"""
N = int(input())
cows = [int(i) for i in input().split()]
odd = even = 0
for i in cows:
    odd += i % 2 == 1
    even += i % 2 == 0
while odd > even:
    odd -= 2
    even += 1
print(odd * 2 + 1 if odd < even else N)