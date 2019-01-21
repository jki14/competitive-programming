#include "bits/stdc++.h"
using namespace std;

//[HEAD_OF_JKI'S_HEADER_

    typedef long long lld;

    int *PRIMELIST(const int til, int *length=NULL){
        int *foo=(int*)malloc(sizeof(int)*(til+1));
        int len=0;
        memset(foo, 0, sizeof(int)*(til+1));
        for(int i=2; i<=til; i++){
            if(!foo[i])foo[len++]=i;
            for(int j=0; j<len && foo[j]<=til/i; j++){
                foo[foo[j]*i]=1;
                if(i%foo[j]==0)break;
            }
        }
        if(length!=NULL){
            *length=len;
        }
        foo[len++]=0;
        foo=(int*)realloc(foo, sizeof(int)*len);
        return foo;
    }

//]TAIL_OF_JKI'S_HEADER

int *primeList, n;
int seq[32], m;
int bit[32];

class TheRoundCityDiv1 {
    private:
    int find(const lld square){
        lld lef=0LL, rig=1000000LL;
        while(lef<=rig){
            lld mid=(lef+rig)>>1;
            if(mid*mid<=square){
                if(mid==rig || (mid+1LL)*(mid+1LL)>square)return (int)mid;
                lef=mid+1LL;
            }else{
                rig=mid-1LL;
            }
        }
        return -1;
    }
    public:
    TheRoundCityDiv1(){
        primeList=PRIMELIST(1000000, &n);
        for(int i=0; i<30; i++)bit[i]=1<<i;
    }
    ~TheRoundCityDiv1(){
        free(primeList);
    }
    long long find(int r) {
        lld foo=1LL;
        for(int dx=1; dx<=r; dx++){
            //get seq
            m=0;
            int tmp=dx;
            for(int i=0; primeList[i]*primeList[i]<=tmp; i++){
                if(tmp%primeList[i]){
                    continue;
                }else{
                    while(!(tmp%primeList[i]))tmp/=primeList[i];
                    seq[m++]=primeList[i];
                }
            }
            if(tmp>1){
                seq[m++]=tmp;
            }
            //get gap
            int gap=this->find(r*1LL*r-dx*1LL*dx);
            //exclusive
            //lld lastFoo=foo;
            for(int i=0; i<bit[m]; i++){
                int cnt=0, val=1;
                for(int j=0; j<m; j++){
                    if(i&bit[j]){
                        cnt++;
                        val*=seq[j];
                    }
                }
                if(val>gap)continue;
                if(cnt&1){
                    foo-=gap/val;
                    //fprintf(stderr, " -%d (%d)\n", gap/val, val);
                }else{
                    foo+=gap/val;
                    //fprintf(stderr, " +%d (%d)\n", gap/val, val);
                }
            }
            //fprintf(stderr, "%d, [1, %d] %lld\n", dx, gap, foo-lastFoo);
        }
        foo*=4LL;
        return foo;
    }
};

// CUT begin
ifstream data("TheRoundCityDiv1.sample");

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

bool do_test(int r, long long __expected) {
    time_t startClock = clock();
    TheRoundCityDiv1 *instance = new TheRoundCityDiv1();
    long long __result = instance->find(r);
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
        int r;
        from_stream(r);
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(r, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1526519253;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 300 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "TheRoundCityDiv1 (300 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
