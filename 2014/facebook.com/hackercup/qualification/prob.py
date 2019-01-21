from sys import stdout
from sys import stderr

class Player:
 
    def __init__(self, name, shot, height):
        self.name, self.shot, self.height = name, shot, height
 
    def __lt__(self, rhs):
        if self.shot > rhs.shot or (self.shot == rhs.shot and self.height > rhs.height):
            return True
        return False


class Pair:

    def __init__(self, first ,second):
        self.first, self.second = first, second

def subsolution(players, m, p, foo):
    n = len(players)
    inarena = [False for i in xrange(n)]
    played = [0 for i in xrange(n)]
    for i in xrange(p):
        inarena[i] = True
    for k in xrange(m):
        for i in xrange(n):
            if inarena[i]:
                played[i] += 1
        p, q = -1, -1
        for i in xrange(n - 1, -1, -1):
            if inarena[i] and (p == -1 or played[i] > played[p]):
                p = i
        for i in xrange(n):
            if not inarena[i] and (q == -1 or played[i] < played[q]):
                q = i
        inarena[p] = False
        inarena[q] = True
    for i in xrange(n):
        if inarena[i]:
            foo.append(players[i].name)

def solution(players, m, p):
    players = sorted(players)
    foo = []
    subsolution(players[::2], m, p, foo)
    subsolution(players[1::2], m, p, foo)
    foo = sorted(foo)
    return foo

def main():
    case_num = int(raw_input().strip())
    for case_id in xrange(1, case_num + 1):
        n, m, p = [int(i) for i in raw_input().strip().split()]
        players = [Player('', 0, 0) for i in xrange(n)]
        for el in players:
            el.name, el.shot, el.height = [i for i in raw_input().strip().split()]
            el.shot = int(el.shot)
            el.height = int(el.height)
        foo = solution(players, m, p)
        stdout.write('Case #%d: %s\n' % (case_id, ' '.join(foo)))
        stdout.flush()

if __name__ == '__main__':
    main()
