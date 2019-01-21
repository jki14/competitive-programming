# -*- coding: utf-8 -*-

def main_entry(length, required):
    til = ''
    for b in range(2, 11):
        til = til+' '+str(b+1)
    x=1<<(length-1)
    cnt = 0
    while True:
    	x += 1
        if (x&1)==0:
            continue
        buf = "{0:b}".format(x)
        flag = True
        for b in range(2, 11):
            cur = 0
            for c in buf:
                cur *= b
                if c=='1':
                    cur += 1
            if (cur%(b+1))!=0:
                flag = False
                break
        if flag:
            print buf+' '+til
	    cnt += 1
            if cnt==required:
                break

case_num = int(raw_input())
for i in xrange(case_num):
    length, required = [int(x) for x in raw_input().split()]
    print 'Case #'+str(i+1)+': '
    main_entry(length, required)
