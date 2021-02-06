def solution(v, t, s, d):
    p, q = t * v, s * v
    if d >= p and d <= q:
        print('No')
    else:
        print('Yes')


def main():
    while True:
        try:
            v, t, s, d = [int(i) for i in raw_input().strip().split()]
            solution(v, t, s, d)
        except EOFError:
            break
        except ValueError:
            continue


if __name__ == '__main__':
    main()
