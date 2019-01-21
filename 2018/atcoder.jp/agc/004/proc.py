def recover(purple):
    h = len(purple)
    w = len(purple[0])
    red = []
    blue = []
    for i in xrange(h):
        if (i&1)==0:
            red.append(['#' for j in xrange(w-1)]+['.'])
            blue.append(['.' for j in xrange(w-1)]+['#'])
        else:
            red.append(['#']+['.' for j in xrange(w-1)])
            blue.append(['.']+['#' for j in xrange(w-1)])
        for j in xrange(w):
            if purple[i][j]=='#':
                red[i][j] = '#'
                blue[i][j] = '#'
    return red, blue

def main():
    h, w = [int(i) for i in raw_input().strip().split()]
    purple = []
    for i in xrange(h):
        purple.append(raw_input().strip())
    r, b = recover(purple)
    for line in r:
        print ''.join(line)
    print ''
    for line in b:
        print ''.join(line)

if __name__=='__main__':
    main()
