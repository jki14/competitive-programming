
def urandom32(low, hig):
    with open('/dev/urandom', 'rb') as urand:
        foo = int(urand.read(8).encode('hex'), 16)
        foo %= hig-low+1
        foo = low+foo
        urand.close()
        return foo

n = 1000
d = urandom32(0, 10**2)
r = ''
for i in xrange(n):
    if len(r)>0:
        r += ' '
    r += str(urandom32(-10**2, 10**2))

print str(n)+' '+str(d)
print r
