# -*- coding: utf-8 -*-

def main_entry():
    k, c, s = [int(x) for x in raw_input().split()]
    if c*s < k:
        return 'IMPOSSIBLE'
    ans = ''
    cur = -1
    while True:
        cur += 1
        pos = cur
        for i in xrange(c-1):
            pos *= k
            if cur<k-1:
                cur += 1
                pos += cur
        if len(ans)>0:
            ans += ' '
        ans += str(pos+1)
        if cur>=k-1:
            break
    return ans

case_num = int(raw_input())
for i in xrange(case_num):
    print 'Case #'+str(i+1)+': '+main_entry()
