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

def check(x, y, a, h, w):
  foo = 0
  for i in xrange(x + 1, h):
    if a[i][y] == '.':
      continue
    if a[i][y] != a[x][y]:
      foo += 1
    break
  for i in xrange(y + 1, w):
    if a[x][i] == '.':
      continue
    if a[x][i] != a[x][y]:
      foo += 1
    break
  return foo

class WarmupWithRooks:
  def count(self, a):
    foo = 0
    h, w = len(a), len(a[0])
    for i in xrange(h):
      for j in xrange(w):
        if a[i][j] == '.':
          continue
        foo += check(i, j, a, h, w)
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

def do_test(board, __expected):
    startTime = time.time()
    instance = WarmupWithRooks()
    exception = None
    try:
        __result = instance.count(board);
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
    sys.stdout.write("WarmupWithRooks (200 Points)\n\n")

    passed = cases = 0
    case_set = set()
    for arg in sys.argv[1:]:
        case_set.add(int(arg))

    with open("WarmupWithRooks.sample", "r") as f:
        while True:
            label = f.readline()
            if not label.startswith("--"): break

            board = []
            for i in range(0, int(f.readline())):
                board.append(f.readline().rstrip())
            board = tuple(board)
            f.readline()
            __answer = int(f.readline().rstrip())

            cases += 1
            if len(case_set) > 0 and (cases - 1) in case_set: continue
            sys.stdout.write("  Testcase #%d ... " % (cases - 1))
            passed += do_test(board, __answer)

    sys.stdout.write("\nPassed : %d / %d cases\n" % (passed, cases))

    T = time.time() - 1564806607
    PT, TT = (T / 60.0, 75.0)
    points = 200 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT))
    sys.stdout.write("Time   : %d minutes %d secs\n" % (int(T/60), T%60))
    sys.stdout.write("Score  : %.2f points\n" % points)

if __name__ == '__main__':
    run_tests()

# }}}
# CUT end
