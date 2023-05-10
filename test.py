from sys import argv
import random

if len(argv) < 2:
    exit(0)
n = 0
a = list()
try:
    while (n != int(argv[1])):
        b = random.randint(0, int(argv[1]))
        if  b not in a:
            a.append(b)
            n += 1

    for i in a:
        print(i, end=" ")
except:
    exit(1)
