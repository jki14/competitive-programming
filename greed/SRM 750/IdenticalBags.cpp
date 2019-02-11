#include "bits/stdc++.h"
using namespace std;

typedef long long lld;

class IdenticalBags {
  private:
  lld process(lld lef, lld rig, const vector<lld> &c, const lld s) {
    auto good = [=](const lld k) {
      __int128 sum = 0;
      for (const lld x : c) {
        sum += x / k;
      }
      return (sum >= s) ? true : false;
    };
    while (lef <= rig) {
      const lld mid = (lef + rig) >> 1;
      if (good(mid)) {
        if (mid == rig || !good(mid + 1LL)) return mid;
        lef = mid + 1LL;
      } else {
        rig = mid - 1LL;
      }
    }
    return 0LL;
  }
  public:
  long long makeBags(vector<long long> candy, long long bagSize) {
    return process(1LL, *max_element(candy.begin(), candy.end()), candy, bagSize);
  }
};

// CUT begin
ifstream data("IdenticalBags.sample");

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

bool do_test(vector<long long> candy, long long bagSize, long long __expected) {
    time_t startClock = clock();
    IdenticalBags *instance = new IdenticalBags();
    long long __result = instance->makeBags(candy, bagSize);
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
        vector<long long> candy;
        from_stream(candy);
        long long bagSize;
        from_stream(bagSize);
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(candy, bagSize, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1549641686;
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
        cout << "IdenticalBags (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
