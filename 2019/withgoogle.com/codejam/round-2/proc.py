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
    return int(raw_input().strip())
  @staticmethod
  def getInts():
    return [int(i) for i in raw_input().strip().split()]
  @staticmethod
  def getFloat():
    return float(raw_input().strip())
  @staticmethod
  def getFloats():
    return [float(i) for i in raw_input().strip().split()]
  @staticmethod
  def getStr():
    return str(raw_input().strip())
  @staticmethod
  def getStrs():
    return [str(i) for i in raw_input().strip().split()]

class fraction_t:

  def __init__(self, num, den):
    d = fractions.gcd(num, den)
    self.num, self.den = num / d, den / d
    if self.den < 0:
      self.num *= -1
      self.den *= -1

  def __add__(self, rhs):
    return fraction_t(self.num + self.den * rhs, self.den)

  def __sub__(self, rhs):
    return fraction_t(self.num - self.den * rhs, self.den)

  def __lt__(self, rhs):
    return self.num * rhs.den < rhs.num * self.den

  def __le__(self, rhs):
    return self.num * rhs.den <= rhs.num * self.den

  def reciprocal(self):
    return fraction_t(self.den, self.num)

def unnamed(gt, lt):
  if gt.num == 0:
    return fraction_t(1, lt.den / lt.num + 1)
  if gt.num >= gt.den:
    mul = gt.num / gt.den
    return unnamed(gt - mul, lt - mul) + mul
  if fraction_t(1, 1) < lt:
    return fraction_t(1, 1)
  return unnamed(lt.reciprocal(), gt.reciprocal()).reciprocal()

def solution():
  n = joshu.getInt()
  seq = [tuple(joshu.getInts()) for i in xrange(n)]
  gt, lt = fraction_t(0, 1), fraction_t(1, 0)
  for i in xrange(n - 1):
    dc, dj = seq[i][0] - seq[i + 1][0], seq[i][1] - seq[i + 1][1]
    if dc * dj < 0:
      if dc < 0:
        gt = max(fraction_t(-dj, dc), gt)
      else:
        lt = min(fraction_t(-dj, dc), lt)
      if lt <= gt:
        return 'IMPOSSIBLE'
    elif dc > 0 or dj > 0:
      return 'IMPOSSIBLE'
  foo = unnamed(gt, lt)
  return '%d %d' % (foo.num, foo.den)

def main():
  case_num = joshu.getInt()
  for case_id in xrange(case_num):
    sys.stdout.write('Case #%d: %s\n' % (case_id + 1, solution()))

if __name__ == '__main__':
  main()
