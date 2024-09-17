import random

n = 200000
m = 50000

print("%d %d" % (n, m))
f = lambda: random.randint(1, 10000)
a = [f() for i in range(n)]
print(" ".join([str(i) for i in a]))
