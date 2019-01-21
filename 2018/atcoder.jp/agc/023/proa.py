def process():
    try:
        n = int(raw_input().strip())
    except ValueError:
        return True
    except EOFError:
        return False
    a = [int(i) for i in raw_input().strip().split()]
    s = {}
    s[0] = 1
    c = 0
    foo = 0
    for i in xrange(n):
        c += a[i]
        if c in s:
            foo += s[c]
            s[c] += 1
        else:
            s[c] = 1
    print foo
    return True

def main():
    while True:
        if not process():
            break
    
if __name__ == '__main__':
    main()
