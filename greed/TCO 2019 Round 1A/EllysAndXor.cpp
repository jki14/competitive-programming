#include "bits/stdc++.h"
using namespace std;

//TYPEDEF
typedef long long lld;
typedef unsigned long long u64;
typedef pair<int, int> pii;

//COMPARE
template<class T> inline T MIN(const T x, const T y){ return (x<y)?x:y; }
template<class T> inline T MAX(const T x, const T y){ return (x>y)?x:y; }

template<class T> inline void UPDMIN(T &x, const T y){ if(x>y)x=y; }
template<class T> inline void UPDMAX(T &x, const T y){ if(x<y)x=y; }

//STL
template<class T>  inline int SIZE(const T &x){ return (int)x.size(); }
template<class T>  inline int LENGTH(const T &x){ return (int)x.length(); }
template<class T1, class T2> inline pair<T1, T2> MP(const T1 &x, const T2 &y){ return make_pair(x, y); }


class EllysAndXor {
  public:
    int getMax(vector<int> numbers) {
      int const n = SIZE(numbers);
      int const m = 1 << (n - 1);
      int foo = 0;
      for (int msk = 0; msk < m; ++msk) {
        int bar = numbers[0];
        for (int i = 0; i < n - 1; ++i) {
          if ((msk >> i) & 1) {
            bar &= numbers[i + 1];
          } else {
            bar ^= numbers[i + 1];
          }
        }
        UPDMAX(foo, bar);
      }
      return foo;
    }
};

// CUT begin
ifstream data("EllysAndXor.sample");

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

template <typename T> void from_stream(vector<T> &ts) {
  int len;
  from_stream(len);
  ts.clear();
  for (int i = 0; i < len; ++i) {
    T t;
    from_stream(t);
    ts.push_back(t);
  }
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

bool do_test(vector<int> numbers, int __expected) {
  time_t startClock = clock();
  EllysAndXor *instance = new EllysAndXor();
  int __result = instance->getMax(numbers);
  double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
  delete instance;

  if (__result == __expected) {
    cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
    return true;
  }
  else {
    cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
    cout << "           Expected: " << to_string(__expected) << endl;
    cout << "           Received: " << to_string(__result) << endl;
    return false;
  }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
  int cases = 0, passed = 0;
  while (true) {
    if (next_line().find("--") != 0)
      break;
    vector<int> numbers;
    from_stream(numbers);
    next_line();
    int __answer;
    from_stream(__answer);

    cases++;
    if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
      continue;

    cout << "  Testcase #" << cases - 1 << " ... ";
    if ( do_test(numbers, __answer)) {
      passed++;
    }
  }
  if (mainProcess) {
    cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
    int T = time(NULL) - 1555776107;
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
    cout << "EllysAndXor (250 Points)" << endl << endl;
  }
  return run_test(mainProcess, cases, argv[0]);
}
// CUT end
