pic = (set([0,1,2,4,5,6]),set([2,5]),set([0,2,3,4,6]),set([0,2,3,5,6]),set([1,2,3,5]),set([0,1,3,5,6]),set([0,1,3,4,5,6]),set([0,2,5]),set([0,1,2,3,4,5,6]),set([0,1,2,3,5,6]))

buf = ''

for x in range(0,10):
    buf += '('
    for y in range(0,10):
        if y>0:
            buf+=','
        buf+=str(len(pic[x]&pic[y]))
    buf += ')'
    if x!=9:
        buf += ','

print buf
