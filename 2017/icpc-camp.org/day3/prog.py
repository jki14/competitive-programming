import numpy

offset = 0

while True:
    #print "-"*32
    try:
        n = int(raw_input())
    except EOFError:
        break
    a = numpy.array([int(i) for i in raw_input().split()], dtype='i')

    print a

    r = numpy.zeros(n, dtype='i')

    idx = 0
    
    while True:
        b = numpy.zeros(n, dtype='i')
        for i in xrange(a.shape[0]):
            b[a[i]]=i
        print str(idx) + ' ' + str(a) + ' ' + str(b)
        if a[0]==0:
            break
        #if idx>1024:
        #    idx = -1
        c = a[0]
        for i in xrange(c):
            a[i] = a[i+1]
        a[c] = c
        r[c] += 1
        idx += 1
    #print str(offset)+' '+str(idx)+' '+str(r)
    #offset += 1
