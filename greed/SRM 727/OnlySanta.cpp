#include "bits/stdc++.h"
using namespace std;

//STL
template<class T>  inline int SIZE(const T &x){ return (int)x.size(); }
template<class T>  inline int LENGTH(const T &x){ return (int)x.length(); }
template<class T1, class T2> inline pair<T1, T2> MP(const T1 &x, const T2 &y){ return make_pair(x, y); }

const char *pos = "SANTA";
const char *neg = "SATAN";

int n;
char a[1024];

int f[1024][8][8];
int g[1024][8][8];
int h[1024][8][8];

string track(int x, int y){
    string foo="";
    for(int i=n; i>0; i--){
        //fprintf(stderr, "f[%d][%d][%d]=%d\n", i, x, y, f[i][x][y]);
        assert(f[i][x][y]>=0);
        for(int k=1; k<=f[i][x][y]; k++){
            foo.push_back(pos[x-k]);
        }
        foo.push_back(a[i-1]);
        int _x=g[i][x][y];
        int _y=h[i][x][y];
        x=_x;
        y=_y;
    }
    reverse(foo.begin(), foo.end());
    return foo;
}

class OnlySanta {
    public:
    string solve(string S) {
        n=LENGTH(S);
        for(int i=0; i<n; i++)a[i]=S[i];
        memset(f, 0xff, sizeof(f));
        f[0][0][0]=0;
        for(int i=0; i<n; i++){
            for(int x=0; x<=5; x++){
                for(int y=0; y<=5; y++){
                    if(!~f[i][x][y])continue;
                    int p=x, q=y;
                    if(p<5 && a[i]==pos[p])p++;
                    if(q<5 && a[i]==neg[q])q++;
                    if(!~f[i+1][p][q]){
                        f[i+1][p][q]=0;
                        g[i+1][p][q]=x;
                        h[i+1][p][q]=y;
                    }
                    for(int k=1; p+k<=5; k++){
                        if(q<5 && pos[p+k-1]==neg[q])q++;
                        if(!~f[i+1][p+k][q]){
                            //fprintf(stderr, "(%d, %d, %d) => (%d, %d, %d) with %d\n", i, x, y, i+1, p+k, q, k);
                            f[i+1][p+k][q]=k;
                            g[i+1][p+k][q]=x;
                            h[i+1][p+k][q]=y;
                        }
                    }
                }
            }
        }
        for(int y=0; y<5; y++){
            if(~f[n][5][y]){
                return track(5, y);
            }
        }
        return "";
    }
};

// CUT begin
ifstream data("OnlySanta.sample");

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

bool do_test(string S, string __expected) {
    time_t startClock = clock();
    OnlySanta *instance = new OnlySanta();
    string __result = instance->solve(S);
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
        string __answer;
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
        int T = time(NULL) - 1515636005;
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
        cout << "OnlySanta (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
