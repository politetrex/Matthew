from math import sqrt

def f(x):
    return sqrt(x*x*x-x*x+3*x) / (sqrt(x*x*x) - abs(x) + sqrt(3*x))

"""l = 0
r = 10**10
while r - l > 1e-10:
    m = (l+r)/2
    if f(m) > 100/99: l = m
    else: r = m
print("Problem 1", r)
"""


total = 0
infty = 100000
for k in range(infty):
    total += (-1)**(k+1) * k * k / (k*k*k+1)
    if k > infty - 3:
        print(total)
        
print("Problem 2", total)
