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

days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
dsum = [sum(days[:i]) for i in xrange(len(days))]
offset = 2

def skip(pos):
  return 6 - (pos + 2) % 7

class SaturdayNightStay:
  def countOptions(self, firstDay, firstMonth, lastDay, lastMonth):
    head = dsum[firstMonth - 1] + firstDay - 1
    tail = dsum[lastMonth - 1] + lastDay - 1
    foo = 0
    for i in xrange(head, tail):
      bar = tail - i
      foo += max(bar - skip(i), 0)
    sys.stderr.write('%d -> %d, len = %d\n' % ((head + 1) % 7 + 1,
                                               (tail + 1) % 7 + 1,
                                               tail - head + 1))
    sys.stderr.write('foo = %d\n' % (foo))
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

def do_test(firstDay, firstMonth, lastDay, lastMonth, __expected):
    startTime = time.time()
    instance = SaturdayNightStay()
    exception = None
    try:
        __result = instance.countOptions(firstDay, firstMonth, lastDay, lastMonth);
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
    sys.stdout.write("SaturdayNightStay (500 Points)\n\n")

    passed = cases = 0
    case_set = set()
    for arg in sys.argv[1:]:
        case_set.add(int(arg))

    with open("SaturdayNightStay.sample", "r") as f:
        while True:
            label = f.readline()
            if not label.startswith("--"): break

            firstDay = int(f.readline().rstrip())
            firstMonth = int(f.readline().rstrip())
            lastDay = int(f.readline().rstrip())
            lastMonth = int(f.readline().rstrip())
            f.readline()
            __answer = int(f.readline().rstrip())

            cases += 1
            if len(case_set) > 0 and (cases - 1) in case_set: continue
            sys.stdout.write("  Testcase #%d ... " % (cases - 1))
            passed += do_test(firstDay, firstMonth, lastDay, lastMonth, __answer)

    sys.stdout.write("\nPassed : %d / %d cases\n" % (passed, cases))

    T = time.time() - 1560582283
    PT, TT = (T / 60.0, 75.0)
    points = 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT))
    sys.stdout.write("Time   : %d minutes %d secs\n" % (int(T/60), T%60))
    sys.stdout.write("Score  : %.2f points\n" % points)

if __name__ == '__main__':
    run_tests()

# }}}
# CUT end
