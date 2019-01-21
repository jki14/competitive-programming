import matplotlib.pyplot as plt

def main():
    n = int(raw_input().strip())
    cx = [0 for i in xrange(n)]
    cy = [0 for i in xrange(n)]
    for i in xrange(n):
        cx[i], cy[i] = [int(j) for j in raw_input().strip().split()]
    plt.plot(cx, cy, 'b.')
    m = int(raw_input().strip())
    jx = [0 for i in xrange(m)]
    jy = [0 for i in xrange(m)]
    for i in xrange(m):
        jx[i], jy[i] = [int(j) for j in raw_input().strip().split()]
    plt.plot(jx, jy, 'r.')
    k = int(raw_input().strip())
    vx = [0 for i in xrange(k)]
    vy = [0 for i in xrange(k)]
    for i in xrange(k):
        vx[i], vy[i] = [int(j) for j in raw_input().strip().split()]
        if vx[i]<n:
            if vy[i]<n:
                plt.plot([cx[vx[i]], cx[vy[i]]], [cy[vx[i]], cy[vy[i]]], '#000000', alpha=0.1)
            else:
                plt.plot([cx[vx[i]], jx[vy[i]-n]], [cy[vx[i]], jy[vy[i]-n]], '#000000', alpha=0.1)
        else:
            if vy[i]<n:
                plt.plot([jx[vx[i]-n], cx[vy[i]]], [jy[vx[i]-n], cy[vy[i]]], '#000000', alpha=0.1)
            else:
                plt.plot([jx[vx[i]-n], jx[vy[i]-n]], [jy[vx[i]-n], jy[vy[i]-n]], '#000000', alpha=0.1)
    plt.show()

if __name__ == '__main__':
    main()
