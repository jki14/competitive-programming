def solution(s, t):
    cs = [0 for i in xrange(26)]
    for c in s:
        cs[ord(c) - ord('a')] += 1
    ps = { }
    for k in cs:
        if k > 0:
            if k not in ps:
                ps[k] = 1
            else:
                ps[k] += 1
    ct = [0 for i in xrange(26)]
    for c in t:
        ct[ord(c) - ord('a')] += 1
    for k in ct:
        if k > 0:
            if k not in ps:
                return False
            if ps[k] == 0:
                return False
            ps[k] -= 1
    return True

def main():
    s = raw_input().strip()
    t = raw_input().strip()
    if solution(s, t):
        print 'Yes'
    else:
        print 'No'

if __name__ == '__main__':
    main()
