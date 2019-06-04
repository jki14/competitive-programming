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

class MedianFaking:

  def minimize(self, n, m, data, goal):
    lt, gt = (len(data) - 1) / 2, len(data) / 2

    a = [[0, 0] for i in xrange(n)]
    s = [0, 0]
    for i in xrange(n):
      for j in xrange(m):
        k = i * m + j
        if data[k] == goal:
          pass
        else:
          if data[k] < goal:
            a[i][0] += 1
          else:
            a[i][1] += 1
      s[0] += a[i][0]
      s[1] += a[i][1]
    if (s[0] > lt):
      s = s[0] - lt
      a = sorted([v[0] for v in a], reverse = True)
      # sys.stderr.write('s = %d, a = %s\n' % (s, str(a)))
      rhs = s
      for i in xrange(n):
        if s <= a[i]:
          # rhs = max(s, rhs)
          return (i + 1, rhs)
        s -= a[i]
        # rhs = max(a[i], rhs)
    elif (s[1] > gt):
      s = s[1] - gt
      a = sorted([v[1] for v in a], reverse = True)
      # sys.stderr.write('s = %d, a = %s\n' % (s, str(a)))
      rhs = s
      for i in xrange(n):
        if s <= a[i]:
          # rhs = max(s, rhs)
          return (i + 1, rhs)
        s -= a[i]
        # rhs = max(a[i], rhs)
    else:
      return (0, 0)

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

def do_test(F, M, data, goal, __expected):
    startTime = time.time()
    instance = MedianFaking()
    exception = None
    try:
        __result = instance.minimize(F, M, data, goal);
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
    sys.stdout.write("MedianFaking (250 Points)\n\n")

    passed = cases = 0
    case_set = set()
    for arg in sys.argv[1:]:
        case_set.add(int(arg))

    with open("MedianFaking.sample", "r") as f:
        while True:
            label = f.readline()
            if not label.startswith("--"): break

            F = int(f.readline().rstrip())
            M = int(f.readline().rstrip())
            data = []
            for i in range(0, int(f.readline())):
                data.append(int(f.readline().rstrip()))
            data = tuple(data)
            goal = int(f.readline().rstrip())
            f.readline()
            __answer = []
            for i in range(0, int(f.readline())):
                __answer.append(int(f.readline().rstrip()))
            __answer = tuple(__answer)

            cases += 1
            if len(case_set) > 0 and (cases - 1) in case_set: continue
            sys.stdout.write("  Testcase #%d ... " % (cases - 1))
            passed += do_test(F, M, data, goal, __answer)

    sys.stdout.write("\nPassed : %d / %d cases\n" % (passed, cases))

    T = time.time() - 1559660456
    PT, TT = (T / 60.0, 75.0)
    points = 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT))
    sys.stdout.write("Time   : %d minutes %d secs\n" % (int(T/60), T%60))
    sys.stdout.write("Score  : %.2f points\n" % points)

if __name__ == '__main__':
    run_tests()

# }}}
# CUT end
