#include "bits/stdc++.h"
using namespace std;

int nbs[1100], dst[3100], nxt[3100], br[3100], eid;
int vst[1100], col[1100], msk;
int f[1100], g[1100];

void add_edge(const int u, const int v) {
  nxt[eid] = nbs[u];
  dst[eid] = v;
  br[eid] = 0;
  nbs[u] = eid++;
  nxt[eid] = nbs[v];
  dst[eid] = u;
  br[eid] = 0;
  nbs[v] = eid++;
}

void dfs(const int u, const int cu, const int cv, const int msk) {
  col[u] = msk;
  for(int i = nbs[u]; ~i; i = nxt[i]) {
    const int v = dst[i];
    if(u == cu && v == cv)continue;
    if(col[v] == msk)continue;
    dfs(v, cu, cv, msk);
  }
}

void mark_bridge(const int u) {
  for(int i = nbs[u]; ~i; i = nxt[i]) {
    const int v = dst[i];
    dfs(u, u, v, ++msk);
    if(col[v] != msk) {
      br[i] = 1;
    }
  }
}

int count(const int u, const int p) {
  vst[u] = 1;
  f[u] = 1;
  g[u] = 0;
  for(int i = nbs[u]; ~i; i = nxt[i]) {
    const int v = dst[i];
    if(v == p) continue;
    if(!br[i]) continue;
    g[u] += count(v, u);
    f[u] += g[v];
  }
  return max(f[u], g[u]);
}

class MaxCutFree {
  public:
  int solve(int n, vector<int> a, vector<int> b) {
    for(int i = 0; i < n; ++i)
      nbs[i] = -1;
    eid = 0;
    int m = a.size();
    for(int i = 0; i < m; ++i)
      add_edge(a[i], b[i]);
    for(int i = 0; i < n; ++i) {
      vst[i] = 0;
      col[i] = -1;
    }
    msk = 0;
    for(int i = 0; i < n; ++i) {
      mark_bridge(i);
    }
    int foo = 0;
    for(int i = 0; i < n; ++i) {
      if(vst[i])continue;
      foo += count(i, -1);
    }
    return foo;
  }
};

// CUT begin
ifstream data("MaxCutFree.sample");

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

bool do_test(int n, vector<int> a, vector<int> b, int __expected) {
    time_t startClock = clock();
    MaxCutFree *instance = new MaxCutFree();
    int __result = instance->solve(n, a, b);
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
        vector<int> a;
        from_stream(a);
        vector<int> b;
        from_stream(b);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(n, a, b, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1553094049;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 300 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "MaxCutFree (300 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
