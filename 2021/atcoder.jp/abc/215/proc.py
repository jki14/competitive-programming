from sys import stdout


def iterate(bar, pool, foo):
    if pool == '':
        foo[bar] = True
        return
    for i in xrange(0, len(pool)):
        iterate(bar + pool[i], pool[:i] + pool[i + 1:], foo)


def solution(s, k):
    foo = {}
    iterate('', s, foo)
    foo = sorted(foo.keys())
    stdout.write('%s\n' % foo[k - 1])


def main():
    while True:
        try:
            s, k = [i for i in raw_input().strip().split()]
            k = int(k)
            solution(s, k)
        except EOFError:
            break
        except ValueError:
            continue


if __name__ == '__main__':
    main()
