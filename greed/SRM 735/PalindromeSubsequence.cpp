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

//]TAIL_OF_JKI'S_HEADER

const int inf=0x3f3f3f3f;

int n;
char a[64];
int f[64][64];
int g[64][64];

vector<int> r;

int process(const int lef, const int rig){
    if(lef>rig)return 0;
    if(~f[lef][rig])return f[lef][rig];
    int &foo=f[lef][rig];
    foo=inf;
    for(int i=lef; i<=rig; i++){
        if(a[i]==a[lef]){
            int tmp=MAX(process(lef+1, i-1), 1)+process(i+1, rig);
            if(foo>tmp){
                foo=tmp;
                g[lef][rig]=i;
            }
        }
    }
    //fprintf(stderr, "f[%d][%d]=%d\n", lef, rig, f[lef][rig]);
    return foo;
}

void build(const int lef, const int rig, int &col){
    if(lef>rig)return;
    r[lef]=r[g[lef][rig]]=col;
    build(lef+1, g[lef][rig]-1, col);
    if(g[lef][rig]+1<=rig)
        build(g[lef][rig]+1, rig, ++col);
}

class PalindromeSubsequence {
    public:
    vector<int> optimalPartition(string s) {
        n=s.length();
        for(int i=0; i<n; i++)a[i]=s[i];
        memset(f, 0xff, sizeof(f));
        r.resize(n);
        if(process(0, n-1)<=2){
            int tmp=1;
            build(0, n-1, tmp);
        }else{
            for(int i=0; i<n; i++){
                r[i]=(a[i]=='a')?1:2;
            }
        }
        return r;
    }
};

// CUT begin
ifstream data("PalindromeSubsequence.sample");

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

template <typename T> string to_string(vector<T> ts) {
    stringstream s;
    s << "[ ";
    for (int i = 0; i < ts.size(); ++i) {
        if (i > 0) s << ", ";
        s << to_string(ts[i]);
    }
    s << " ]";
    return s.str();
}

bool do_test(string s, vector<int> __expected) {
    time_t startClock = clock();
    PalindromeSubsequence *instance = new PalindromeSubsequence();
    vector<int> __result = instance->optimalPartition(s);
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
        string s;
        from_stream(s);
        next_line();
        vector<int> __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(s, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1530010807;
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
        cout << "PalindromeSubsequence (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
