from sys import stdout


def solution(n):
    opta = []
    while n > 0:
        if (n & 1) == 1:
            opta.append(True)
        opta.append(False)
        n >>= 1
    bar = ''.join('A' if k else 'B' for k in reversed(opta))
    stdout.write(bar + '\n')


def main():
    while True:
        try:
            n = int(raw_input().strip())
            solution(n)
        except EOFError:
            break
        except ValueError:
            continue


if __name__ == '__main__':
    main()
