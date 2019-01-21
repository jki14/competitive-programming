# -*- coding: utf-8 -*-
import math,string,itertools,fractions,heapq,collections,re,array,bisect

class SquareCutout:
    def verify(self, cutout):
        r = len(cutout)
        c = len(cutout[0])
        px, py = -1, -1
        for i in xrange(r):
            for j in xrange(c):
                if cutout[i][j] == '#':
                    px, py = i, j
                    break
            if px != -1:
                break
        if px == -1:
            return 1
        qx, qy = -1, -1
        for i in xrange(r - 1, -1, -1):
            for j in xrange(c - 1, -1, -1):
                if cutout[i][j] == '#':
                    qx, qy = i, j
                    break
            if qx != -1:
                break
        #check-outside-of-pq
        for i in xrange(r):
            for j in xrange(c):
                if cutout[i][j] == '#':
                    if px <= i and i <= qx and py <= j and j <= qy:
                        continue
                    return 0
        #check-inside-of-pq
        for i in xrange(px, qx + 1):
            for j in xrange(py, qy + 1):
                if cutout[i][j] == '.':
                    return 0
        pqh = qx - px + 1
        pqw = qy - py + 1
        #already square
        if pqw == pqh:
            return pqw
        #extend
        if px == 0 or qx == r - 1:
            if pqw >= pqh:
                return pqw
                pass
        if py == 0 or qy == c - 1:
            if pqh >= pqw:
                return pqh
                pass
        return 0

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

def do_test(cutout, __expected):
    startTime = time.time()
    instance = SquareCutout()
    exception = None
    try:
        __result = instance.verify(cutout);
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
    sys.stdout.write("SquareCutout (250 Points)\n\n")

    passed = cases = 0
    case_set = set()
    for arg in sys.argv[1:]:
        case_set.add(int(arg))

    with open("SquareCutout.sample", "r") as f:
        while True:
            label = f.readline()
            if not label.startswith("--"): break

            cutout = []
            for i in range(0, int(f.readline())):
                cutout.append(f.readline().rstrip())
            cutout = tuple(cutout)
            f.readline()
            __answer = int(f.readline().rstrip())

            cases += 1
            if len(case_set) > 0 and (cases - 1) in case_set: continue
            sys.stdout.write("  Testcase #%d ... " % (cases - 1))
            passed += do_test(cutout, __answer)

    sys.stdout.write("\nPassed : %d / %d cases\n" % (passed, cases))

    T = time.time() - 1532048793
    PT, TT = (T / 60.0, 75.0)
    points = 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT))
    sys.stdout.write("Time   : %d minutes %d secs\n" % (int(T/60), T%60))
    sys.stdout.write("Score  : %.2f points\n" % points)

if __name__ == '__main__':
    run_tests()

# }}}
# CUT end
