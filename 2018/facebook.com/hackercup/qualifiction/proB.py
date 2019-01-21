def main():
    caseNum = int(raw_input().strip())
    for caseId in xrange(caseNum):
        n = int(raw_input().strip())
        p = [int(raw_input().strip()) for i in xrange(n + 1)]
        if (n & 1) == 1:
            print('Case #%d: 1' % (caseId + 1))
            print('0.0')
        else:
            print('Case #%d: 0' % (caseId + 1))

if __name__ == '__main__':
    main()
