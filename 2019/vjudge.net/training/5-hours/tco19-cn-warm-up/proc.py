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

tra = 'jki14-win'
mod = 1000000007

def rush(prv):
  cur = prv
  for c in tra:
    cur = (cur * 31 + ord(c)) % mod
  cur = cur * 7 % mod
  token = (cur + 9999999) / 10000000 * 10000000 - cur
  if token >= 1000000000:
    token = 140000000 + mod - cur
  sys.stdout.write('%s %d\n' % (tra, token))
  # sys.stderr.write('%s %d => %d\n' % (tra, token, (cur + token) % mod))
  return (cur + token) % mod

def solution(prv):
  prv = rush(prv)
  rush(prv)

def main():
  while True:
    try:
      foo = joshu.getStr()
      foo = int(foo)
      solution(foo)
    except EOFError:
      break
    except:
      continue

if __name__ == '__main__':
  main()
