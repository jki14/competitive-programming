# -*- coding: utf-8 -*-

import numpy
import sets

def check(s, pat):
    if len(s)!=len(pat):
        return False
    for i in range(len(pat)):
        if pat[i]!='?' and pat[i]!=s[i]:
            return False
    return True

case_num = int(raw_input())
for i in xrange(case_num):
    sc, sj = [s for s in raw_input().split()]
    ax = False
    ay = False
    n = len(sc)
    for x in xrange(1000):
        bx = str(x)
        while len(bx)<n:
            bx='0'+bx
        if not check(bx, sc):
                continue;
        for y in xrange(1000):
            by = str(y)
            while len(by)<n:
                by='0'+by
            if not check(by, sj):
                continue;
            if type(ax)==bool or abs(int(bx)-int(by))<abs(int(ax)-int(ay)):
                ax=bx
                ay=by
    print 'Case #'+str(i+1)+': '+str(ax)+' '+str(ay)
