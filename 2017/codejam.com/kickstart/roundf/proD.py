from collections import deque

def EatCake(n):
    #TODO: check if n is valid (integer > 0)
    cache = [None for i in xrange(n + 1)]
    que = deque()
    cache[0] = 0
    que.append(0)
    while que:
        cur = que.popleft()
        length = 1
        nxt = cur + length ** 2
        while nxt <= n:
            if  cache[nxt] is None:
                cache[nxt] = cache[cur] + 1
                if nxt != n:
                    que.append(nxt)
                else:
                    return cache[n]
            length += 1
            nxt = cur + length ** 2

def main():
    c = int(raw_input().strip())
    for i in xrange(c):
        n = int(raw_input().strip())
        print('Case #%d: %d' % (i + 1, EatCake(n)))

if __name__ == '__main__':
    main()
