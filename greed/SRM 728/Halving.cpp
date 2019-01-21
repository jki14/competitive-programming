#include "bits/stdc++.h"
using namespace std;

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

class Halving {
    private:
    void cut(const int len, unordered_map<int, int> &goo){
        queue<int> que;
        goo.insert(MP(len, 0));
        que.push(len);
        for(; !que.empty(); que.pop()){
            int cur=que.front();
            int dis=goo[cur];
            if(cur&1){
                //odd
                int x=cur>>1;
                int y=cur-x;
                if(x>0 && !goo.count(x)){
                    goo.insert(MP(x, dis+1));
                    que.push(x);
                }
                if(y>0 && !goo.count(y)){
                    goo.insert(MP(y, dis+1));
                    que.push(y);
                }
            }else{
                //even
                int x=cur>>1;
                if(x>0 && !goo.count(x)){
                    goo.insert(MP(x, dis+1));
                    que.push(x);
                }
            }
        }
    }
    public:
    int minSteps(vector<int> a) {
        unordered_map<int, int> foo;
        unordered_map<int, int> goo;
        int n=SIZE(a);
        foo.clear();
        cut(a[0], foo);
        for(int i=1; i<n; i++){
            goo.clear();
            cut(a[i], goo);
            for(unordered_map<int, int>::iterator it=foo.begin(); it!=foo.end(); ){
                unordered_map<int, int>::const_iterator it2=goo.find(it->first);
                if(it2!=goo.end()){
                    it->second+=it2->second;
                    it++;
                }else{
                    it=foo.erase(it);
                }
            }
        }
        int res=0x3f3f3f3f;
        for(unordered_map<int, int>::const_iterator it=foo.begin(); it!=foo.end(); it++){
            UPDMIN(res, it->second);
        }
        return res;
    }
};

// CUT begin
ifstream data("Halving.sample");

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

bool do_test(vector<int> a, int __expected) {
    time_t startClock = clock();
    Halving *instance = new Halving();
    int __result = instance->minSteps(a);
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
        vector<int> a;
        from_stream(a);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(a, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1516896005;
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
        cout << "Halving (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
