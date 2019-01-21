from sys import stdout
from sys import stderr

def check(w, h, a, s):
    if s == 0:
        return True
    r, c = h / s, w / s
    rem = c
    for w in a:
        cost = len(w)
        if cost <= rem:
            rem -= cost + 1
        else:
            rem = c
            r -= 1
            if rem < cost or r == 0:
                return False
            rem -= cost + 1
    return True

def solution(w, h, a):
    #todo: check w, h, and a are all valid
    lef, rig = 0, min(w, h)
    while lef < rig:
        mid = (lef + rig) >> 1
        if check(w, h, a, mid + 1):
            lef = mid + 1
        else:
            rig = mid
    return lef

def main():
    case_num = int(raw_input().strip())
    for case_id in xrange(1, case_num + 1):
        a = [i for i in raw_input().strip().split()]
        w = int(a[0])
        h = int(a[1])
        a = a[2:]
        stdout.write('Case #%d: %d\n' % (case_id, solution(w, h, a)))
        stdout.flush()

if __name__ == '__main__':
    main()
