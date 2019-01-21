
def main():
    try:
        n, c = [int(i) for i in raw_input().strip().split()]
    except ValueError:
        return True
    except EOFError:
        return False
    d = [0 for i in xrange(n)]
    w = [0 for i in xrange(n)]
    for i in xrange(n):
        d[i], w[i] = [int(j) for j in raw_input().strip().split()]
    tot = sum(w)
    foo = 0
    foo = max(foo, tot-d[-1])
    foo = max(foo, tot-c+d[0])
    # <>>
    presum = 0
    suffix = tot
    prefer = 0
    for k in xrange(n-1):
        presum += w[k]
        prefer = max(prefer, presum - d[k])
        suffix -= w[k]
        foo = max(foo, prefer)
        tmp = c - d[k+1]
        foo = max(foo, prefer + suffix - tmp - tmp)
    # ><<
    presum = 0
    suffix = tot
    prefer = 0
    for k in xrange(n-1, 0, -1):
        presum += w[k]
        prefer = max(prefer, presum - (c - d[k]))
        suffix -= w[k]
        foo = max(foo, prefer)
        tmp = d[k-1]
        foo = max(foo, prefer + suffix - tmp - tmp)
    print foo
    return True
    
if __name__ == '__main__':
    while True:
        if not main():
            break
