#import os
#import time

'''
class four_state:
    def __init__(self, col=[0, 0, 0, 0], row=0, cap=0):
        self.col = col
        self.row = row
        self.cap = cap
    
    def __hash__(self):
        return hash((tuple(self.col), self.row))
    
    def __eq__(self, other):
        return (self.col, self.row) == (other.col, other.row)
'''
'''
buf = dict()
for i in range(17):
    buf[i] = 0
'''
'''
f = list()
for i in range(17):
    f.append(dict())
f[0][four_state()] = 1

for x in range(4):
    for y in range(4):
        pos = x*4+y
        for pre, cnt in f[pos].iteritems():
            for val in range(pre.cap+1):
                if (y==0 or (pre.row&(1<<val))==0) and (pre.col[y]&(1<<val))==0:
                    col = pre.col[:]
                    col[y] |= 1<<val
                    row = pre.row if y>0 else 0
                    row |= 1<<val
                    nxt = four_state(col, row, max(val+1, pre.cap))
                    if x==3 and y==3:
                        break;
                    if nxt in f[pos+1]:
                        f[pos+1][nxt] = f[pos+1][nxt]+cnt
                    else:
                        f[pos+1][nxt] = cnt

for sta, cnt in f[16].iteritems():
    print cnt
'''
'''
def buf_entry(buf, row=0, col=[0, 0, 0, 0], cap=-1, x=0, y=0):
    if y==4:
        x+=1
        y=0
        row=0
    if x==4:
        buf[cap+1]+=1
        return
    for k in range(cap+2):
        if row&(1<<k)!=0:
            continue
        if col[y]&(1<<k)!=0:
            continue
        row^=(1<<k)
        col[y]^=(1<<k)
        buf_entry(buf, row, col, max(cap, k), x, y+1);
        row^=(1<<k)
        col[y]^=(1<<k)

start_flag = time.time()
buf_entry(buf)
print("--- %s seconds ---"%(time.time()-start_flag))

res = ''
for i in range(17):
    if len(res)>0:
        res += ','
    res += str(buf[i])

print res
'''

buf = [0,0,0,0,24,4896,185532,1569864,4552617,5787840,3717416,1310592,265110,31152,2076,72,1]

T = int(raw_input())
for _T in range(T):
    n = int(raw_input())
    r = 0
    for k in range(4, min(17, n+1)):
        s = buf[k]
        for i in range(k):
            s *= n-i
        r += s
    r = pow(r, 4)
    print r
