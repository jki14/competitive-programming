# -*- coding: utf-8 -*-
import array
import bisect
import collections
import fractions
import heapq
import itertools
import math
import re
import string
import sys

class joshu:

    # stdio
    @staticmethod
    def getInt():
        return int(input().strip())
    @staticmethod
    def getInts():
        return [int(i) for i in input().strip().split()]
    @staticmethod
    def getFloat():
        return float(input().strip())
    @staticmethod
    def getFloats():
        return [float(i) for i in input().strip().split()]
    @staticmethod
    def getStr():
        return str(input().strip())
    @staticmethod
    def getStrs():
        return [str(i) for i in input().strip().split()]

class foo_t:
    def __init__(self, k):
        self.bar = []
        self.rem = k
    def append(self, op):
        if self.rem == 0 or op[0] == 0:
            return
        cst = len(op[1])
        wht = op[0] * cst
        if wht <= self.rem:
            self.bar.append(op)
            self.rem -= wht
        else:
            k = self.rem // cst
            if k > 0:
                self.bar.append((k, op[1]))
                self.rem -= k * cst
            if self.rem > 0:
                self.bar.append((1, op[1][:self.rem]))
                self.rem = 0

def solution(n, m, k):
    if k > 4 * n * m - 2 *n - 2 * m:
        sys.stdout.write('NO\n')
        return
    foo = foo_t(k)
    foo.append((m - 1, 'R'))
    foo.append((m - 1, 'L'))
    for i in range(1, n):
        foo.append((1, 'D'))
        foo.append((m - 1, 'RUD'))
        foo.append((m - 1, 'L'))
    foo.append((n - 1, 'U'))
    sys.stdout.write('YES\n')
    sys.stdout.write('%d\n' % (len(foo.bar)))
    for row in foo.bar:
        sys.stdout.write('%d %s\n' % row)

def main():
    while True:
        try:
            n, m, k  = joshu.getInts()
            solution(n, m, k)
        except ValueError:
            continue
        except EOFError:
            break

if __name__ == '__main__':
    main()
