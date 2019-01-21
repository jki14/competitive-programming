def GoogolString(k):
    #TODO: check if k is valid
    length = 0
    while length < k:
        length = length * 2 + 1
    foo = 0
    while True:
        mid = (length + 1) / 2
        if k == mid:
            return foo
        elif k < mid:
            pass
        else:
            k = length - k + 1
            foo ^= 1
        length = (length - 1) / 2

def main():
    c = int(raw_input().strip())
    for i in xrange(c):
        k = int(raw_input().strip())
        print('Case #%d: %d' % (i + 1, GoogolString(k)))

if __name__ == '__main__':
    main()
