def core(m, n, c):
    return 1

for m in range(1, 4):
    for n in range(1, 4):
        cnt=n*m
        til=1<<cnt
        ans=0
        for c in range(1, til):
            ans+=2**core(m, n, c)
        print str(m)+'x'+str(n)+'='+str(ans)
