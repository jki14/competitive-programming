a = ''
b = ''

with open('/dev/urandom', 'rb') as src:
    for i in xrange(50):
        a+=chr(ord('A')+int(src.read(8).encode('hex'), 16)%26)
        b+=chr(ord('A')+int(src.read(8).encode('hex'), 16)%26)
    
print a
print b
