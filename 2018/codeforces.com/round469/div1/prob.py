def rollback(cur, num):
    if (cur&1)==1:
        return (cur+1)>>1
    #if dif==-1:
    #    dif = num+((cur-1)>>1)+1-cur
    #else:
    #    dif >>= 1
    #return rollback(cur+dif, num, dif)
    dif = num+((cur-1)>>1)+1-cur
    tot = dif
    while (tot&1)==0:
        dif >>= 1
        tot += dif
    return (cur + tot + 1) >> 1

def main():
    n, q = [long(x) for x in raw_input().strip().split()]
    for i in xrange(q):
        p = long(raw_input().strip())
        print rollback(p, n)

if __name__ == '__main__':
    main()
