from sys import stdout


def solution(a):
    d = {}
    for entry in a:
        d[entry[0] + ' ' + entry[1]] = True
    stdout.write(('Yes' if len(d.keys()) < len(a) else 'No') + '\n')


def main():
    while True:
        try:
            n = int(raw_input().strip())
            a = [tuple([j for j in raw_input().strip().split()]) for i in xrange(n)]
            solution(a)
        except EOFError:
            break
        except ValueError:
            continue


if __name__ == '__main__':
    main()
