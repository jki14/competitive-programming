import os

foo = ''

for i in xrange(200000):
    foo += chr(ord('a')+int(os.urandom(1).encode('hex'), 16)%26)

print foo
