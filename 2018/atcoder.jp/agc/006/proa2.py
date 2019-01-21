def minimumLen(s, t):
    n = len(s)
    failed = [-1 for i in xrange(n)]
    pos = -1
    for i in xrange(1, n):
        while pos!=-1 and t[pos+1]!=t[i]:
            pos = failed[pos]
        if t[pos+1]==t[i]:
            pos += 1
        failed[i] = pos
    pos = -1
    for c in s:
        while pos!=-1 and t[pos+1]!=c:
            pos = failed[pos]
        if t[pos+1]==c:
            pos += 1
    return n*2-(pos+1)

def main():
    n = int(raw_input().strip())
    s = raw_input().strip()
    t = raw_input().strip()
    print minimumLen(s, t)

if __name__ == '__main__':
    main()
