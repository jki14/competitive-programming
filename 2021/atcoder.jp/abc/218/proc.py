from sys import stdout


def rr(s):
    n = len(s)
    return [''.join([s[n - j - 1][i] for j in xrange(n)]) for i in xrange(n)]


def transh(s):
    n = len(s)
    return [''.join([s[i][n - j - 1] for j in xrange(n)]) for i in xrange(n)]


def transv(s):
    n = len(s)
    return [''.join([s[n - i - 1][j] for j in xrange(n)]) for i in xrange(n)]


def std(s):
    n = len(s)
    dx, dy = 0, 0
    for i in xrange(n):
        if '#' in s[i]:
            dx = i
            break
    for j in xrange(n):
        if '#' in [s[i][j] for i in xrange(n)]:
            dy = j
            break
    return [''.join([s[i + dx][j + dy] if i + dx < n and j + dy < n else '.' for j in xrange(n)]) for i in xrange(n)]


def equal(s, t):
    n = len(s)
    for i in xrange(n):
        if s[i] != t[i]:
            return False
    return True


def rotatecheck(s, t):
    for i in xrange(4):
        s = rr(s)
        s = std(s)
        if equal(s, t):
            stdout.write('Yes\n')
            return True
    return False


def solution(s, t):
    t = std(t)
    if rotatecheck(s, t):
        return 0
    '''
    s = transh(s)
    if rotatecheck(s, t):
        return 0
    s = transv(s)
    if rotatecheck(s, t):
        return 0
    '''
    stdout.write('No\n')
    return 0


def main():
    while True:
        try:
            n = int(raw_input().strip())
            s = [raw_input().strip() for i in xrange(n)]
            t = [raw_input().strip() for i in xrange(n)]
            solution(s, t)
        except EOFError:
            break
        except ValueError:
            continue


if __name__ == '__main__':
    main()
