#include "bits/stdc++.h"
using namespace std;

const int inf = 0x3f3f3f3f;

int nbs[1024], dst[2048], wht[2048], nxt[2048], eid;
int f[1024], g[1024], vst[1024];

void add_edge(const int u, const int v, const int w) {
  nxt[eid] = nbs[u];
  dst[eid] = v;
  wht[eid] = w;
  nbs[u] = eid++;
}

int run(const int u, const int p, const int k) {
  vst[u] = 1;
  f[u] = 0;
  int sub = 0;
  for (int i = nbs[u]; ~i; i = nxt[i]) {
    const int v = dst[i];
    const int w = wht[i];
    if (w != k) continue;
    if (v == p) continue;
    ++sub;
    run(v, u, k);
    f[u] += g[v];
  }
  f[u] -= sub >> 1;
  g[u] = f[u] + ((sub & 1) ^ 1);
  return f[u];
}

class DismantleTheTree {
  public:
  int dismantle(const int n, vector<int> const& u, vector<int> const& v, vector<int> const& w) {
    for (int i = 0; i < n; ++i) {
      nbs[i] = -1;
    }
    eid = 0;
    for (int i = 0; i + 1 < n; ++i) {
      add_edge(u[i] - 1, v[i] - 1, w[i]);
      add_edge(v[i] - 1, u[i] - 1, w[i]);
    }
    int foo = 0;
    for (int k = 1; k <= 100; ++k) {
      for (int i = 0; i < n; ++i) {
        f[i] = g[i] = inf;
        vst[i] = 0;
      }
      for (int i = 0; i < n; ++i) {
        if (vst[i]) continue;
        foo += k * run(i, -1, k);
      }
    }
    return foo;
  }
};

// CUT begin
ifstream data("DismantleTheTree.sample");

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

bool do_test(int N, vector<int> X, vector<int> Y, vector<int> weight, int __expected) {
    time_t startClock = clock();
    DismantleTheTree *instance = new DismantleTheTree();
    int __result = instance->dismantle(N, X, Y, weight);
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
        vector<int> X;
        from_stream(X);
        vector<int> Y;
        from_stream(Y);
        vector<int> weight;
        from_stream(weight);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(N, X, Y, weight, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1552666802;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 600 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "DismantleTheTree (600 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
