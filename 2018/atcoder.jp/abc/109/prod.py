def solution(a):
    foo = []
    r = len(a)
    c = len(a[0])
    for i in xrange(r):
        for j in xrange(c):
            if a[i][j] & 1 == 1:
                if j != c - 1:
                    foo.append((i + 1, j + 1, i + 1, j + 2))
                    a[i][j] -= 1
                    a[i][j + 1] += 1
                elif i != r - 1:
                    foo.append((i + 1, j + 1, i + 2, j + 1))
                    a[i][j] -= 1
                    a[i + 1][j] += 1
    return foo

def main():
    r, c = [int(i) for i in raw_input().strip().split()]
    a = [[int(j) for j in raw_input().strip().split()] for i in xrange(r)]
    foo = solution(a)
    print(len(foo))
    for row in foo:
        print('%d %d %d %d' % row)

if __name__ == '__main__':
    main()
