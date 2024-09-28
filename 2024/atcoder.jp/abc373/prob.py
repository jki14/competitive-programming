from sys import stdout


def solution(a):
    if len(a) != 26:
        return
    foo = 0
    c = 'A'
    for i in range(26):
        foo += abs(ord(a[i]) - ord(c))
        c = a[i]
    stdout.write("%d\n" % foo)


def main():
    while True:
        try:
            a = input().strip()
        except EOFError:
            break
        solution(a)


if __name__ == '__main__':
    main()
