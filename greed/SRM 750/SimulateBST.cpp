#include "bits/stdc++.h"
using namespace std;

static const int MOD=1000000007;

typedef long long lld;
template<class T> inline T MIN(const T x, const T y){ return (x<y)?x:y; }
template<class T> inline T MAX(const T x, const T y){ return (x>y)?x:y; }
template<class T> inline void UPDMIN(T &x, const T y){ if(x>y)x=y; }
template<class T> inline void UPDMAX(T &x, const T y){ if(x<y)x=y; }
template<class T1, class T2> inline pair<T1, T2> MP(const T1 &x, const T2 &y){ return make_pair(x, y); }
template<class T> inline T MOD_STD(const T x, const T m=MOD){ return (x%m+m)%m; }
template<class T> inline void MOD_STD(T *x, const T m=MOD){ *x=(*x%m+m)%m; }
template<class T> inline T MOD_ADD(const T x, const T y, const T m=MOD){ return (x+y)%m; }
template<class T> inline void MOD_ADD(T *x, const T y, const T m=MOD){ *x=(*x+y)%m; }
template<class T> inline T MOD_MUL(const T x, const T y, const T m=MOD){ return (T)((1LL*x*y)%m); }
template<class T> inline void MOD_MUL(T *x, const T y, const T m=MOD){ *x=(T)((1LL*(*x)*y)%m); }

class SimulateBST {
  public:
  int checksum(int n, vector<int> s, int a, int m) {
    const int p = s.size();
    vector<int> b(n, 0);
    map<int, int> bst;
    int foo = 0, goo = 1;
    for (int i = 0; i < n; ++i) {
      int x = (i < p) ? s[i] : ((a * 1LL * b[i - p] + bst[b[i - 1]] * 1LL + 1LL) % m);
      int y = 0;
      if (bst.count(x)) {
        y = bst[x];
      } else {
        if (!bst.empty()) {
          auto iter = bst.lower_bound(x);
          if (iter != bst.end()) {
            UPDMAX(y, iter->second + 1);
          }
          if (iter != bst.begin()) {
            iter--;
            UPDMAX(y, iter->second + 1);
          }
        }
        bst.insert(MP(x, y));
        //fprintf(stderr, "insert %d, %d\n", x, y);
      }
      MOD_ADD(&foo, MOD_MUL(y, goo));
      MOD_MUL(&goo, 100000);
      b[i] = x;
    }
    return foo;
  }
};

// CUT begin
ifstream data("SimulateBST.sample");

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

bool do_test(int n, vector<int> Sprefix, int a, int m, int __expected) {
    time_t startClock = clock();
    SimulateBST *instance = new SimulateBST();
    int __result = instance->checksum(n, Sprefix, a, m);
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
        int n;
        from_stream(n);
        vector<int> Sprefix;
        from_stream(Sprefix);
        int a;
        from_stream(a);
        int m;
        from_stream(m);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(n, Sprefix, a, m, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1549642470;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "SimulateBST (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
