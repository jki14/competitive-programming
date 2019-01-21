from random import randint
from sys import stdout
from sys import stderr

class Treap:

    class _TreapNode:

        def __init__(self, key, value):
            self.key = key
            self.value = value
            self.score = randint(0, 2147483647)
            self.child = [None, None]
            self.parent = None
            self.update()

        def update(self):
            self.nsize = 1
            self.height = 1
            # customized
            self.numvl = self.value
            self.total = self.key * self.value
            for i in xrange(2):
                if self.child[i] is not None:
                    self.child[i].parent = self
                    self.nsize += self.child[i].nsize
                    self.height = max(self.child[i].height + 1, self.height)
                    # customized
                    self.numvl += self.child[i].numvl
                    self.total += self.child[i].total

        def rotate(self, raise_child_id):
            node = self.child[raise_child_id]
            temp = node.child[raise_child_id ^ 1]
            node.child[raise_child_id ^ 1] = self
            self.child[raise_child_id] = temp
            self.update()
            node.update()
            return node

        def insert(self, key, value):
            if key < self.key:
                if self.child[0] is not None:
                    self.child[0] = self.child[0].insert(key, value)
                else:
                    self.child[0] = self.__class__(key, value)
                if self.child[0] is not None and self.child[0].score > self.score:
                    return self.rotate(0)
            elif key > self.key:
                if self.child[1] is not None:
                    self.child[1] = self.child[1].insert(key, value)
                else:
                    self.child[1] = self.__class__(key, value)
                if self.child[1] is not None and self.child[1].score > self.score:
                    return self.rotate(1)
            else:
                self.value += value
                if self.value == 0:
                    return self.delete()
            self.update()
            return self

        def delete(self):
            if self.child[0] is not None:
                if self.child[1] is not None and self.child[1].score > self.child[0].score:
                    node = self.rotate(1)
                    node.child[0] = self.delete()
                    node.update()
                    return node
                else:
                    node = self.rotate(0)
                    node.child[1] = self.delete()
                    node.update()
                    return node
            else:
                if self.child[1] is not None:
                    node = self.rotate(1)
                    node.child[0] = self.delete()
                    node.update()
                    return node
                else:
                    self.parent = None
                    return None

        def prev(self):
            if self.child[0] is not None:
                node = self.child[0]
                while node.child[1] is not None:
                    node = node.child[1]
                return node
            else:
                node = self
                while node.parent is not None:
                    if node.parent.child[1] is node:
                        return node.parent
                    else:
                        node = node.parent
                return None

        def next(self):
            if self.child[1] is not None:
                node = self.child[1]
                while node.child[0] is not None:
                    node = node.child[0]
                return node
            else:
                node = self
                while node.parent is not None:
                    if node.parent.child[0] is node:
                        return node.parent
                    else:
                        node = node.parent
                return None

        def first(self):
            node = self
            while node.child[0] is not None:
                node = node.child[0]
            return node

        def last(self):
            node = self
            while node.child[1] is not None:
                node = node.child[1]
            return node

        def __str__(self):
            foo = ''
            if self.child[0] is not None:
                foo += '(' + self.child[0].__str__() + ')'
            foo += '<%d, %d, %d, %d>' % (self.key, self.value, self.numvl, self.total)
            if self.child[1] is not None:
                foo += '(' + self.child[1].__str__() + ')'
            return foo

    def __init__(self):
        self.root = None

    def get_first(self):
        if self.root is not None:
            return self.root.first()
        else:
            return None

    def get_last(self):
        if self.root is not None:
            return self.root.last()
        else:
            return None

    def insert(self, key, value):
        if self.root is not None:
            self.root = self.root.insert(key, value)
        else:
            self.root = self._TreapNode(key, value)

    def lower_bound(self, key):
        node = self.root
        while node is not None:
            if key > node.key:
                node = node.child[1]
            elif key < node.key:
                if node.child[0] is None or key > node.child[0].last().key:
                    break
                node = node.child[0]
            else:
                break
        return node

    def __str__(self):
        if self.root is not None:
            return self.root.__str__()
        else:
            return 'nil'

    def __len__(self):
        if self.root is not None:
            return self.root.nsize
        else:
            return 0

class Monster:
    def __init__(self, x, y):
        self.x, self.y = x, y

def SafeSquares(r, c, monsters):
    mir = [[] for i in xrange(r)]
    for monster in monsters:
        mir[monster.x].append(monster.y)
    foo = 0
    for b in xrange(r):
        pots = Treap()
        pots.insert(-1, 1)
        pots.insert(c, 1)
        segs = Treap()
        segs.insert(c, 1)
        for i in xrange(b, r):
            for y in mir[i]:
                node = pots.lower_bound(y)
                x = node.prev().key
                z = node.key
                segs.insert(z - x - 1, -1)
                if y - x - 1 > 0:
                    segs.insert(y - x - 1, 1)
                if z - y - 1 > 0:
                    segs.insert(z - y - 1, 1)
                pots.insert(y, 1)
            edgl = i - b + 1
            node = segs.root
            if node is not None:
                numvl = node.numvl
                total = node.total
                while node is not None:
                    #print('node.key = %d' % (node.key))
                    if edgl < node.key:
                        node = node.child[0]
                    elif edgl > node.key:
                        numvl -= node.numvl
                        total -= node.total
                        if node.child[1] is not None:
                            numvl += node.child[1].numvl
                            total += node.child[1].total
                        node = node.child[1]
                    else:
                        if node.child[0] is not None:
                            numvl -= node.child[0].numvl
                            total -= node.child[0].total
                        break
                    #print('total = %d, numvl = %d' % (total, numvl))
                #print('%d - %d, edgl = %d' % (b, i, edgl))
                #print(pots)
                #print(segs)
                #print('total = %d, numvl = %d, contribution = %d' % (total, numvl, total - numvl * (edgl - 1)))
                foo += total - numvl * (edgl - 1)
        stderr.write('pots.nsize = %d, pots.height = %d\n' % (pots.root.nsize, pots.root.height))
        stderr.write('segs.nsize = %d, segs.height = %d\n' % (segs.root.nsize, segs.root.height))
        stderr.flush()
    return foo

def main():
    caseNum = int(raw_input().strip())
    for caseId in xrange(caseNum):
        r, c, k = [int(i) for i in raw_input().strip().split()]
        monsters = []
        for i in xrange(k):
            x, y = [int(i) for i in raw_input().strip().split()]
            monsters.append(Monster(x, y))
        print('Case #%d: %d' % (caseId + 1, SafeSquares(r, c, monsters)))
        stdout.flush()

if __name__ == '__main__':
    main()
