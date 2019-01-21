def minimumSum(seq):
    foo = 0
    seq = sorted(seq)
    p = 0
    i = (len(seq)+1)>>1
    while i>0:
        j = len(seq)-i+1
        foo += seq[p]*(i*j)
        print foo
        p += 1
        if i!=j:
            foo += seq[p]*(i*j)
            print foo
            p += 1
        i -= 1
    return foo

def main():
    n = int(raw_input().strip())
    a = [int(i) for i in raw_input().strip().split()]
    print minimumSum(a)

if __name__=='__main__':
    main()
