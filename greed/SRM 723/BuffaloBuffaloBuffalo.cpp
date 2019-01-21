#include "bits/stdc++.h"
using namespace std;

//HEAD_OF_CONFIG_

static const int MOD=1000000007; //1000000000000000003LL
static const double eps=1e-8;

//TAIL_OF_CONFIG_

//HEAD_OF_JKI'S_HEADER_

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

    //REMINDER-LIZATION
    template<class T> inline T MOD_STD(const T x, const T m=MOD){ return (x%m+m)%m; }
    template<class T> inline void MOD_STD(T *x, const T m=MOD){ *x=(*x%m+m)%m; }
    template<class T> inline T MOD_ADD(const T x, const T y, const T m=MOD){ return (x+y)%m; }
    template<class T> inline void MOD_ADD(T *x, const T y, const T m=MOD){ *x=(*x+y)%m; }

//TAIL_OF_JKI'S_HEADER

const char buffalo[8]="buffalo";

int g[15][15][29][15][15][15];
int v[15][15][29][15][15][15];

struct state_t{
    int b, u, f, a, l, o;
    int p;
    state_t(const int _b=0, const int _u=0, const int _f=0, const int _a=0, const int _l=0, const int _o=0, const int _p=-1){
        this->b=_b;
        this->u=_u;
        this->f=_f;
        this->a=_a;
        this->l=_l;
        this->o=_o;
        if(~_p){
            this->p=_p;
        }else{
            this->p=this->b+this->u+this->f+this->a+this->l+this->o;
        }
    }
};
queue<state_t> seq;

int n, m;
char s[128];

class BuffaloBuffaloBuffalo {
    public:
    int count(string pattern) {
        n=LENGTH(pattern);
        for(int i=0; i<n; i++)
            s[i]=pattern[i];
        if((n%7)==0){
            m=n/7;
            memset(g, 0, sizeof(g));
            g[0][0][0][0][0][0]=1;
            memset(v, 0, sizeof(v));
            v[0][0][0][0][0][0]=1;
            while(!seq.empty())seq.pop();
            seq.push(state_t(0, 0, 0, 0, 0, 0, 0));
            for(; !seq.empty(); seq.pop()){
                state_t *curr=&seq.front();
                if(curr->p==n)continue;
                if(s[curr->p]=='?'){
                    state_t next=*curr;
                    next.p++;
                    
                    next.b++;
                    if(next.b<=m){
                        if(!v[next.b][next.u][next.f][next.a][next.l][next.o]){
                            v[next.b][next.u][next.f][next.a][next.l][next.o]=1;
                            seq.push(next);
                        }
                        MOD_ADD(&g[next.b][next.u][next.f][next.a][next.l][next.o], g[curr->b][curr->u][curr->f][curr->a][curr->l][curr->o]);
                    }
                    next.b--;

                    next.u++;
                    if(next.u<=next.b){
                        if(!v[next.b][next.u][next.f][next.a][next.l][next.o]){
                            v[next.b][next.u][next.f][next.a][next.l][next.o]=1;
                            seq.push(next);
                        }
                        MOD_ADD(&g[next.b][next.u][next.f][next.a][next.l][next.o], g[curr->b][curr->u][curr->f][curr->a][curr->l][curr->o]);
                    }
                    next.u--;

                    next.f++;
                    if(next.f<=(next.u<<1)){
                        if(!v[next.b][next.u][next.f][next.a][next.l][next.o]){
                            v[next.b][next.u][next.f][next.a][next.l][next.o]=1;
                            seq.push(next);
                        }
                        MOD_ADD(&g[next.b][next.u][next.f][next.a][next.l][next.o], g[curr->b][curr->u][curr->f][curr->a][curr->l][curr->o]);
                    }
                    next.f--;
                    
                    next.a++;
                    if(next.a<=(next.f>>1)){
                        if(!v[next.b][next.u][next.f][next.a][next.l][next.o]){
                            v[next.b][next.u][next.f][next.a][next.l][next.o]=1;
                            seq.push(next);
                        }
                        MOD_ADD(&g[next.b][next.u][next.f][next.a][next.l][next.o], g[curr->b][curr->u][curr->f][curr->a][curr->l][curr->o]);
                    }
                    next.a--;
                    
                    next.l++;
                    if(next.l<=next.a){
                        if(!v[next.b][next.u][next.f][next.a][next.l][next.o]){
                            v[next.b][next.u][next.f][next.a][next.l][next.o]=1;
                            seq.push(next);
                        }
                        MOD_ADD(&g[next.b][next.u][next.f][next.a][next.l][next.o], g[curr->b][curr->u][curr->f][curr->a][curr->l][curr->o]);
                    }
                    next.l--;

                    next.o++;
                    if(next.o<=next.l){
                        if(!v[next.b][next.u][next.f][next.a][next.l][next.o]){
                            v[next.b][next.u][next.f][next.a][next.l][next.o]=1;
                            seq.push(next);
                        }
                        MOD_ADD(&g[next.b][next.u][next.f][next.a][next.l][next.o], g[curr->b][curr->u][curr->f][curr->a][curr->l][curr->o]);
                    }
                    next.o--;

                }else{
                    state_t next=*curr;
                    if(s[curr->p]=='b'){
                        next.b++;
                        if(next.b>m)continue;
                    }else if(s[curr->p]=='u'){
                        next.u++;
                        if(next.u>next.b)continue;
                    }else if(s[curr->p]=='f'){
                        next.f++;
                        if(next.f>(next.u<<1))continue;
                    }else if(s[curr->p]=='a'){
                        next.a++;
                        if(next.a>(next.f>>1))continue;
                    }else if(s[curr->p]=='l'){
                        next.l++;
                        if(next.l>next.a)continue;
                    }else if(s[curr->p]=='o'){
                        next.o++;
                        if(next.o>next.l)continue;
                    }
                    next.p++;
                    if(!v[next.b][next.u][next.f][next.a][next.l][next.o]){
                        v[next.b][next.u][next.f][next.a][next.l][next.o]=1;
                        seq.push(next);
                    }
                    MOD_ADD(&g[next.b][next.u][next.f][next.a][next.l][next.o], g[curr->b][curr->u][curr->f][curr->a][curr->l][curr->o]);
                }
            }
            return MOD_STD(g[m][m][m+m][m][m][m]);
        }else{
            return 0;
        }
    }
};

// CUT begin
ifstream data("BuffaloBuffaloBuffalo.sample");

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

bool do_test(string pattern, int __expected) {
    time_t startClock = clock();
    BuffaloBuffaloBuffalo *instance = new BuffaloBuffaloBuffalo();
    int __result = instance->count(pattern);
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
        string pattern;
        from_stream(pattern);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(pattern, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1511025611;
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
        cout << "BuffaloBuffaloBuffalo (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
