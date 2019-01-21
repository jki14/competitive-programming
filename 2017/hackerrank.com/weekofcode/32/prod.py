print 500000
foo = ''
for i in xrange(500000):
    foo += 'abc'[i%3]
print foo
