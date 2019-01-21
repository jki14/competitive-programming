#!/bin/python

a = []
mod = pow(10, 9) + 9

for i in range(1010):
    t = [0] * (i + 1)
    a.append(t)
    for j in range(0, len(t)):
        if j in [0, i]:
            a[i][j] = 1
        else:
            a[i][j] = (a[i - 1][j - 1] + a[i - 1][j]) % mod

t = int(raw_input().strip())
for _ in range(t):
    n, k = [int(x) for x in raw_input().split()]
    n -= 1
    n_k = []
    n_k.append(n)
    for i in range(1, k + 1):
        t = (pow(n + 1, i + 1, mod) - 1) % mod
        s = 0
        for j in range(2, i + 2):
            s += (a[i + 1][j] * n_k[i + 1 - j]) % mod
        n_k.append((((t - s) % mod) * pow(a[i + 1][1], mod - 2, mod)) % mod)
    foo = n_k[-1]
    foo -= 1
    foo = ((foo % mod) + mod) % mod
    print foo
