from sys import stdout


def lb(x):
    bar = [0, 40, 70, 90]
    for i in xrange(len(bar) - 1):
        if x >= bar[i] and x < bar[i + 1]:
            return str(bar[i + 1] - x)
    return 'expert'


def solution(x):
    stdout.write(lb(x) + '\n')


def main():
    while True:
        try:
            x = int(raw_input().strip())
            solution(x)
        except EOFError:
            break
        except ValueError:
            continue


if __name__ == '__main__':
    main()
