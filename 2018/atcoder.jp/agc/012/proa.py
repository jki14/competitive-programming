def maximumSum(a):
    foo = 0
    n = len(a)/3
    a = sorted(a)
    for i in xrange(n):
        foo += a[n*3-(i+1)*2]
    return foo

def main():
    n = int(raw_input().strip())
    a = [int(x) for x in raw_input().strip().split()]
    print maximumSum(a)

if __name__ == '__main__':
    main()
