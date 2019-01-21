# -*- coding: utf-8 -*-

import numpy
import sets

def greedy_entry(a):
    ans = 0
    for c in reversed(a):
        if c=='+':
            if (ans&1)==1: ans+=1
        else:
            if (ans&1)==0: ans+=1
    return ans

case_num = int(raw_input())
for i in xrange(case_num):
    a = raw_input()
    print 'Case #'+str(i+1)+': '+str(greedy_entry(a))
