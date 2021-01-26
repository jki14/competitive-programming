import sys


def match(lhs, rhs):
    size = min(len(lhs), len(rhs))
    return lhs[:size] == rhs[:size]


def solution(a):
    head = ''
    tail = ''
    body = ''
    for pat in a:
        pre = pat.split('*')[0]
        if not match(pre, head):
            return '*'
        if len(head) < len(pre):
            head = pre
        suf = pat.split('*')[-1]
        if not match(suf[::-1], tail[::-1]):
            return '*'
        if len(tail) < len(suf):
            tail = suf
        for mid in pat.split('*')[1:-1]:
            body += mid
    return head + body + tail


def process(case_id):
    n = int(raw_input().strip())
    a = [raw_input().strip() for i in xrange(n)]
    sys.stdout.write('Case #%d: %s\n' % (case_id, solution(a)))
    

def main():
    case_num = int(raw_input().strip())
    for i in xrange(case_num):
        process(i + 1)


if __name__ == '__main__':
    main()
