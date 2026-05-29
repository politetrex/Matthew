from svg.creator import Creator
from svg.elements import *
import svg.errors

FILENAME = "svg_output"
C = Creator(width=2000, height=2000)
col1 = "#E7CACA"
col2 = "#DEE7BE"
col3 = "#FFFF66"
col4 = "#F72424"
file = "Win_data/task4sample.dat"
f = open(file, "r")
    
if __name__ == "__main__":
    pos = {}
    for r in range(4):
        c = 0
        for i in f.readline().strip().split():
            if i:
                if i == "*": i=0
                else: i = int(i)
                pos[i] = (80*c+5, 80*r+5)
                c += 1
                
    for i in range(0, 16):
        r, c = pos[i]
        g = Svg(x=r, y=c)
        g.add_child(Rect(
            id=f"{r*4+c}Rect",
            x=0,
            y=0,
            width=75,
            height=75,
            colour=col1,
            #style=f"fill: {col1}"
        ))
        if i < 10:
            g.add_child(Text(
                i,
                id=f"{r*4+c}Text",
                x=30,
                y=50.5,
                style="font: bold 30px sans-serif;",
            ))
        else:
            g.add_child(Text(
                i,
                id=f"{r*4+c}Text",
                x=25,
                y=50.5,
                style="font: bold 30px sans-serif;",
            ))
        C.add_child(g)
    
    f.readline()
    
    t = 0
    for x in f.readline().strip().split():
        x = int(x)
        if pos[0][0] != pos[x][0] and pos[0][1] != pos[x][1]:
            # error
            break
        C.children[x].add_child(Animate(
            attributeName="x",
            fill="freeze",
            begin=f"{t}s",
            dur="0.4s",
            to=pos[0][0]
        ))
        C.children[x].add_child(Animate(
            attributeName="y",
            fill="freeze",
            begin=f"{t}s",
            dur="0.4s",
            to=pos[0][1]
        ))
        if False:
            C.children[x].add_child(Animate(
                attributeName="style",
                fill="freeze",
                begin=f"{t}s",
                dur="0.4s",
                to=f"fill: {col2}"
            ))
        pos[0], pos[x] = pos[x], pos[0]
        t += 0.4
    
    C.write_to(FILENAME + '.html')
    C.write_to(FILENAME + '.svg')
    #C.view()
    print(C)
