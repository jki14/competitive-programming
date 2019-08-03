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

inf = 0x3f3f3f3f

class RealWithRooks:
  def construct(self, h, w, n):
    foo = self.solution(h, w, n)
    return tuple([''.join(bar) for bar in foo])
  def solution(self, h, w, n):
    foo = [['.' for j in xrange(w)] for i in xrange(h)]
    cur = (inf, inf)
    for y in xrange(1, w + 1):
      x = (n + y - 1) / y
      if x > h:
        continue
      if cur[0] + cur[1] > x + y:
        cur = (x, y)
    cheat = ['W', 'B']
    for i in xrange(cur[0]):
      for j in xrange(cur[1]):
        if n > 0:
          foo[i][j] = cheat[(i + j) % 2]
          n -= 1
        else:
          return foo
    return foo

# CUT begin
# TEST CODE FOR PYTHON {{{
import sys, time, math

def tc_equal(expected, received):
    try:
        _t = type(expected)
        received = _t(received)
        if _t == list or _t == tuple:
            if len(expected) != len(received): return False
            return all(tc_equal(e, r) for (e, r) in zip(expected, received))
        elif _t == float:
            eps = 1e-9
            d = abs(received - expected)
            return not math.isnan(received) and not math.isnan(expected) and d <= eps * max(1.0, abs(expected))
        else:
            return expected == received
    except:
        return False

def pretty_str(x):
    if type(x) == str:
        return '"%s"' % x
    elif type(x) == tuple:
        return '(%s)' % (','.join( (pretty_str(y) for y in x) ) )
    else:
        return str(x)

def do_test(R, C, N, __expected):
    startTime = time.time()
    instance = RealWithRooks()
    exception = None
    try:
        __result = instance.construct(R, C, N);
    except:
        import traceback
        exception = traceback.format_exc()
    elapsed = time.time() - startTime   # in sec

    if exception is not None:
        sys.stdout.write("RUNTIME ERROR: \n")
        sys.stdout.write(exception + "\n")
        return 0

    if tc_equal(__expected, __result):
        sys.stdout.write("PASSED! " + ("(%.3f seconds)" % elapsed) + "\n")
        return 1
    else:
        sys.stdout.write("FAILED! " + ("(%.3f seconds)" % elapsed) + "\n")
        sys.stdout.write("           Expected: " + pretty_str(__expected) + "\n")
        sys.stdout.write("           Received: " + pretty_str(__result) + "\n")
        return 0

def run_tests():
    sys.stdout.write("RealWithRooks (300 Points)\n\n")

    passed = cases = 0
    case_set = set()
    for arg in sys.argv[1:]:
        case_set.add(int(arg))

    with open("RealWithRooks.sample", "r") as f:
        while True:
            label = f.readline()
            if not label.startswith("--"): break

            R = int(f.readline().rstrip())
            C = int(f.readline().rstrip())
            N = int(f.readline().rstrip())
            f.readline()
            __answer = []
            for i in range(0, int(f.readline())):
                __answer.append(f.readline().rstrip())
            __answer = tuple(__answer)

            cases += 1
            if len(case_set) > 0 and (cases - 1) in case_set: continue
            sys.stdout.write("  Testcase #%d ... " % (cases - 1))
            passed += do_test(R, C, N, __answer)

    sys.stdout.write("\nPassed : %d / %d cases\n" % (passed, cases))

    T = time.time() - 1564808408
    PT, TT = (T / 60.0, 75.0)
    points = 300 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT))
    sys.stdout.write("Time   : %d minutes %d secs\n" % (int(T/60), T%60))
    sys.stdout.write("Score  : %.2f points\n" % points)

if __name__ == '__main__':
    run_tests()

# }}}
# CUT end
