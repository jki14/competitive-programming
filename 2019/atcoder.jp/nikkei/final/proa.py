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

def main():
  n = joshu.getInt()
  a = joshu.getInts()
  b = a
  print(max(b))
  for d in xrange(1, n):
    b = [b[i] + a[i + d] for i in xrange(len(b) - 1)]
    print(max(b))

if __name__ == '__main__':
  main()
