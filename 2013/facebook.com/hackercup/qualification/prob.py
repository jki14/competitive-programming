from sys import stdout

def solution(s):
    #todo: check if s is valid
    n = len(s)
    f = [[False for i in xrange(n + 1)] for j in xrange(n + 1)]
    for i in xrange(n + 1):
        f[i][i] = True
    for i in xrange(n):
        if ord('a') <= ord(s[i]) and ord(s[i]) <= ord('z'):
            f[i][i + 1] = True
        elif s[i] == ' ' or s[i] == ':':
            f[i][i + 1] = True
    for i in xrange(n - 1):
        if f[i][i + 1] and f[i + 1][i + 2]:
            f[i][i + 2] = True
        elif s[i] == ':' and s[i + 1] in ['(', ')']:
            f[i][i + 2] = True
        elif s[i] == '(' and s[i + 1] == ')':
            f[i][i + 2] = True
    for k in xrange(3, n + 1):
        for i in xrange(n - k + 1):
            if s[i] == '(' and s[i + k - 1] == ')' and f[i + 1][i + k - 1]:
                f[i][i + k] = True
            else:
                for j in xrange(1, k):
                    if f[i][i + j] and f[i + j][i + k]:
                        f[i][i + k] = True
                        break
    return f[0][n]

def main():
    case_num = int(raw_input().strip())
    for case_id in xrange(1, case_num + 1):
        s = raw_input().strip()
        if solution(s):
            stdout.write('Case #%d: YES\n' % case_id)
        else:
            stdout.write('Case #%d: NO\n' % case_id)
        stdout.flush()

if __name__ == '__main__':
    main()
