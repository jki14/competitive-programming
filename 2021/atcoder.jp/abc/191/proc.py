import sys


def count(a, h ,w):
    foo = 0
    for i in xrange(h - 1):
        bar = ''.join(['#' if a[i][j] != a[i + 1][j] else ' ' for j in xrange(w)])
        # sys.stderr.write('%s\n' % bar)
        foo += len(bar.split())
    # sys.stderr.write('%d\n' % foo)
    return foo


def solution(a, h, w):
    foo = 0
    foo += count(a, h, w)
    b = [[a[j][i] for j in xrange(h)] for i in xrange(w)]
    foo += count(b, w, h)
    print(foo)


def main():
    while True:
        try:
            h, w = [int(i) for i in raw_input().strip().split()]
            a = [raw_input().strip() for i in xrange(h)]
            solution(a, h, w)
        except EOFError:
            break
        except ValueError:
            continue


if __name__ == '__main__':
    main()
