def check(a):
    a = sorted(a)
    d = {}
    for x in a:
        if x not in d.keys():
            d[x] = 1
        else:
            d[x] += 1
    if (a[-1]+1)>>1 != a[0]:
        return False
    if (a[-1]&1) != 1 and d[a[0]]!=1:
        return False
    if (a[-1]&1) == 1 and d[a[0]]!=2:
        return False
    for i in xrange(a[-1], a[0], -1):
        if i not in d.keys() or d[i]<2:
            return False
    return True

def main():
    n = int(raw_input().strip())
    a = [int(x) for x in raw_input().strip().split()]
    if check(a):
        print 'Possible'
    else:
        print 'Impossible'

if __name__ == '__main__':
    main()
