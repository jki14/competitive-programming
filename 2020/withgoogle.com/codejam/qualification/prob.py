import sys


def solution(a):
    n = len(a)
    hig = [i for i in a]
    lef = [0 for i in xrange(n)]
    rig = [0 for i in xrange(n)]
    for k in xrange(9, 0, -1):
        i = 0
        while i < n:
            if hig[i] == k:
                j = i
                while j + 1 < n and hig[j + 1] == k:
                    j += 1
                lef[i] += 1
                rig[j] += 1
                for p in xrange(i, j + 1):
                    hig[p] -= 1
                i = j + 1
            else:
                i += 1
    foo = [' ' for i in xrange(n + sum(lef) + sum(rig))]
    p = 0
    for i in xrange(n):
        for j in xrange(lef[i]):
            foo[p] = '('
            p += 1
        foo[p] = chr(ord('0') + a[i])
        p += 1
        for j in xrange(rig[i]):
            foo[p] = ')'
            p += 1
    return ''.join(foo)


def process(case_id):
    a = [int(i) for i in raw_input().strip()]
    res = solution(a)
    sys.stdout.write('Case #%d: %s\n' % (case_id, res))
    

def main():
    case_num = int(raw_input().strip())
    for i in xrange(case_num):
        process(i + 1)


if __name__ == '__main__':
    main()
