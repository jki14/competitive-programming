def possible(a):
    cntOdd = 0
    for i in a:
        if (i&1)==1:
            cntOdd += 1
    if (cntOdd&1)==0:
        return True
    else:
        return False

def main():
    n = (raw_input().strip())
    a = [int(i) for i in raw_input().strip().split()]
    if possible(a):
        print 'YES'
    else:
        print 'NO'

if __name__=='__main__':
    main()
