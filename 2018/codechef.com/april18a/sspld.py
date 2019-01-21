def process():
    s, k = [int(i) for i in raw_input().strip().split()]
    g = [0 for i in xrange(k+1)]
    g[1] = 10
    f = [0 for i in xrange(k+1)]
    f[1] = 9
    for i in xrange(1, k):
        if (i&1)==0:
            g[i+1] = g[i] * (9 * i + 10)
            f[i+1] = f[i] * (9 * i + 10 - 1)
        else:
            g[i+1] = g[i]
            f[i+1] = f[i]
    

def main():
    c = (raw_input().strip())
    for i in xrange(c):
        print process()

if __name__ == '__main__':
    main()
