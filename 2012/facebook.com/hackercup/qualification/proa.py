from sys import stdout

def solution(s, p = 'HACKERCUP'):
    #todo: check if s is valid
    g = [0 for i in xrange(26)]
    for c in p:
        if ord('A') <= ord(c) and ord(c) <= ord('Z'):
            g[ord(c) - ord('A')] += 1
    f = [0 for i in xrange(26)]
    for c in s:
        if ord('A') <= ord(c) and ord(c) <= ord('Z'):
            f[ord(c) - ord('A')] += 1
    foo = len(s)
    for i in xrange(26):
        if g[i] > 0:
            foo = min(f[i] / g[i], foo)
    return foo

def main():
    case_num = int(raw_input().strip())
    for case_id in xrange(1, case_num + 1):
        s = raw_input().strip()
        stdout.write('Case #%d: %d\n' % (case_id, solution(s)))
        stdout.flush()

if __name__ == '__main__':
    main()
