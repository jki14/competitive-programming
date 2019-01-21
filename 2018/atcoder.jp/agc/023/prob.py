def process():
    try:
        n = int(raw_input().strip())
    except ValueError:
        return True
    except EOFError:
        return False
    a = [raw_input().strip() for i in xrange(n)]
    foo = 0
    x = 0
    for y in xrange(n):
        sym = True
        for d in xrange(n):
            for k in xrange(1, n):
                if a[(x+d)%n][(y+d+k)%n]!=a[(x+d+k)%n][(y+d)%n]:
                    sym = False
                    break
            if not sym:
                break
        if sym:
            foo += 1
    print foo * n
    return True

def main():
    while True:
        if not process():
            break
    
if __name__ == '__main__':
    main()
