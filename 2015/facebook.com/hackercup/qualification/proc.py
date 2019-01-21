from sys import stdout
from Queue import Queue

class Position:
   
    def __init__(self, x, y):
        self.x, self.y = x, y
   
    def go(self, k):
        #todo: check if k is valid
        if k == 0:
            return Position(self.x - 1, self.y)
        elif k == 1:
            return Position(self.x, self.y + 1)
        elif k == 2:
            return Position(self.x + 1, self.y)
        else:
            return Position(self.x, self.y - 1)


class State:
    
    def __init__(self, position, k):
        self.position, self.k = position ,k
   

class Grids:
    
    def __init__(self, themap):
        self.h = len(themap)
        self.w = len(themap[0])
        self.themap = themap
        
    def size(self):
        return self.h, self.w
        
    def valid(self, position):
        if 0 <= position.x and position.x < self.h:
            if 0 <= position.y and position.y < self.w:
                return True
        return False

    def visitable(self, position):
        if self.valid(position):
            return self.themap[position.x][position.y] in ['S', 'G', '.']
        return False

    def goal(self, position):
        if self.themap[position.x][position.y] == 'G':
            return True
        return False

    def safe(self, state):
        for i in xrange(4):
            pos = state.position.go(i)
            while self.visitable(pos):
                pos = pos.go(i)
            if self.valid(pos) and self.themap[pos.x][pos.y] in ['^', '>', 'v', '<']:
                ori = (['^', '>', 'v', '<'].index(self.themap[pos.x][pos.y]) + state.k) % 4
                if ori == i^2:
                    return False
        return True


def solution(grids, s):
    #todo: check if all parameters are valid
    h, w = grids.size()
    f = [[[-1 for k in xrange(4)] for j in xrange(w)] for i in xrange(h)]
    q = Queue()
    f[s.x][s.y][0] = 0
    q.put(State(s, 0))
    while not q.empty():
        state = q.get()
        for i in xrange(4):
            next_state = State(state.position.go(i), (state.k + 1) % 4)
            if grids.visitable(next_state.position) and f[next_state.position.x][next_state.position.y][next_state.k] == -1 and grids.safe(next_state):
                f[next_state.position.x][next_state.position.y][next_state.k] = f[state.position.x][state.position.y][state.k] + 1
                if grids.goal(next_state.position):
                    return f[next_state.position.x][next_state.position.y][next_state.k]
                q.put(next_state)
    return -1

def main():
    case_num = int(raw_input().strip())
    for case_id in xrange(1, case_num + 1):
        h, w = [int(i) for i in raw_input().strip().split()]
        themap = [raw_input().strip() for i in xrange(h)]
        s = Position(-1, -1)
        for x in xrange(h):
            for y in xrange(w):
                if themap[x][y] == 'S':
                    s.x, s.y = x, y
                    break
            if s.x >= 0:
                break
        foo = solution(Grids(themap), s)
        if foo >= 0:
            stdout.write('Case #%d: %d\n' % (case_id, foo))
        else:
            stdout.write('Case #%d: impossible\n' % (case_id))
        stdout.flush()

if __name__ == '__main__':
    main()
