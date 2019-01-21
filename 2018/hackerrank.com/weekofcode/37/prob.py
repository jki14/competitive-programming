def main():
    n = int(raw_input().strip())
    x = 0
    for i in xrange(n):
        raw = raw_input().strip().split()
        opt = str(raw[0])
        rhs = int(raw[1])
        if opt[0]=='a':
            if rhs>0:
                x += rhs
        else:
            if rhs>x:
                x = rhs
    print x 

if __name__ == '__main__':
    main()
