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

class EncloseArea:
    def __init__(self):
        self.foo = None
    def check(self, x, y):
        if x < 0 or x >= 50 or y < 0 or y >= 50:
            return False
        return self.foo[x][y]
    def enclose(self, s):
        if s % 2 == 1:
            return tuple()
        self.foo = [[False for j in xrange(50)] for i in xrange(50)]
        s >>= 1
        for d in xrange(0, 49, 2):
            for i in xrange(0, 49 - d):
                j = i + d
                if s > 0:
                    self.foo[i][j] = True
                    s -= 1
        for d in xrange(-2, -49, -2):
            for i in xrange(-d, 49):
                j = i + d
                if s > 0:
                    self.foo[i][j] = True
                    s -= 1
        if s > 0:
            return tuple()
        bar = [['.' for j in xrange(50)] for i in xrange(50)]
        for d in xrange(-48, 50, 2):
            for x in xrange(max(-d, 0), min(50 - d, 50)):
                y = x + d
                if self.check(x, y) != self.check(x - 1, y - 1):
                    bar[x][y] = '/'
        for d in xrange(-49, 50, 2):
            for x in xrange(max(-d, 0), min(50 - d, 50)):
                y = x + d
                if self.check(x, y - 1) != self.check(x - 1, y):
                    bar[x][y] = '\\'
        return tuple([''.join(row) for row in bar])
