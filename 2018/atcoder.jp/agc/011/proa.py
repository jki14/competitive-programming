def minimumNumberOfBus(a, c, k):
    foo = 0
    a = sorted(a)
    cur = 0
    while cur<len(a):
        departing_time = a[cur]+k
        space = c
        while space>0 and cur<len(a) and a[cur]<=departing_time:
            cur += 1
            space -= 1
        foo += 1
    return foo

def main():
    n, c, k = [int(x) for x in raw_input().strip().split()]
    a = [0 for i in xrange(n)]
    for i in xrange(n):
        a[i] = int(raw_input().strip())
    print minimumNumberOfBus(a, c, k)

if __name__ == '__main__':
    main()
