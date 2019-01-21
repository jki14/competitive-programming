for k in range(2, 1001):
    flag = False
    n = 1
    while flag==False and n <= 50:
        m = 1
        while flag==False and m <= 50:
            red = (((n+1)/2*m+n/2)-(k+1))
            if (n+1)/2*m+n/2>=k+1 and red%2==0 and ((m-1)-(m+1)/2)*(n/2)>=red/2:
                print str(n)+' * '+str(m)+' - '+str(red)+' '+str(k)
                flag = True
                break
            m += 1
        n += 4
    if flag==False:
        print 'Error '+str(k)
