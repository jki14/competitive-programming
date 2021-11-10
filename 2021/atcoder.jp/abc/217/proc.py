from sys import stdout


def solution(p):
    q = [0] * len(p)
    for i in xrange(len(p)):
        q[p[i] - 1] = i + 1
    stdout.write(' '.join([str(i) for i in q]) + '\n')


def main():
    while True:
        try:
            n = int(raw_input().strip())
            p = [int(i) for i in raw_input().strip().split()]
            solution(p)
        except EOFError:
            break
        except ValueError:
            continue


if __name__ == '__main__':
    main()
