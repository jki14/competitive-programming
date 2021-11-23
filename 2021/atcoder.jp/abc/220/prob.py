from sys import stdout


def calc(x, k):
    foo = 0
    for c in x:
        foo *= k
        foo += int(c)
    return foo


def solution(a, b, k):
    lhs, rhs = calc(a, k), calc(b, k)
    stdout.write('%d\n' % (lhs * rhs))


def main():
    while True:
        try:
            k = int(raw_input().strip())
            a, b = [i for i in raw_input().strip().split()]
            solution(a, b, k)
        except EOFError:
            break
        except ValueError:
            continue


if __name__ == '__main__':
    main()
