from __main__ import detect
from __main__ import defuse

def defuse_mines(N: int):
    number = detect(1,1)
    if(number!=0):
        for i in range(2,4):
            for j in range(2,4):
                defuse(i,j)
