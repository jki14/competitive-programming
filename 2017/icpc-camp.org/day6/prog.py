import os
from sets import Set

(a, b) = [int(i) for i in raw_input().split()]

hashset = Set([])
hashmap = dict()

def hashval(foo):
    h = 0
    for c in foo:
        h = (h*a+ord(c)-97+1)%b
    return h

while True:
    foo = list('?'*7)
    for i in xrange(7):
        foo[i] = chr(97 + (int(os.urandom(1).encode('hex'), 16) % 26))
    foo = ''.join(foo)
    if foo not in hashset:
        hashset.add(foo)
        h = hashval(foo)
        #print foo+' '+str(h)
        if h not in hashmap:
            hashmap[h] = foo
        else:
            goo = hashmap[h]
            for k in xrange(100):
                ans = ''
                for i in xrange(7):
                    if (k&(1<<i))==0:
                        ans += foo
                    else:
                        ans += goo
                print ans
            break
