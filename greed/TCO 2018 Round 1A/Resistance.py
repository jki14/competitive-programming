# -*- coding: utf-8 -*-
import math,string,itertools,fractions,heapq,collections,re,array,bisect

def getNext(x):
    lowbit = x & (-x)
    fund = x + lowbit
    sup = ((fund ^ x) >> 2) / lowbit
    return fund | sup

def check(s, missions):
    for row in missions:
        if row[0]!='F':
            continue
        cnt = 0
        for i in xrange(len(row)-1):
            if row[i+1]=='1' and (s&(1<<i))!=0:
                cnt += 1
        if cnt==0:
            return False
    return True

class Resistance:
    def spyProbability(self, P, S, missions):
        valid = []
        s = (1<<S)-1
        while s<(1<<P):
            if check(s, missions):
                valid.append(s)
            s = getNext(s)
        if len(valid)>0:
            foo = [0 for i in xrange(P)]
            for s in valid:
                for i in xrange(P):
                    if (s&(1<<i))!=0:
                        foo[i] += 1
            return [foo[i]*1.0/len(valid) for i in xrange(P)]
        else:
            return []

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

def do_test(P, S, missions, __expected):
    startTime = time.time()
    instance = Resistance()
    exception = None
    try:
        __result = instance.spyProbability(P, S, missions);
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
    sys.stdout.write("Resistance (500 Points)\n\n")

    passed = cases = 0
    case_set = set()
    for arg in sys.argv[1:]:
        case_set.add(int(arg))

    with open("Resistance.sample", "r") as f:
        while True:
            label = f.readline()
            if not label.startswith("--"): break

            P = int(f.readline().rstrip())
            S = int(f.readline().rstrip())
            missions = []
            for i in range(0, int(f.readline())):
                missions.append(f.readline().rstrip())
            missions = tuple(missions)
            f.readline()
            __answer = []
            for i in range(0, int(f.readline())):
                __answer.append(float(f.readline().rstrip()))
            __answer = tuple(__answer)

            cases += 1
            if len(case_set) > 0 and (cases - 1) in case_set: continue
            sys.stdout.write("  Testcase #%d ... " % (cases - 1))
            passed += do_test(P, S, missions, __answer)

    sys.stdout.write("\nPassed : %d / %d cases\n" % (passed, cases))

    T = time.time() - 1524326794
    PT, TT = (T / 60.0, 75.0)
    points = 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT))
    sys.stdout.write("Time   : %d minutes %d secs\n" % (int(T/60), T%60))
    sys.stdout.write("Score  : %.2f points\n" % points)

if __name__ == '__main__':
    run_tests()

# }}}
# CUT end
