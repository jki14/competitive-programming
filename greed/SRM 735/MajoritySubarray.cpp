#include "bits/stdc++.h"
using namespace std;

//[HEAD_OF_JKI'S_HEADER_

    //TYPEDEF
    typedef long long lld;
    typedef unsigned long long u64;
    typedef pair<int, int> pii;

    //BIT
    template<class T> inline T LOWBIT(const T x){ return (x^(x-1))&x; }

//]TAIL_OF_JKI'S_HEADER

const int dived = 1<<16;
const lld moded = 1LL<<31;

int a[110000];
int b[110000];
int c[210000];

inline void add(const int k, const int s){
    for(int i=k; i<=s; i+=LOWBIT(i)){
        c[i]++;
    }
}

inline int cnt(const int k){
    int foo=0;
    for(int i=k; i; i-=LOWBIT(i)){
        foo+=c[i];
    }
    return foo;
}

class MajoritySubarray {
    private:
    lld solution(const int n, lld seed, int m){
        for(int i=0; i<n; i++){
            a[i]=(seed/dived)%m;
            //fprintf(stderr, " %d", a[i]);
            seed=(seed*1103515245LL+12345LL)%moded;
        }
        //fprintf(stderr, "\n");
        lld foo=0LL;
        for(int k=0; k<m; k++){
            for(int i=0; i<n; i++){
                b[i]=(a[i]==k)?1:-1;
            }
            for(int i=0; i<=n+n+1; i++){
                c[i]=0;
            }
            int presum=0;
            add(presum+n+1, n+n+1);
            for(int i=0; i<n; i++){
                presum+=b[i];
                foo+=cnt(presum+n);
                //fprintf(stderr, "presum=%d, foo=%lld\n", presum, foo);
                add(presum+n+1, n+n+1);
            }
            //fprintf(stderr, "\n");
        }
        return foo;
    }
    public:
    long long getCount(int n, int seed, int m) {
        return this->solution(n, seed, m);
    }
};

// CUT begin
ifstream data("MajoritySubarray.sample");

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

bool do_test(int n, int seed, int m, long long __expected) {
    time_t startClock = clock();
    MajoritySubarray *instance = new MajoritySubarray();
    long long __result = instance->getCount(n, seed, m);
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
        int seed;
        from_stream(seed);
        int m;
        from_stream(m);
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(n, seed, m, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1530012878;
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
        cout << "MajoritySubarray (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
