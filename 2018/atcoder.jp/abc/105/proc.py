def toBasen2(x, sign):
    foo = ''
    k = 1
    while k <= x:
        if (x & k) == k:
            foo += '1'
            if not sign:
                x += k
        else:
            foo += '0'
        k <<= 1
        sign = not sign
    if foo == '':
        foo = '0'
    return foo[::-1]

def main():
    x = int(raw_input())
    if x >= 0:
        print toBasen2(x, True)
    else:
        print toBasen2(-x, False)

if __name__ == '__main__':
    main()
