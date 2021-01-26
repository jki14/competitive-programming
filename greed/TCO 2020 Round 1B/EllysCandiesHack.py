import os

def urandom32(low, hig):
    foo = int(os.urandom(4).encode('hex'), 16)
    foo %= hig - low + 1
    foo += low
    return foo

def main():
    print(','.join([str(urandom32(1, 1000)) for i in xrange(20)]))

if __name__ == '__main__':
    main()
