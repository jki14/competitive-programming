from sys import stdout


def solution(r, s, t):
    foo = {r: True, s: True, t: True}
    for k in ['ABC', 'ARC', 'AGC', 'AHC']:
        if k not in foo:
            stdout.write(k + '\n')
            return


def main():
    while True:
        try:
            r = raw_input().strip()
            s = raw_input().strip()
            t = raw_input().strip()
            solution(r, s, t)
        except EOFError:
            break
        except ValueError:
            continue


if __name__ == '__main__':
    main()
