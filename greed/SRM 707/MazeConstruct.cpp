#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
using namespace std;

vector<string> ans;

class MazeConstruct {
    public:
    vector<string> construct(int k) {
        ans.clear();
        for(int n=1; n<=50; n+=4){
            for(int m=1; m<=50; m+=1){
                int top=(n+1)/2*m+n/2;
                if(top<k+1)continue;
                int red=top-(k+1);
                if((red&1) || ((m-1)-(m+1)/2)*(n/2)<red/2)continue;
                for(int i=0; i<n; i++){
                    ans.push_back(string(m, '.'));
                }
                for(int i=1; i<n; i+=4){
                    for(int j=0; j<m-1; j++){
                        ans[i][j]='#';
                    }
                }
                for(int i=3; i<n; i+=4){
                    for(int j=1; j<m; j++){
                        ans[i][j]='#';
                    }
                }
                int r=1, c=m-2;
                while(red){
                    if((r-1)%4==0){
                        if(c>=(m+1)/2){
                            ans[r][c]='.';
                            c--;
                            red-=2;
                            continue;
                        }
                    }else{
                        if(c+1<(m+1)/2){
                            ans[r][c]='.';
                            c++;
                            red-=2;
                            continue;
                        }
                    }
                    r+=2;
                    if((r-1)%4==0){
                        c=m-2;
                    }else{
                        c=1;
                    }
                }
                break;
            }
            if(!ans.empty())break;
        }
        return ans;
    }
};

// CUT begin
/*ifstream data("MazeConstruct.sample");

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

bool do_test(int k, vector<string> __expected) {
    time_t startClock = clock();
    MazeConstruct *instance = new MazeConstruct();
    vector<string> __result = instance->construct(k);
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
        int k;
        from_stream(k);
        next_line();
        vector<string> __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(k, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1485828007;
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
        cout << "MazeConstruct (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}*/

const int inf=0x3f3f3f3f;

int f[64][64];

inline void UPDMIN(int &x, const int y){ if(x>y)x=y; }

int run(const int x, const int y, const vector<string> &foo){
    if(x<0 || x>=(int)foo.size())return inf;
    if(y<0 || y>=(int)foo[0].length())return inf;
    if(~f[x][y])return f[x][y];
    int &res=f[x][y];
    res=inf;
    if(foo[x][y]=='.'){
        UPDMIN(res, run(x+1, y, foo)+1);
        UPDMIN(res, run(x-1, y, foo)+1);
        UPDMIN(res, run(x, y+1, foo)+1);
        UPDMIN(res, run(x, y-1, foo)+1);
    }
    return res;
}

int calc(const vector<string> &foo){
    const int n=foo.size();
    const int m=foo[0].length();
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            f[i][j]=-1;
        }
    }
    f[0][0]=0;
    return run(n-1, m-1, foo);
}

int main(int argc, char *argv[]) {
    MazeConstruct *foo=new MazeConstruct();
    for(int k=2; k<=1000; k++){
        vector<string> ans=foo->construct(k);
        if(ans.empty() || calc(ans)!=k){
            printf("Error %d(%d)\n", k, calc(ans));
        }
    }
    delete foo;
    return 0;
}

// CUT end
