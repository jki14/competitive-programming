#include "bits/stdc++.h"
using namespace std;

typedef long long lld;
typedef pair<int, int> pii;

int n, rawx[3100], rawy[3100];
unordered_set<lld> foo, bar;

inline lld tohash(pii pnt) {
  lld bar = 0;
  if (pnt.first < 0) {
    pnt.first = -pnt.first;
    bar |= 1;
  }
  if (pnt.second < 0) {
    pnt.second = - pnt.second;
    bar |= 2;
  }
  return (bar << 50) + pnt.first * 1000000LL + pnt.second;
}

pii hashto(lld code) {
  lld bar = 3LL << 50;
  bar = (code & bar) >> 50;
  lld dx = (bar & 1) ? -1 : 1;
  lld dy = (bar & 2) ? -1 : 1;
  code &= ~(3LL << 50);
  //fprintf(stderr, "foo: %lld, %lld\n", (code / 1000000) * dx, (code % 1000000) * dy);
  return make_pair<int, int>((code / 1000000) * dx, (code % 1000000) * dy);
}

pii rev(pii const& lhs, pii const& rhs) {
  return make_pair<int, int>(lhs.first - rhs.second + lhs.second, 
                             lhs.second + rhs.first - lhs.first);
}

int process() {
  foo.clear();
  for (int i = 0; i < n; ++i) {
    //fprintf(stderr, "raw: %d, %d\n", rawx[i], rawy[i]);
    foo.insert(tohash(make_pair(rawx[i], rawy[i])));
  }
  bar.clear();
  for (auto p = foo.begin(); p != foo.end(); ++p) {
    for (auto q = foo.begin(); q != foo.end(); ++q) {
      auto a = hashto(*p);
      auto s = hashto(*q);
      auto d = rev(a, s);
      auto f = rev(d, a);
      if (foo.count(tohash(d))) {
        if (!foo.count(tohash(f))) {
          //fprintf(stderr, "(%d, %d)\n", f.first, f.second);
          bar.insert(tohash(f));
        }
      } else if (foo.count(tohash(f))) {
        if (!foo.count(tohash(d))) {
          //fprintf(stderr, "(%d, %d)\n", d.first, d.second);
          bar.insert(tohash(d));
        }
      }
    }
  }
  return bar.size();
}

class MoreSquares {
  public:
  int countLocations(int N, int SX, int SY, vector<int> Xprefix, vector<int> Yprefix) {
    n = N;
    int L = Xprefix.size();
    for (int i = 0; i < L; ++i) {
      rawx[i] = Xprefix[i];
      rawy[i] = Yprefix[i];
    }
    for (int i= L; i < N; ++i) {
      rawx[i] = (rawx[i - 1] * 47 + 42) % SX;
      rawy[i] = (rawy[i - 1] * 47 + 42) % SY;
    }
    return process();
  }
};

// CUT begin
ifstream data("MoreSquares.sample");

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

bool do_test(int N, int SX, int SY, vector<int> Xprefix, vector<int> Yprefix, int __expected) {
    time_t startClock = clock();
    MoreSquares *instance = new MoreSquares();
    int __result = instance->countLocations(N, SX, SY, Xprefix, Yprefix);
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
        int N;
        from_stream(N);
        int SX;
        from_stream(SX);
        int SY;
        from_stream(SY);
        vector<int> Xprefix;
        from_stream(Xprefix);
        vector<int> Yprefix;
        from_stream(Yprefix);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(N, SX, SY, Xprefix, Yprefix, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1553943932;
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
        cout << "MoreSquares (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
