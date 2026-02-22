opt=[]
end=int(input())
while True:
    try:
        opt.append(input()[:end])
    except:
        break
for i in opt:
    print(i)