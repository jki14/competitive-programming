ans = 0
cur = 0
for i in xrange(30):
    r = i % 8
    if(r>=1 and r<=3):
        cur += 5
    elif(r>=5 and r<=7):
        cur -= 1
    if ans<cur:
        ans=cur

print cur
