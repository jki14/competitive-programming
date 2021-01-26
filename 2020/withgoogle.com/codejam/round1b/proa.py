import sys


def solution(we, sn):
    foo = ''

    swe = 'WE'
    if we < 0:
        we = -we
        swe = swe[::-1]

    ssn = 'SN'
    if sn < 0:
        sn = -sn
        ssn = ssn[::-1]

    for k in xrange(0, 64):
        if (we >> k) == 0 and (sn >> k) == 0:
            break
        cwe = (we >> k) & 1
        csn = (sn >> k) & 1
        if cwe + csn != 1:
            foo = 'IMPOSSIBLE'
            break
        nwe = (we >> (k + 1)) & 1
        nsn = (sn >> (k + 1)) & 1
        if (we >> (k + 1)) == 0 and (sn >> (k + 1)) == 0:
            nwe = 1
            nsn = 0
        drt = (nwe + nsn) & 1
        if cwe:
            foo += swe[drt]
            we -= (1 << k) if drt else -(1 << k)
        else:
            foo += ssn[drt]
            sn -= (1 << k) if drt else -(1 << k)

    return foo


def process(case_id):
    we, sn = [int(i) for i in raw_input().strip().split()]
    sys.stdout.write('Case #%d: %s\n' % (case_id, solution(we, sn)))
    

def main():
    case_num = int(raw_input().strip())
    for i in xrange(case_num):
        process(i + 1)


if __name__ == '__main__':
    main()
