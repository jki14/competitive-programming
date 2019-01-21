# calculate (x ** y) % z
def QuickPowMod(x, y, z):
    foo = 1
    c = x % z
    h = 1
    while h <= y:
        if (y & h) != 0:
            foo = foo * c % z
        c = c * c % z
        h <<= 1
    return foo

def HugeNumbers(a, n, p):
    foo = a % p
    for i in xrange(2, n + 1):
        foo = QuickPowMod(foo, i, p)
    return (foo % p + p) % p

def main():
    c = int(raw_input().strip())
    for i in xrange(c):
        a, n, p = [int(j) for j in raw_input().strip().split()]
        print('Case #%d: %d' % (i + 1, HugeNumbers(a, n, p)))

if __name__ == '__main__':
    main()
