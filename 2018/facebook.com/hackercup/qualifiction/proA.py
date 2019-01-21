from fractions import gcd

def process(n, k ,v):
    #cycle = n * k / gcd(n, k)
    #prv = k * (v - 1) % cycle
    prv = k * (v - 1)
    cur = prv % n
    return sorted([(cur + i) % n for i in xrange(k)])

def solution(caseId):
    n, k, v = [int(i) for i in raw_input().strip().split()]
    a = [raw_input().strip() for i in xrange(n)]
    buf = 'Case #%d:' % (caseId);
    for i in process(n, k, v):
        buf += ' ' + a[i]
    print buf

def main():
    caseNum = int(raw_input().strip())
    for i in xrange(caseNum):
        solution(i + 1)

if __name__ == '__main__':
    main()
