from sys import stdout


def solution(s):
    stdout.write('%s\n' % ('AC' if s == 'Hello,World!' else 'WA'))


def main():
    while True:
        try:
            s = raw_input().strip()
            solution(s)
        except EOFError:
            break
        except ValueError:
            continue


if __name__ == '__main__':
    main()
