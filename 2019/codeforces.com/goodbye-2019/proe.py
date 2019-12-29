import sys

def solution():
    n = int(input().strip())
    a = [tuple(int(j) for j in input().strip().split()) for i in range(n)]
    if n == 2:
        sys.stdout.write('%d\n%d\n' % (1, 1))
        return
    foo = {}
    for i in range(n):
        for j in range(i + 1, n):
            v = (a[i][0] - a[j][0]) ** 2 + (a[i][1] - a[j][1]) ** 2
            if v not in foo:
                foo[v] = {}
            if i not in foo[v]:
                foo[v][i] = True
            else:
                foo[v][i] = False
            if j not in foo[v]:
                foo[v][j] = True
            else:
                foo[v][j] = False
    for i in range(n):
        for j in range(i + 1, n):
            v = (a[i][0] - a[j][0]) ** 2 + (a[i][1] - a[j][1]) ** 2
            if foo[v][i] and foo[v][j]:
                sys.stdout.write('%d\n%d %d\n' % (2, i + 1, j + 1))
                return

def main():
    solution()

if __name__ == '__main__':
    main()
