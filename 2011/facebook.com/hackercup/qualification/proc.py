from sys import stdout

class Substring:
    
    def __init__(self, content):
        self.content = content

    def __cmp__(self, rhs):
        lho = self.content + rhs.content
        rho = rhs.content + self.content
        if lho != rho:
            if lho < rho:
                return -1
            else:
                return 1
        else:
            return 0

def solution(words):
    #todo: check if words is valid
    a = [Substring(i) for i in words]
    a = sorted(a)
    foo = ''
    for el in a:
        foo += el.content
    return foo

def main():
    case_num = int(raw_input().strip())
    for case_id in xrange(1, case_num + 1):
        row = [i for i in raw_input().strip().split()]
        stdout.write('Case #%d: %s\n' % (case_id, solution(row[1:])))
        stdout.flush()

if __name__ == '__main__':
    main()
