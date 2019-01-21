def ethan(pattern, text):
    n = len(text)
    m = len(pattern)
    j = 0
    for i in xrange(n):
        if text[i] == pattern[j]:
            j += 1
            if j == m:
                return True
        else:
            j = 0
    return False

def solution(pattern):
    n = len(pattern)
    fail = [-1 for i in xrange(n)]
    for i in xrange(1, n):
        prev = fail[i - 1]
        while prev != -1 and pattern[i] != pattern[prev + 1]:
            prev = fail[prev]
        if pattern[i] == pattern[prev + 1]:
            prev += 1
        fail[i] = prev
        while prev != -1:
            temp = pattern[:i] + pattern[prev:]
            if not ethan(pattern, temp):
                return temp
            prev = fail[prev]
    return 'Impossible'

def main():
    caseNum = int(raw_input().strip())
    for caseId in xrange(caseNum):
        pattern = raw_input().strip()
        print('Case #%d: %s' % (caseId + 1, solution(pattern)))

if __name__ == '__main__':
    main()
