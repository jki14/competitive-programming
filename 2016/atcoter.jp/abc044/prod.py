def func(b, n):
    if n<b:
        return [n]
    else:
        return func(b, n/b)+[n%b]

n = int(raw_input())
for b in range(2, n+2):
    foo=func(b, n)
    while len(foo)<10:
        foo=[0]+foo
    print 'f('+str(b)+','+str(n)+') = '+str(foo)+' = '+str(sum(foo))
