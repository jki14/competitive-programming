from sys import stdout

def Eea(a, b):
    if b == 0:
        return a, 1, 0;
    else:
        d, x, y = Eea(b, a % b)
        x, y = y, x - (a / b) * y
        return d, x, y

def Inversee(a, mod = 1000000007):
    return Eea(a, mod)[1]

def ModPow(x, y, mod = 1000000007):
    r = 1
    i = 1
    while i <= y:
        if (y & i) != 0:
            r = (r * x) % mod
        x = (x * x) % mod
        i <<= 1
    return r

def MagicPlay(a, k, mod = 1000000007):
    if a != 1:
        return a * (ModPow(a, k) - 1) % mod * Inversee(a - 1) % mod
    else:
        return k

def KickstartAlarm(a, k, mod = 1000000007):
    n = len(a)
    foo = 0
    prefix = 0
    for i in xrange(n):
        increment = MagicPlay(i + 1, k)
        prefix = (prefix + increment) % mod
        foo = (foo + prefix * a[i] % mod * (n - i) % mod) % mod
    foo = (foo % mod + mod) % mod
    return foo

def main():
    c = int(raw_input().strip())
    for i in xrange(c):
        n, k, x1, y1, C, D, E1, E2, F = [int(j) for j in raw_input().strip().split()]
        x = [x1 for j in xrange(n)]
        y = [y1 for j in xrange(n)]
        for j in xrange(1, n):
            x[j] = (x[j - 1] * C + y[j - 1] * D + E1) % F
            y[j] = (x[j - 1] * D + y[j - 1] * C + E2) % F
        a = [(x[j] + y[j]) % F for j in xrange(n)]
        print('Case #%d: %d' % (i + 1, KickstartAlarm(a, k)))
        stdout.flush()

if __name__ == '__main__':
    main()
