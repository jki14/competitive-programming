from sys import stdout


def solution(s, n):
    for i in range(1, n):
        for j in range(n):
            if j + i == n or s[j] == s[j + i]:
                stdout.write('%d\n' % (j))
                break

def main():
    while True:
        try:
            n = int(input().strip())
            s = input().strip()
        except ValueError:
            continue
        except EOFError:
            break
        solution(s, n)


if __name__ == '__main__':
    main()
