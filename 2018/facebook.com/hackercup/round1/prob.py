from sys import stdout
from sys import setrecursionlimit

class TreeNode:

    def __init__(self, label):
        self.label = label
        self.child = [None, None]

    def pre_order_traversal(self):
        foo = [self.label]
        if self.child[0] is not None:
            foo += self.child[0].pre_order_traversal()
        if self.child[1] is not None:
            foo += self.child[1].pre_order_traversal()
        return foo

    def post_order_traversal(self):
        foo = []
        if self.child[0] is not None:
            foo += self.child[0].post_order_traversal()
        if self.child[1] is not None:
            foo += self.child[1].post_order_traversal()
        foo.append(self.label)
        return foo

def find(u, f):
    if f[u] != u:
        f[u] = find(f[u], f)
    return f[u]

def solution(root, k):
    pre_seq = root.pre_order_traversal()
    post_seq = root.post_order_traversal()
    n = len(pre_seq) 
    f = [i for i in xrange(n)]
    for i in xrange(n):
        f[find(pre_seq[i], f)] = find(post_seq[i], f)
    c = [0 for i in xrange(n)]
    p = 0
    for i in xrange(n):
        if c[i] == 0:
            if c[find(i, f)] == 0:
                c[find(i, f)] = (p % k) + 1
                p += 1
            c[i] = c[find(i, f)]
    if p < k:
        return 'Impossible'
    else:
        return ' '.join([str(i) for i in c])

def main():
    setrecursionlimit(2048)
    caseNum = int(raw_input().strip())
    for caseId in xrange(caseNum):
        n, k = [int(i) for i in raw_input().strip().split()]
        nodes = [TreeNode(i) for i in xrange(n)]
        for u in xrange(n):
            lef, rig = [int(i) for i in raw_input().strip().split()]
            if lef != 0:
                nodes[u].child[0] = nodes[lef - 1]
            if rig != 0:
                nodes[u].child[1] = nodes[rig - 1]
        stdout.write('Case #%d: %s\n' % (caseId + 1, solution(nodes[0], k)))
        stdout.flush()

if __name__ == '__main__':
    main()
