import os

def main():
    s = 1000
    n = 100
    print '%d %d' % (s, n<<1)
    c = [ [False for j in xrange(s+1)] for i in xrange(s+1)]
    for i in xrange(n):
        x = int(os.urandom(4).encode('hex'), 16) % (s+1)
        y = int(os.urandom(4).encode('hex'), 16) % (s+1)
        while c[x][y]:
            x = int(os.urandom(4).encode('hex'), 16) % (s+1)
            y = int(os.urandom(4).encode('hex'), 16) % (s+1)
        c[x][y] = True
        print '%d %d' % (x, y)
    junctionCost = (int(os.urandom(4).encode('hex'), 16) % 1000001) * 1.0 / 100000.0
    failureProbability = (int(os.urandom(4).encode('hex'), 16) % 400001) * 1.0 / 1000000.0
    print '%.6f %.6f' % (junctionCost, failureProbability)

if __name__ == '__main__':
    main()
