def count(n, d, v):
    if v>0:
        lef, rig = 0, n-1
        while lef<=rig:
            mid = (lef+rig)>>1
            if v+d*mid>0:
                if mid==rig or v+d*(mid+1)<=0:
                    return mid+1
                lef = mid + 1
            else:
                rig = mid - 1
    else:
        if v+d*(n-1)<=0:
            return 0
        lef, rig = 0, n-1
        while lef<=rig:
            mid = (lef+rig)>>1
            if v+d*mid>0:
                if mid==lef or v+d*(mid-1)<=0:
                    return n-mid
                rig = mid - 1
            else:
                lef = mid + 1

def main():
    c = int(raw_input().strip())
    for i in xrange(c):
        s, n = [sub for sub in raw_input().strip().split()]
        n = int(n)
        m = len(s)
        a = [0 for i in xrange(m)]
        if s[0]=='a':
            a[0] = 1
        else:
            a[0] = -1
        for i in xrange(1, m):
            if s[i]=='a':
                a[i] = a[i-1] + 1
            else:
                a[i] = a[i-1] - 1
        foo = 0
        for i in xrange(0, m):
            foo += count(n, a[-1], a[i])
        print foo

if __name__ == '__main__':
    main()
