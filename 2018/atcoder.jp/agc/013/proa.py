def minimumSubSeq(a):
    n = len(a)
    f = [[0 for i in xrange(2)] for j in xrange(n)]
    f[0][0] = 1
    f[0][1] = 1
    for i in xrange(1, n):
        for j in xrange(2):
            f[i][j] = f[i-1][0] + 1
            f[i][j] = min(f[i][j], f[i-1][1] + 1)
            if (j==0 and a[i-1]>=a[i]) or (j==1 and a[i-1]<=a[i]):
                f[i][j] = min(f[i][j], f[i-1][j])
    return min(f[n-1][0], f[n-1][1])

def main():
    n = int(raw_input().strip())
    a = [int(i) for i in raw_input().strip().split()]
    print minimumSubSeq(a)

if __name__ == '__main__':
    main()
