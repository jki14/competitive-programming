def getPermutation(n, x):
    if x==1 or x==n*2-1:
        return None
    if n==2:
        return [1, 2, 3]
    if x==2:
        bar = [x+1, x-1, x, x+2]
    else:
        bar = [x-1, x+1, x, x-2]
    rem = [i for i in xrange(1, n*2) if i not in bar]
    return rem[:n-2]+bar+rem[n-2:]

def main():
    n, x = [int(i) for i in raw_input().strip().split()]
    res = getPermutation(n, x)
    if res is None:
        print 'No'
    else:
        print 'Yes'
        for i in res:
            print i

if __name__ == '__main__':
    main()
