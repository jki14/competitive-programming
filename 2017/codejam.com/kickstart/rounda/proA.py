def SquareCounting(r, c):
    n = min(r, c)
    foo = n * (n + 1) / 2 * (r * c)
    foo -= ((n - 1) * n * (n + 1) / 3) * (r + c)
    foo += (n - 1) * n * (n + 1) * (3 * n - 2) / 12
    return foo % 1000000007

def main():
    c = int(raw_input().strip())
    for i in xrange(c):
        r, c = [int(k) for k in raw_input().strip().split()]
        print 'Case #%d: %d' % (i+1, SquareCounting(r - 1, c - 1))

if __name__ == '__main__':
    main()
