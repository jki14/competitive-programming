from sys import stdout


def solution(s):
    foo, m = 0, 1
    for i in range(1, len(s)):
        m *= 26
        foo += m
    for i in range(len(s)):
        foo += m * (ord(s[i]) - ord('A'))
        m /= 26
    stdout.write('%d\n' % (foo + 1))

def main():
    while True:
        try:
            s = input().strip()
        except ValueError:
            continue
        except EOFError:
            break
        solution(s)


if __name__ == '__main__':
    main()
