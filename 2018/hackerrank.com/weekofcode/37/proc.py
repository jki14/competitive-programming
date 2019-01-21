def run():
    a = [int(i) for i in raw_input().strip().split()]
    n = sum(a)
    if n < 3:
        return 0
    m = (n - 1) >> 1
    for i in xrange(26):
        if a[i]>0:
            a[i] -= 1
            break
    s = 0
    b = [0 for i in xrange(26)]
    c = [0 for i in xrange(26)]
    for i in xrange(26):
        b[i] = min(a[i], m-s)
        c[i] = a[i] - b[i]
        s += b[i]
    if (n&1)==0:
        for i in xrange(26):
            if c[i]>0:
                c[i] -= 1
                break
    foo = 0
    for i in xrange(26):
        for j in xrange(i+1, 26):
            cur = min(b[i], c[j])
            b[i] -= cur
            c[j] -= cur
            foo += cur
    return foo

def main():
    c = int(raw_input().strip())
    for i in xrange(c):
        print run()

if __name__ == '__main__':
    main()
