#include "bits/stdc++.h"
using namespace std;

//[HEAD_OF_JKI'S_HEADER_

    //TYPEDEF
    typedef long long lld;
    typedef unsigned long long u64;
    typedef pair<int, int> pii;

//]TAIL_OF_JKI'S_HEADER

const lld modl=2147483648LL;

lld a[110000];
int n;
lld m;
lld foo;

lld process(lld *a, const int n){
    lld foo=0LL;
    lld cur=1LL;
    int l=0;
    int x=0, y=0;
    for(int r=0; r<n; r++){
        cur*=a[r];
        while(llabs(cur)>m){
            x++;
            if(a[l]<0LL){
                swap(x, y);
            }
            cur/=a[l++];
        }
        //absolute-range
        foo+=r-l+1;
        //negative-range
        if(cur<0LL){
            //fprintf(stderr, "+x=%d, y=%d, cur=%lld\n", x, y, cur);
            foo+=x;
        }else{
            //fprintf(stderr, "x=%d, +y=%d, cur=%lld\n", x, y, cur);
            foo+=y;
        }
    }
    return foo;
}

class ProductThreshold {
    public:
    long long subarrayCount(int N, int limit, vector<int> Aprefix, int spread, int offset) {
        //init
        n=N;
        m=limit;
        int p=Aprefix.size();
        for(int i=0; i<p; i++){
            a[i]=Aprefix[i];
        }
        lld seed=llabs(a[p-1]);
        for(int i=p; i<n; i++){
            seed=(seed*1103515245LL+12345LL)%modl;
            a[i]=(seed%spread)+offset*1LL;
        }
        //go
        foo=0LL;
        int x=0;
        for(int i=0; i<n; i++){
            if(a[i]==0LL){
                foo+=(x+1)*1LL*(n-i);
                if(x>0){
                    foo+=process(a+(i-x), x);
                }
                x=0;
            }else{
                x++;
            }
        }
        if(x>0){
            foo+=process(a+(n-x), x);
        }
        return foo;
    }
};

// CUT begin
ifstream data("ProductThreshold.sample");

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

bool do_test(int N, int limit, vector<int> Aprefix, int spread, int offset, long long __expected) {
    time_t startClock = clock();
    ProductThreshold *instance = new ProductThreshold();
    long long __result = instance->subarrayCount(N, limit, Aprefix, spread, offset);
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
        int N;
        from_stream(N);
        int limit;
        from_stream(limit);
        vector<int> Aprefix;
        from_stream(Aprefix);
        int spread;
        from_stream(spread);
        int offset;
        from_stream(offset);
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(N, limit, Aprefix, spread, offset, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1530979939;
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
        cout << "ProductThreshold (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
