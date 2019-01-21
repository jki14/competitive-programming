with open('proe.ans', 'r') as ansf:
    ans = ansf.readlines()
    with open('proe.out', 'r') as outf:
        out = outf.readlines()
    for i in xrange(len(ans)):
        req = ans[i].strip()
        if len(req)==0:
            continue
        rep = out[i].strip()
        if req!=rep:
            print 'error found at line %d, expected %s, %s found.' % (i, req, rep)
