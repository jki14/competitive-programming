#include "bits/stdc++.h"
using namespace std;

//HEAD_OF_JKI'S_HEADER_

    //COMPARE
    template<class T> inline T MIN(const T x, const T y){ return (x<y)?x:y; }
    template<class T> inline T MAX(const T x, const T y){ return (x>y)?x:y; }

    template<class T> inline void UPDMIN(T &x, const T y){ if(x>y)x=y; }
    template<class T> inline void UPDMAX(T &x, const T y){ if(x<y)x=y; }

    //STL
    template<class T>  inline int SIZE(const T &x){ return (int)x.size(); }
    template<class T>  inline int LENGTH(const T &x){ return (int)x.length(); }
    template<class T1, class T2> inline pair<T1, T2> MP(const T1 &x, const T2 &y){ return make_pair(x, y); }

//TAIL_OF_JKI'S_HEADER

#define N 18
#define S 41000

const int inf=0x3f3f3f3f;
const int col=64;

struct node_t{
    int foo[col];
    int flag;
    void clear(){
        for(int i=0; i<col; i++)
            this->foo[i]=-inf;
        this->flag=0;
    }
    void update(const node_t &rhs){
        for(int i=0; i<col; i++){
            UPDMAX(this->foo[i], rhs.foo[i]);
        }
    }
    void process(const int x){
        int nxt[col];
        for(int i=0; i<col; i++)nxt[i]=-inf;
        for(int i=0; i<col; i++){
            if(this->foo[i]<0)continue;
            int val=this->foo[i]+(this->foo[i]^x);
            UPDMAX(nxt[val&(col-1)], val);
        }
        for(int i=0; i<col; i++)this->foo[i]=nxt[i];
    }
    void insert(const int val){
        UPDMAX(this->foo[val&(col-1)], val);
    }
    int peak(){
        int res=-inf;
        for(int i=0; i<col; i++){
            UPDMAX(res, this->foo[i]);
        }
        return res;
    }
};

int n, a[N];
node_t f[S];

node_t calc(const int cov){
    if(f[cov].flag)return f[cov];
    node_t &foo=f[cov];
    foo.flag=1;
    for(int i=0; i<n; i++){
        int msk=1<<i;
        if(cov&msk){
            node_t pre=calc(cov^msk);
            pre.process(a[i]);
            foo.update(pre);
        }
    }
    return foo;
}

class Xscoregame {
    public:
    int getscore(vector<int> A) {
        n=SIZE(A);
        for(int i=0; i<n; i++)a[i]=A[i];
        int m=(1<<n)-1;
        for(int i=0; i<=m; i++){
            f[i].clear();
        }
        f[0].flag=1;
        f[0].insert(0);
        return calc(m).peak();
    }
};

// CUT begin
ifstream data("Xscoregame.sample");

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

bool do_test(vector<int> A, int __expected) {
    time_t startClock = clock();
    Xscoregame *instance = new Xscoregame();
    int __result = instance->getscore(A);
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
        vector<int> A;
        from_stream(A);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(A, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1487693667;
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
        cout << "Xscoregame (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
