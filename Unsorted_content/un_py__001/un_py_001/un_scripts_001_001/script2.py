import random
def randmess(emb=1, txb=1, len=1000):
    s=""
    for i in range(len):
        seed=[]
        for j in range(emb): 
            seed.append(random.randint(128512, 128591))
            seed.append(random.randint(127789, 127845))
            seed.append(random.randint(128000, 128060))
            seed.append(random.randint(127744, 128317))
            seed.append(random.randint(129296, 129357))
        for j in range(txb): 
            seed.append(random.randint(32, 127))
            seed.append(random.randint(32, 127))
            seed.append(random.randint(32, 127))
            seed.append(random.randint(32, 127))
            seed.append(random.randint(32, 127))
            seed.append(random.randint(32, 127))
        s+=chr(random.choice(seed))
    return s
print(randmess(1,0))