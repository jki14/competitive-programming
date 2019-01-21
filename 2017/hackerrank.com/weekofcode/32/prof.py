n = int(raw_input())
a = raw_input().strip()

foo = {}

for i in xrange(0, n):
    for j in xrange(i, n):
        sub = a[i:j+1]
        if sub == sub[::-1]:
            for k in xrange(len(sub)):
                foo[sub[:k+1]]=True

print len(foo)
print sorted(foo.keys())
