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

def solution(ss):
    n = len(ss[0])
    for i in range(n):
        if ss[0][i] != ss[2][i] and ss[1][i] != ss[2][i]:
            return False
    return True

def main():
    case_num = joshu.getInt()
    for case_id in range(case_num):
        ss = [joshu.getStr() for i in range(3)]
        if solution(ss):
            sys.stdout.write('YES\n')
        else:
            sys.stdout.write('NO\n')

if __name__ == '__main__':
    main()
