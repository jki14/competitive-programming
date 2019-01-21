# -*- coding: utf-8 -*-
import math,string,itertools,fractions,heapq,collections,re,array,bisect

def extended_euclidean(x, y):
    if y != 0:
        g, b, a = extended_euclidean(y, x % y)
        return g, a, b - x / y * a
    else:
        return x, 1, 0

class QuadraticIdentity:

    def getFactorials(self, m):
        f = []
        p = 1
        while p * p <= m:
            p += 1
            if m % p != 0:
                continue
            c = 1
            while m % p == 0:
                m /= p
                c *= p
            f.append(c)
        if m > 1:
            f.append(m)
        return f

    def getFixedPoints(self, m):
        f = self.getFactorials(m)
        n = len(f)
        r = []
        for k in xrange(1 << n):
            x, y = 1, 1 
            for i in xrange(n):
                if (k & (1 << i)) != 0:
                    x *= f[i]
                else:
                    y *= f[i]
            g, a, b = extended_euclidean(x, y)
            a = (a % y + y) % y
            r.append(a * x)
        r = sorted(r)
        while len(r) > 500:
            r = [r[i] for i in xrange(len(r)) if i % 2 == 0]
        return tuple(r)

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

def do_test(m, __expected):
    startTime = time.time()
    instance = QuadraticIdentity()
    exception = None
    try:
        __result = instance.getFixedPoints(m);
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
    sys.stdout.write("QuadraticIdentity (500 Points)\n\n")

    passed = cases = 0
    case_set = set()
    for arg in sys.argv[1:]:
        case_set.add(int(arg))

    with open("QuadraticIdentity.sample", "r") as f:
        while True:
            label = f.readline()
            if not label.startswith("--"): break

            m = int(f.readline().rstrip())
            f.readline()
            __answer = []
            for i in range(0, int(f.readline())):
                __answer.append(int(f.readline().rstrip()))
            __answer = tuple(__answer)

            cases += 1
            if len(case_set) > 0 and (cases - 1) in case_set: continue
            sys.stdout.write("  Testcase #%d ... " % (cases - 1))
            passed += do_test(m, __answer)

    sys.stdout.write("\nPassed : %d / %d cases\n" % (passed, cases))

    T = time.time() - 1531451110
    PT, TT = (T / 60.0, 75.0)
    points = 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT))
    sys.stdout.write("Time   : %d minutes %d secs\n" % (int(T/60), T%60))
    sys.stdout.write("Score  : %.2f points\n" % points)

if __name__ == '__main__':
    run_tests()

# }}}
# CUT end
