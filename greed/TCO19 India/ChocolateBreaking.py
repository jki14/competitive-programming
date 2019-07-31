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

def execute(r, c, x, y):
  if x > r or y > c:
    return 0x3f3f3f3f3f3f3f3f
  return ((r + x - 1) / x) * ((c + y - 1) / y) - (r / x) * (c / y)

class ChocolateBreaking:
  def minDiff(self, r, c, p):
    foo = 0x3f3f3f3f3f3f3f3f
    for x in xrange(1, max(r, c) + 1):
      if x * x > p:
        break
      if p % x != 0:
        continue
      y = p / x
      foo = min(execute(r, c, x, y), foo)
      foo = min(execute(r, c, y, x), foo)
    if foo == 0x3f3f3f3f3f3f3f3f:
      foo = -1
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

def do_test(rows, cols, pieces, __expected):
    startTime = time.time()
    instance = ChocolateBreaking()
    exception = None
    try:
        __result = instance.minDiff(rows, cols, pieces);
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
    sys.stdout.write("ChocolateBreaking (500 Points)\n\n")

    passed = cases = 0
    case_set = set()
    for arg in sys.argv[1:]:
        case_set.add(int(arg))

    with open("ChocolateBreaking.sample", "r") as f:
        while True:
            label = f.readline()
            if not label.startswith("--"): break

            rows = int(f.readline().rstrip())
            cols = int(f.readline().rstrip())
            pieces = int(f.readline().rstrip())
            f.readline()
            __answer = int(f.readline().rstrip())

            cases += 1
            if len(case_set) > 0 and (cases - 1) in case_set: continue
            sys.stdout.write("  Testcase #%d ... " % (cases - 1))
            passed += do_test(rows, cols, pieces, __answer)

    sys.stdout.write("\nPassed : %d / %d cases\n" % (passed, cases))

    T = time.time() - 1564571926
    PT, TT = (T / 60.0, 75.0)
    points = 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT))
    sys.stdout.write("Time   : %d minutes %d secs\n" % (int(T/60), T%60))
    sys.stdout.write("Score  : %.2f points\n" % points)

if __name__ == '__main__':
    run_tests()

# }}}
# CUT end
