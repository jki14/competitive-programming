raw = ''
cnt = 0

for i in xrange(1, 100):
    for j in xrange(1, 100):
        cnt += 1
        raw += '%d %d %d %d\n' % (i, j, 1, 1)

raw = str(cnt) + '\n' + raw

print raw
