def generate(p):
    n = len(p)
    a = [n*i+1 for i in xrange(n)]
    b = a[::-1]
    for i in xrange(n):
        a[p[i]-1] += i
    return a, b

def main():
    n = int(raw_input().strip())
    p = [int(x) for x in raw_input().strip().split()]
    a, b = generate(p)
    print ' '.join([str(x) for x in a])
    print ' '.join([str(x) for x in b])

if __name__ == '__main__':
    main()
