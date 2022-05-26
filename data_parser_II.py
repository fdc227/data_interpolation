from asyncore import write
from multiprocessing.pool import Pool

import pickle
from sympy import *

raw = open("data.pkl", 'rb')
data = pickle.load(raw)

# Alpha,Cl,Cd,Cdp,Cm,Top_Xtr,Bot_Xtr

Alpha = []
Cl = []
Cd = []
Cdp = []
Cm = []
Top_Xtr = []
Bot_Xtr = []

for i in data:
    Alpha.append(i[0])
    Cl.append(i[1])
    Cd.append(i[2])
    Cdp.append(i[3])
    Cm.append(i[4])
    Top_Xtr.append(i[5])
    Bot_Xtr.append(i[6])

def write_array_to_file(arr, fname):
    raw = open(fname, 'w')
    for i in arr:
        raw.write(str(i)+'\n')
    raw.close()
    return

write_array_to_file(Alpha, "./data/Alpha.dat")
write_array_to_file(Cl, "./data/Cl.dat")
write_array_to_file(Cd, "./data/Cd.dat")
write_array_to_file(Cm, "./data/Cm.dat")