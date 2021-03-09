def solution(a, x):
    foo = [str(i) for i in a if i != x]
    bar = ' '.join(foo)
    print(bar)


def main():
    while True:
        try:
            n, x = [int(i) for i in raw_input().strip().split()]
            a = [int(i) for i in raw_input().strip().split()]
            solution(a, x)
        except EOFError:
            break
        except ValueError:
            continue


if __name__ == '__main__':
    main()
