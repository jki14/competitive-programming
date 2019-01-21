n = int(raw_input())
m = int(raw_input())

foo = [0]

print foo

for i in xrange(m):
    goo = foo
    y = int(raw_input())
    for x in foo:
        if x^y not in goo:
            goo.append(x^y)
    goo.sort()
    print goo
    for x in xrange(1<<n):
        hoo = []
        for y in goo:
            hoo.append(x^y)
        hoo.sort()
        print str(x)+' : '+str(hoo)
