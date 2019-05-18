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

def check(k, n, m, a):
  foo = 0
  c = len(a)
  b = sorted([[a[i] % m + 1, a[i]] for i in xrange(c)])
  d = sum(a) - k
  for i in xrange(c):
    if b[i][0] <= d:
      b[i][1] -= b[i][0]
      d -= b[i][0]
  for i in xrange(c):
    foo += b[i][1] / m
  foo -= min(d / m, foo)
  if foo >= n:
    return True
  else:
    return False

def process(n, m, a):
  lef, rig = 1, sum(a)
  while lef <= rig:
    mid = (lef + rig) >> 1
    if check(mid, n, m ,a):
      if mid == lef or not check(mid - 1, n, m, a):
        return mid
      rig = mid - 1
    else:
      lef = mid + 1
  return -1

class CentipedeSocks:
  def fewestSocks(self, C, F, sockCounts):
    return process(C, F, sockCounts)

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

def do_test(C, F, sockCounts, __expected):
    startTime = time.time()
    instance = CentipedeSocks()
    exception = None
    try:
        __result = instance.fewestSocks(C, F, sockCounts);
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
    sys.stdout.write("CentipedeSocks (250 Points)\n\n")

    passed = cases = 0
    case_set = set()
    for arg in sys.argv[1:]:
        case_set.add(int(arg))

    with open("CentipedeSocks.sample", "r") as f:
        while True:
            label = f.readline()
            if not label.startswith("--"): break

            C = int(f.readline().rstrip())
            F = int(f.readline().rstrip())
            sockCounts = []
            for i in range(0, int(f.readline())):
                sockCounts.append(int(f.readline().rstrip()))
            sockCounts = tuple(sockCounts)
            f.readline()
            __answer = int(f.readline().rstrip())

            cases += 1
            if len(case_set) > 0 and (cases - 1) in case_set: continue
            sys.stdout.write("  Testcase #%d ... " % (cases - 1))
            passed += do_test(C, F, sockCounts, __answer)

    sys.stdout.write("\nPassed : %d / %d cases\n" % (passed, cases))

    T = time.time() - 1556586110
    PT, TT = (T / 60.0, 75.0)
    points = 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT))
    sys.stdout.write("Time   : %d minutes %d secs\n" % (int(T/60), T%60))
    sys.stdout.write("Score  : %.2f points\n" % points)

if __name__ == '__main__':
    run_tests()

# }}}
# CUT end
