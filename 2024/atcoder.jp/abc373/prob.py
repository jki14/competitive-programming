from sys import stdout


def solution(a):
    if len(a) != 26:
        return
    b = {c: i for i, c in enumerate(a)}
    s = ''.join(['A'] + [chr(ord('A') + i) for i in range(26)])
    foo = 0
    for i in range(1, 27):
        foo += abs(b[s[i]] - b[s[i - 1]])
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
