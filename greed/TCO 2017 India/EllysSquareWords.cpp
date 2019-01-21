#include "bits/stdc++.h"
using namespace std;

//HEAD_OF_JKI'S_HEADER_

    //COMPARE
    template<class T> inline T MIN(const T x, const T y){ return (x<y)?x:y; }
    template<class T> inline T MAX(const T x, const T y){ return (x>y)?x:y; }

    template<class T> inline void UPDMIN(T &x, const T y){ if(x>y)x=y; }
    template<class T> inline void UPDMAX(T &x, const T y){ if(x<y)x=y; }

//TAIL_OF_JKI'S_HEADER

int n, a[64], r[32];
int cnt[32];

int score(){
    for(int i=0; i<26; i++)cnt[i]=0;
    for(int i=0; i<n; i++){
        cnt[r[a[i]]]++;
    }
    int foo=0;
    for(int i=0; i<26; i++){
        foo+=cnt[i]*cnt[i];
    }
    return foo;
}

class EllysSquareWords {
    public:
    int getScore(string S) {
        n=S.length();
        for(int i=0; i<n; i++)a[i]=S[i]-'A';
        for(int i=0; i<26; i++)r[i]=i;
        int foo=score();
        for(int x=0; x<26; x++){
            for(int y=0; y<26; y++){
                if(x==y)continue;
                r[x]=y;
                UPDMAX(foo, score());
                r[x]=x;
            }
        }
        return foo;
    }
};

// CUT begin
ifstream data("EllysSquareWords.sample");

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

bool do_test(string S, int __expected) {
    time_t startClock = clock();
    EllysSquareWords *instance = new EllysSquareWords();
    int __result = instance->getScore(S);
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
        string S;
        from_stream(S);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(S, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1503219608;
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
        cout << "EllysSquareWords (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
