import sys


mod = 1000000000


def solution(a):
    foo = []
    bar = []
    x, y, k = 0, 0, 1
    for c in a:
        if c == 'N':
            y = (y - 1 + mod) % mod
        elif c == 'S':
            y = (y + 1 + mod) % mod
        elif c == 'E':
            x = (x + 1 + mod) % mod
        elif c == 'W':
            x = (x - 1 + mod) % mod
        elif c == ')':
            x = (x * foo[-1] + mod) % mod
            y = (y * foo[-1] + mod) % mod
            foo.pop()
            x = (x + bar[-1][0]) % mod
            y = (y + bar[-1][1]) % mod
            bar.pop()
        elif c == '(':
            foo.append(k)
            bar.append((x, y))
            x, y, k = 0, 0, 1
        else:
            k = int(c)
    return x + 1, y + 1
 

def main():
    num_cases = int(raw_input().strip())
    for i in xrange(num_cases):
        a = raw_input().strip()
        sys.stdout.write('Case #%d: %d %d\n' % ((i + 1,) + solution(a)))


if __name__ == '__main__':
    main()
