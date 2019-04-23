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

def printout(pzero, c):
  foo, bar = pzero, pzero
  print('foo = %d, bar = %d' % (foo, bar))
  for d in c:
    bar *= 10
    bar = bar * (100 + d) / 100
    if bar % 10 < 5:
      bar = bar / 10
    else:
      bar = bar / 10 + 1
    foo += bar
    print('foo = %d, bar = %d' % (foo, bar))
  foo *= 10
  foo = foo / (len(c) + 1)
  if foo % 10 < 5:
    foo = foo / 10
  else:
    foo = foo / 10 + 1
  print('foo = %d' % foo)
  return foo
  
def expected(pzero, c):
  foo, bar = pzero, pzero
  for d in c:
    bar *= 10
    bar = bar * (100 + d) / 100
    if bar % 10 < 5:
      bar = bar / 10
    else:
      bar = bar / 10 + 1
    foo += bar
  foo *= 10
  foo = foo / (len(c) + 1)
  if foo % 10 < 5:
    foo = foo / 10
  else:
    foo = foo / 10 + 1
  return foo

class EllysTicketPrices:
  def getPrice(self, n, c, target):
    m = target * 100
    lhs, rhs = 0, 1
    while expected(rhs, c) < m:
      rhs *= 2
    while lhs <= rhs:
      mid = (lhs + rhs) / 2
      if expected(mid, c) >= m:
        if mid == lhs or expected(mid - 1, c) < m:
          printout(mid, c)
          return mid / 100.0
        rhs = mid - 1
      else:
        lhs = mid + 1
    return 0.0

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

def do_test(N, C, target, __expected):
    startTime = time.time()
    instance = EllysTicketPrices()
    exception = None
    try:
        __result = instance.getPrice(N, C, target);
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
    sys.stdout.write("EllysTicketPrices (1000 Points)\n\n")

    passed = cases = 0
    case_set = set()
    for arg in sys.argv[1:]:
        case_set.add(int(arg))

    with open("EllysTicketPrices.sample", "r") as f:
        while True:
            label = f.readline()
            if not label.startswith("--"): break

            N = int(f.readline().rstrip())
            C = []
            for i in range(0, int(f.readline())):
                C.append(int(f.readline().rstrip()))
            C = tuple(C)
            target = int(f.readline().rstrip())
            f.readline()
            __answer = float(f.readline().rstrip())

            cases += 1
            if len(case_set) > 0 and (cases - 1) in case_set: continue
            sys.stdout.write("  Testcase #%d ... " % (cases - 1))
            passed += do_test(N, C, target, __answer)

    sys.stdout.write("\nPassed : %d / %d cases\n" % (passed, cases))

    T = time.time() - 1555778048
    PT, TT = (T / 60.0, 75.0)
    points = 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT))
    sys.stdout.write("Time   : %d minutes %d secs\n" % (int(T/60), T%60))
    sys.stdout.write("Score  : %.2f points\n" % points)

if __name__ == '__main__':
    run_tests()

# }}}
# CUT end
