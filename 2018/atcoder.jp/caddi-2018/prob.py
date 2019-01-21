def firstwin(a):
    odd = 0
    for x in a:
        if (x & 1) == 1:
            return True
    return False

def main():
    n = int(raw_input().strip())
    a = [int(raw_input().strip()) for i in xrange(n)]
    if firstwin(a):
        print 'first'
    else:
        print 'second'

if __name__ == '__main__':
    main()
