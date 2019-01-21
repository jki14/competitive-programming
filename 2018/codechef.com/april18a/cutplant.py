def process():
    n = int(raw_input().strip())
    a = [int(i) for i in raw_input().strip().split()]
    b = [int(i) for i in raw_input().strip().split()]
    if len([i for i in xrange(n) if a[i]<b[i]])>0:
        return -1
    foo = 0
    prv = -1
    que = []
    for i in xrange(n):
        while len(que)>0 and que[0]>a[i]:
            que.pop(0)
        while len(que)>0 and que[-1]<b[i]:
            que.pop()
        if len(que)==0 or b[i]!=que[-1]:
            if a[i]!=b[i]:
                que.append(b[i])
                foo += 1
    return foo

def main():
    c = int(raw_input().strip())
    for i in xrange(c):
        print process()

if __name__ == '__main__':
    main()
