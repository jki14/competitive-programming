from sys import stdout


def solution(a):
    n = len(a)
    a = [(a[i], i + 1) for i in xrange(n)]
    stdout.write("%d\n" % sorted(a)[-2][1])


def main():
    while True:
        try:
            n = int(raw_input().strip())
            a = [int(i) for i in raw_input().strip().split()]
            solution(a)
        except EOFError:
            break
        except ValueError:
            continue


if __name__ == '__main__':
    main()
