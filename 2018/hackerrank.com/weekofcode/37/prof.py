mod = 10**9+7

def calc(a, m):
    l = len(a)
    b = [-1 for i in xrange(l)] 
    p = -1
    for i in xrange(1, l):
        while p!=-1 and a[p+1]!=a[i]:
            p = b[p]
        if a[p+1]==a[i]:
            p += 1
        b[i] = p
    r = max(b)+1
    for i in xrange(max(a)+1):
        r = r * (m - i) % mod
    #print 'calc %s = %d (%d)' % (str(a), r, max(b)+1)
    return r

def dfs(f, p, k, n, m):
    if p==n:
        return calc(f, m) % mod
    foo = 0
    for f[p] in xrange(min(k+2, m)):
        foo = (foo + dfs(f, p+1, max(k, f[p]), n, m)) % mod
    return foo

def process():
    try:
        n, m = [int(i) for i in raw_input().strip().split()]
    except ValueError:
        return True
    except EOFError:
        return False
    
    f = [0 for i in xrange(n)]
    print dfs(f, 0, -1, n, m)

    return True

def main():
    while True:
        if not process():
            break

if __name__ == '__main__':
    main()
