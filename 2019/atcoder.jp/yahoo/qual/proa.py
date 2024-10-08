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
  n, k = joshu.getInts()
  if (n + 1) / 2 >= k:
    print('YES')
  else:
    print('NO')

if __name__ == '__main__':
  main()
