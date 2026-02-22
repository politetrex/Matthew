num=input()
stp_num=1
print("Inputted", num)
while num!='123':
    print('Step', stp_num)
    odds=0
    evens=0
    length=len(num)
    for i in num:
        if i=='1' or i=='3' or i=='5' \
            or i=='7' or i=='9':
            odds+=1
        else:
            evens+=1
    num=str(evens)+str(odds)+str(length)
    print("-> Number becomes", num)
    stp_num+=1
print("Black hole made!")