prm = [ 2, 3, 5, 7 ,11 ,13 ,17, 19 ]

foo = 0

for i in xrange(8):
    foo += prm[i]**26

print foo % 2089141547
