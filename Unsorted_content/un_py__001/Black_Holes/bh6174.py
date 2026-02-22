num=input("Enter a four-digit number with different digits\n")
stp_num=1
print("Inputted", num)
while num!='6174':
    print('Step', stp_num)
    digits=[]
    for i in num:
        digits.append(i)
    print('-> Digits:', ', '.join(digits))
    digits.sort()
    minnum=int(''.join(digits))
    digits.reverse()
    maxnum=int(''.join(digits))
    print('-> Minimum:', minnum)
    print('-> Maximum:', maxnum)
    num=str(maxnum-minnum)
    print('-> Number becomes', num)
    stp_num+=1
print("Encountered black hole!")