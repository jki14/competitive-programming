# -*- coding: utf-8 -*-

import numpy
import sets

case_num = int(raw_input())
for i in xrange(case_num):
    x = int(raw_input())
    if x==0:
        print 'Case #'+str(i+1)+': INSOMNIA'
        continue
    tab = sets.Set()
    cur = 0
    while True:
        cur += x
        for c in str(cur):
            tab.add(c)
        if len(tab)==10:
            break
    print 'Case #'+str(i+1)+': '+str(cur)
