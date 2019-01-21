from sys import stdout

class Calories:
    
    def __init__(self, p=0, c=0, f=0):
        self.p, self.c, self.f = p, c, f

    def add(self, rhs):
        self.p += rhs.p
        self.c += rhs.c
        self.f += rhs.f
        
    def compareTo(self, rhs):
        if self.p == rhs.p and self.c == rhs.c and self.f == rhs.f:
            return 0
        if self.p > rhs.p or self.c > rhs.c or self.f > rhs.f:
            return 1
        return -1


def solution(goal, foods):
    n = len(foods)
    for k in xrange(1 << n):
        current = Calories()
        for i in xrange(n):
            if (k >> i) & 1 == 1:
                current.add(foods[i])
                tmp = current.compareTo(goal)
                if tmp == 0:
                    return True
                elif tmp > 0:
                    break
    return False

def main():
    case_num = int(raw_input().strip())
    for case_id in xrange(1, case_num + 1):
        goal = Calories()
        goal.p, goal.c, goal.f = [int(i) for i in raw_input().strip().split()]
        n = int(raw_input().strip())
        foods = [Calories() for i in xrange(n)]
        for el in foods:
            el.p, el.c, el.f = [int(i) for i in raw_input().strip().split()]
        if solution(goal, foods):
            stdout.write('Case #%d: yes\n' % case_id)
        else:
            stdout.write('Case #%d: no\n' % case_id)
        stdout.flush()

if __name__ == '__main__':
    main()
