def add((a,b),(c,d)):
    return a+c, b+d

def sub((a,b),(c,d)):
    return a-c, b-d

def rot((i,j)):
    return j,-i

def rotk(k,x):
    for it in xrange(k):
        x = rot(x)
    return x

def trans((k,d),x):
    return add(rotk(k,x),d)

def inv((k,d)):
    k = -k & 3
    return k, rotk(k^2,d)

def contains((c0,c1),p):
    return c0[0] <= p[0] <= c1[0] and c0[1] <= p[1] <= c1[1]


n = input()
s = input()
transes = [None]*(s+1)
corners = [None]*(s+1)
transes[0] = 0, (0,0)
corners[0] = (0,0), (n-1,n-1)

for i in xrange(s):
    a,b,d = map(int, raw_input().strip().split())
    a -= 1
    b -= 1
    itr = inv(transes[i]); i += 1
    ncorns = [trans(itr,x) for x in [(a,b),(a,b+d),(a+d,b+d),(a+d,b)]]
    transes[i] = i & 3, sub((a,b), rotk(i & 3, ncorns[3]))
    corners[i] = min(ncorns), max(ncorns)

for qq in xrange(input()):
    x = input()
    p = x/n, x%n
    L = 0
    R = s+1
    while R - L > 1:
        M = L + R >> 1
        if contains(corners[M],p):
            L = M
        else:
            R = M

    ans = trans((transes[L]),p)
    print "%s %s" % add(ans,(1,1))
