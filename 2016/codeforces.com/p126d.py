import sys

raw_input = sys.stdin.readline

def find_entry(x, pre):
    lef=0
    rig=len(pre)-1
    while lef<=rig:
        mid=(lef+rig)>>1
        if pre[mid]>=x:
            if mid==lef or pre[mid-1]<x:
                return mid
            else:
                rig=mid-1
        else:
            lef=mid+1
    return -1

def init(x, pre):
    y=find_entry(x, pre)
    if pre[y]==x:
        return (1<<(y+1))-1
    else:
        return ((1<<(y+1))-1)^init(pre[y]-x, pre)

def lowest(x):
    til=0
    while (1<<(til+1))<=x:
        til+=1
    for i in range(til, 1, -1):
        if (x&(1<<i))==0:
            continue
        if (x&(1<<(i-1)))==0 and (x&(1<<(i-2)))==0:
            x^=(1<<(i-1))
            x^=(1<<(i-2))
            x^=(1<<i)
    return x

def main_entry():

    fib=range(1,3)
    idx=2
    while True:
        cur=fib[idx-1]+fib[idx-2]
        if cur>1000000000000000000:
            break
        fib.append(cur)
        idx+=1

    pre=[0]*len(fib)
    pre[0]=fib[0]
    for i in range(1, len(pre)):
        pre[i]=pre[i-1]+fib[i]
    
    while True:
        try:
            t = int(raw_input())
        except ValueError:
            continue
        except EOFError:
            break
        
        while t>0:
            try:
                n = int(raw_input())
            except ValueError:
                continue
            except EOFError:
                break
            t-=1


            key=init(n, pre)
            key=lowest(key)
            m=0
            while (1<<m)<=key:
                m+=1
            f=[[0 for i in range(2)] for i in range(m+1)] 
            f[0][0]=1
            f[1][0]=1
        
            #for i in range(0, m):
            #    for j in range(0, 2):
            #        print 'f['+str(i)+']['+str(j)+']='+str(f[i][j])

            #print 'key='+str(key)
            for i in range(1, m):
                #print 'f['+str(i)+'][0]='+str(f[i][0])
                #print 'f['+str(i)+'][1]='+str(f[i][1])
                #f[i+1][1]
                if (key&(1<<i))!=0:
                    if (key&(1<<(i-1)))!=0:
                        f[i+1][1]+=f[i-1][0]+f[i-1][1]
                    else:
                        f[i+1][1]+=f[i-1][1]
                #f[i+1][0]
                if (key&(1<<i))!=0:
                    f[i+1][0]+=f[i][0]
                else:
                    f[i+1][0]+=f[i][0]+f[i][1]
                
            #print 'f['+str(m)+'][0]='+str(f[m][0])
            #print 'f['+str(m)+'][1]='+str(f[m][1])
            
            print f[m][0]+f[m][1]

        break


if __name__ == '__main__':
    main_entry()
