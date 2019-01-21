#include "bits/stdc++.h"
using namespace std;

//[HEAD_OF_JKI'S_HEADER_

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

//]TAIL_OF_JKI'S_HEADER

lld pos[64], neg[64], low[64];

class OrAndSum {
    public:
    string isPossible(vector<long long> pairOr, vector<long long> pairSum) {
        int n=SIZE(pairOr);
        memset(pos, 0, sizeof(pos));
        memset(neg, 0, sizeof(neg));
        memset(low, 0, sizeof(low));
        for(int i=0; i<n; i++){
            for(lld k=1LL<<59; k; k>>=1){
                if((pairOr[i]&k)==0LL){
                    neg[i]|=k;
                    neg[i+1]|=k;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(lld k=1LL<<59; k; k>>=1){
                if((pairOr[i]&k)!=0LL){
                    if(((~neg[i])&k) && ((~neg[i+1])&k)){
                        low[i]|=k;
                    }else if((~neg[i])&k){
                        pos[i]|=k;
                    }else if((~neg[i+1])&k){
                        pos[i+1]|=k;
                    }else{
                        return "Impossible";
                    }
                }
            }
        }
        for(int i=0; i<n; i++){
            if(pos[i]+pos[i+1]+low[i]>pairSum[i]){
                return "Impossible";
            }
            if(pos[i]+pos[i+1]+(low[i]<<1)<pairSum[i]){
                return "Impossible";
            }
        }
        return "Possible";
    }
};

// CUT begin
ifstream data("OrAndSum.sample");

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

bool do_test(vector<long long> pairOr, vector<long long> pairSum, string __expected) {
    time_t startClock = clock();
    OrAndSum *instance = new OrAndSum();
    string __result = instance->isPossible(pairOr, pairSum);
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
        vector<long long> pairOr;
        from_stream(pairOr);
        vector<long long> pairSum;
        from_stream(pairSum);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(pairOr, pairSum, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1511884804;
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
        cout << "OrAndSum (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
