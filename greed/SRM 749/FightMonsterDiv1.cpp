#include "bits/stdc++.h"
using namespace std;

//HEAD_OF_CONFIG_

static const int MOD=1000000007; //1000000000000000003LL
static const double eps=1e-8;

//TAIL_OF_CONFIG_

//TYPEDEF
typedef long long lld;
typedef unsigned long long u64;
typedef pair<int, int> pii;

//COMPARE
template<class T> inline T MIN(const T x, const T y){ return (x<y)?x:y; }
template<class T> inline T MAX(const T x, const T y){ return (x>y)?x:y; }

template<class T> inline void UPDMIN(T &x, const T y){ if(x>y)x=y; }
template<class T> inline void UPDMAX(T &x, const T y){ if(x<y)x=y; }


const lld inf = 0x3f3f3f3f3f3f3f3fLL;

class FightMonsterDiv1 {
  private:
    lld bs0(lld lef, lld rig, const lld goal, const lld base, const lld delta) {
      auto calc = [=](const lld x) {
        return (base + base + delta * x) * x / 2LL;
      };
      while (lef <= rig) {
        const lld mid = (lef + rig) >> 1;
        if (calc(mid) >= goal) {
          if (mid == lef || calc(mid - 1LL) < goal) return mid;
          rig = mid - 1LL;
        } else {
          lef = mid + 1LL;
        }
      }
      return inf;
    }
    lld bs1(lld lef, lld rig, const lld goal, const lld base, const lld delta, const lld enhance) {
      auto calc = [=](const lld x) {
        lld normal = MAX(x - enhance, 0LL);
        lld base2 = base + normal * delta;
        lld x2 = x - normal;
        return (base + base + delta * normal) * normal / 2LL + (base2 + base2 + delta * x2) * x2 / 2LL * 5LL;
      };
      while (lef <= rig) {
        const lld mid = (lef + rig) >> 1;
        if (calc(mid) >= goal) {
          if (mid == lef || calc(mid - 1LL) < goal) return mid + 1LL;
          rig = mid - 1LL;
        } else {
          lef = mid + 1LL;
        }
      }
      return inf;
    }
  public:
    long long fightTime(long long hp, long long attack, int level, long long duration) {
      lld delta = attack * level / 100L;
      lld brute = bs0(1LL, (hp + attack - 1LL) / attack, hp, attack, delta);
      lld magic = bs1(1LL, brute, hp, attack, delta, duration);
      return MIN(brute, magic);
    }
};

// CUT begin
ifstream data("FightMonsterDiv1.sample");

string next_line() {
  string s;
  getline(data, s);
  return s;
}

template <typename T> void from_stream(T &t) {
  stringstream ss(next_line());
  ss >> t;
}

void from_stream(string &s) {
  s = next_line();
}

template <typename T>
string to_string(T t) {
  stringstream s;
  s << t;
  return s.str();
}

string to_string(string t) {
  return "\"" + t + "\"";
}

bool do_test(long long hp, long long attack, int level, long long duration, long long __expected) {
  time_t startClock = clock();
  FightMonsterDiv1 *instance = new FightMonsterDiv1();
  long long __result = instance->fightTime(hp, attack, level, duration);
  double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
  delete instance;

  if (__result == __expected) {
    cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
    return true;
  }
  else {
    cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
    cout << "       Expected: " << to_string(__expected) << endl;
    cout << "       Received: " << to_string(__result) << endl;
    return false;
  }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
  int cases = 0, passed = 0;
  while (true) {
    if (next_line().find("--") != 0)
      break;
    long long hp;
    from_stream(hp);
    long long attack;
    from_stream(attack);
    int level;
    from_stream(level);
    long long duration;
    from_stream(duration);
    next_line();
    long long __answer;
    from_stream(__answer);

    cases++;
    if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
      continue;

    cout << "  Testcase #" << cases - 1 << " ... ";
    if ( do_test(hp, attack, level, duration, __answer)) {
      passed++;
    }
  }
  if (mainProcess) {
    cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
    int T = time(NULL) - 1549108812;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
  }
  return 0;
}

int main(int argc, char *argv[]) {
  cout.setf(ios::fixed, ios::floatfield);
  cout.precision(2);
  set<int> cases;
  bool mainProcess = true;
  for (int i = 1; i < argc; ++i) {
    if ( string(argv[i]) == "-") {
      mainProcess = false;
    } else {
      cases.insert(atoi(argv[i]));
    }
  }
  if (mainProcess) {
    cout << "FightMonsterDiv1 (250 Points)" << endl << endl;
  }
  return run_test(mainProcess, cases, argv[0]);
}
// CUT end
