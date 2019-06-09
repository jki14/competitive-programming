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

def solution(es):
  foo = [0 for i in xrange(366)]
  for e in es:
    fr = e[0]
    to = e[1] + 1
    foo[fr : to] = [1 for i in xrange(fr, to)]
  return sum(foo)

def main():
  while True:
    try:
      n = joshu.getInt()
      e = [tuple(joshu.getInts()) for i in xrange(n)]
      sys.stdout.write('%d\n' % solution(e))
    except:
      break

if __name__ == '__main__':
  main()
