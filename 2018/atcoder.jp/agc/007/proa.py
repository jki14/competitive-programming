def isAble(a, r, c):
    lastC = 1
    for i in xrange(r):
        lowbit = a[i]&-a[i]
        if popcount(a[i]+lowbit)!=1:
            return False
        if lowbit!=lastC:
            return False
        lastC = (a[i]+lowbit)>>1
    if lastC!=(1<<(c-1)):
        return False
    return True

def popcount(x):
    x = (x & 0x55555555) + ((x >> 1) & 0x55555555)
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333)
    x = (x & 0x0f0f0f0f) + ((x >> 4) & 0x0f0f0f0f)
    x = (x & 0x00ff00ff) + ((x >> 8) & 0x00ff00ff)
    x = (x & 0x0000ffff) + ((x >> 16) & 0x0000ffff)
    return x

def main():
    r, c = [int(x) for x in raw_input().strip().split()]
    a = []
    for i in xrange(r):
        row = raw_input().strip()
        foo = 0
        for j in xrange(c):
            if row[j]=='#':
                foo |= 1<<j
        a.append(foo)
    if isAble(a, r, c):
        print 'Possible'
    else:
        print 'Impossible'

if __name__ == '__main__':
    main()
