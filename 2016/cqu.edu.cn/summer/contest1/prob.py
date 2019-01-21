import fractions

for n in range(1, 100):
    ans=1
    for m in range(1, n+1):
        cur=1
        for i in xrange(m):
            cur*=n-i
            cur/=i+1
        ans=ans*cur/fractions.gcd(ans, cur)
    print ans
