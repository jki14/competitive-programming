from sys import stderr, stdout

def solution(n, p, a):
    p = [p[i] - 1 for i in range(n)]

    v = [False for i in range(n)]
    s = [0 for i in range(n)]
    for i in range(n):
        m = 0
        j = i
        while v[j] == False:
            v[j] = True
            s[m] = a[j]
            m += 1
            j = p[j]
        if m > 1:
            d = min([(s[k], k) for k in range(m)])[1]
            j = i
            for k in s[d : m] + s[0 : d]:
                a[j] = k
                j = p[j]
    
    stdout.write(' '.join([str(i) for i in a]))
    stdout.write('\n')
        


def main():
    while True:
        try:
            n = int(input().strip())
        except EOFError:
            break
        p = [int(i) for i in input().strip().split()]
        a = [int(i) for i in input().strip().split()]
        while len(p) != n:
            pass
        while len(a) != n:
            pass
        solution(n, p, a)
        break


if __name__ == '__main__':
    main()
