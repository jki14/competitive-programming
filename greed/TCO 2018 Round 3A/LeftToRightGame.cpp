#include "bits/stdc++.h"
using namespace std;

int n, d;
int f[1024][1024];

int process(const int taken, const int reminder){
    if(~f[taken][reminder])return f[taken][reminder];
    int &foo=f[taken][reminder];
    if(taken==n){
        if((taken&1)==0){
            //alice 
            return foo=(reminder!=0);
        }else{
            //bob
            return foo=(reminder==0);
        }
    }else{
        if((taken&1)==0){
            //alice
            for(int i=0; i<10; i++){
                if(taken==0 && i==0)continue;
                if(!process(taken+1, (reminder*10+i)%d))return foo=1;
            }
            return foo=0;
        }else{
            //bob
            for(int i=0; i<10; i++){
                if(taken==0 && i==0)continue;
                if(!process(taken+1, (reminder*10+i)%d))return foo=1;
            }
            return foo=0;
        }
    }
}

class LeftToRightGame {
    public:
    string whoWins(int length, int divisor) {
        memset(f, 0xff, sizeof(f));
        n = length;
        d = divisor;
        if(process(0, 0)){
            return "Alice";
        }else{
            return "Bob";
        }
    }
};

// CUT begin
ifstream data("LeftToRightGame.sample");

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

bool do_test(int length, int divisor, string __expected) {
    time_t startClock = clock();
    LeftToRightGame *instance = new LeftToRightGame();
    string __result = instance->whoWins(length, divisor);
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
        int length;
        from_stream(length);
        int divisor;
        from_stream(divisor);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(length, divisor, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1530979222;
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
        cout << "LeftToRightGame (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
