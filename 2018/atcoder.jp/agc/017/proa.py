def combination(total, selected):
    foo = 1
    for i in xrange(selected):
        foo *= total-i
        foo /= i+1
    return foo

def process(a, p):
    odds = 0
    even = 0
    for x in a:
        if (x%2)==0:
            even += 1
        else:
            odds += 1
    foo = 0
    for i in xrange(p, odds+1, 2):
        foo += combination(odds, i)
    foo *= 1<<even
    return foo

def main():
    n, p = [int(x) for x in raw_input().strip().split()]
    a = [int(x) for x in raw_input().strip().split()]
    print process(a, p)

if __name__ == '__main__':
    main()
