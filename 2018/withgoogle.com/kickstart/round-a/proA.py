def EvenDigits(n):
    strn = str(n)
    lenn = len(strn)
    #
    a = ['0' for i in xrange(lenn+1)]
    for i in xrange(lenn):
        if (ord(strn[i]) - ord('0')) & 1 == 1:
            if strn[i] != '9':
                a[i + 1] = chr(ord(strn[i]) + 1)
            else:
                a[i + 1] = '0'
                while a[i] == '8':
                    a[i] = '0'
                    i -= 1
                a[i] = chr(ord(a[i]) + 2)
            break
        else:
            a[i + 1] = strn[i]
    foo = int(''.join(a)) - n
    #
    b = ['8' for i in xrange(lenn)]
    for i in xrange(lenn):
        if (ord(strn[i]) - ord('0')) & 1 == 1:
            b[i] = chr(ord(strn[i]) - 1)
            break
        else:
            b[i] = strn[i]
    foo = min(n - int(''.join(b)), foo)
    return foo

def main():
    c = int(raw_input().strip())
    for i in xrange(c):
        n = int(raw_input().strip())
        print 'Case #%d: %d' % (i+1, EvenDigits(n))

if __name__ == '__main__':
    main()
