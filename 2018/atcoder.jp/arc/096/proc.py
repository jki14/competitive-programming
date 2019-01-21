
def main():
    a, b, c, x, y = [int(i) for i in raw_input().strip().split()]
    foo = x * a + b * y
    for k in xrange(max(x, y)+1):
        foo = min(foo, (k * c * 2) + (max(x-k, 0) * a) + (max(y-k, 0) * b))
    print foo
    
if __name__ == '__main__':
    main()
