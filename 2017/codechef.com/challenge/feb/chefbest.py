
def run():
    n = int(raw_input())
    a = [int(ai) for ai in raw_input().split()]
    res = 0
    #print a
    while True:
        flag = True
        for i in xrange(len(a)-1):
            if a[i]==0 and a[i+1]==1:
                flag = False
                a[i]=1
                a[i+1]=2
        if flag:
            break
        for i in xrange(len(a)):
            if a[i]==2:
                a[i]=0
        #print a
        res += 1
    #print a
    print res

T = int(raw_input())
for i in xrange(T):
    run()
