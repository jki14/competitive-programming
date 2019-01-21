foo = 0

for i in xrange(12):
    x, y = [int(i) for i in raw_input().split()]
    foo += x*x + y*y

print foo
