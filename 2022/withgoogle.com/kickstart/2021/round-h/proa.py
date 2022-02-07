from sys import stdout


def handler():
    s = input().strip()
    t = input().strip()

    f = [25 for i in range(26)]
    for c in t:
        f[ord(c) - ord('a')] = 0
    for i in range(26):
        f[i] = min(f[i - 1] + 1, f[i])
    for i in range(25, -1, -1):
        f[i] = min(f[(i + 1) % 26] + 1, f[i])
    for i in range(26):
        f[i] = min(f[i - 1] + 1, f[i])
    for i in range(25, -1, -1):
        f[i] = min(f[(i + 1) % 26] + 1, f[i])
    
    res = sum([f[ord(c) - ord('a')] for c in s])
    stdout.write('%d\n' % res)


def main():
    t = int(input().strip())
    for i in range(t):
        stdout.write('Case #%d: ' % (i + 1))
        handler()


if __name__ == '__main__':
    main()
