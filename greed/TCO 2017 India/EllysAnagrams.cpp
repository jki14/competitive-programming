#include "bits/stdc++.h"
using namespace std;

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

//TAIL_OF_JKI'S_HEADER

const int inf=0x3f3f3f3f;

class MinimumCostFlow{
    private:
    int maxv, maxe;
    struct mcf_edge_t{
        int dest;
        mcf_edge_t *next, *dual;
        int cap, cost;
        int flow;
    } **head, *pool, *tail, **prev;
    int *dist, *vst, *que;
    inline int roll(int &offset){
        int cache=offset;
        offset=(offset+1)%this->maxv;
        return cache;
    }
    int spfa(const int s, const int t){
        int lef=0, rig=0;
        for(int i=0; i<this->maxv; i++){
            this->dist[i]=inf;
            this->vst[i]=0;
            this->prev[i]=NULL;
        }
        this->dist[s]=0;
        this->vst[s]=1;
        que[this->roll(rig)]=s;
        while(lef!=rig){
            int u=que[this->roll(lef)];
            this->vst[u]=0;
            for(mcf_edge_t *edge=this->head[u]; edge!=NULL; edge=edge->next){
                int v=edge->dest;
                if(edge->cap>edge->flow && this->dist[v]>this->dist[u]+edge->cost){
                    this->dist[v]=this->dist[u]+edge->cost;
                    this->prev[v]=edge;
                    if(!this->vst[v]){
                        this->que[this->roll(rig)]=v;
                        this->vst[v]=1;
                    }
                }
            }
        }
        return this->prev[t]!=NULL;
    }
    public:
    MinimumCostFlow(const int numv=11000, const int nume=110000){
        this->maxv=numv;
        this->maxe=nume<<1;
        this->pool=(mcf_edge_t*)malloc(sizeof(mcf_edge_t)*nume*2);
        this->head=(mcf_edge_t**)malloc(sizeof(mcf_edge_t*)*numv);
        this->tail=this->pool;
        this->prev=(mcf_edge_t**)malloc(sizeof(mcf_edge_t*)*numv);
        this->dist=(int*)malloc(sizeof(int)*numv);
        this->vst=(int*)malloc(sizeof(int)*numv);
        this->que=(int*)malloc(sizeof(int)*numv);
    };
    ~MinimumCostFlow(){
        free(this->que);
        free(this->vst);
        free(this->dist);
        free(this->prev);
        free(this->head);
        free(this->pool);
    }
    void reset(){
        for(int i=0; i<this->maxv; i++){
            this->head[i]=NULL;
        }
        this->tail=this->pool;
    }
    void add_edge(const int u, const int v, const int cap, const int cost){
        assert(u<this->maxv && v<this->maxv);
        assert(this->tail-this->pool<this->maxe);
        this->tail->next=this->head[u];
        this->tail->dual=this->tail+1;
        this->tail->dest=v;
        this->tail->cap=cap;
        this->tail->cost=cost;
        this->tail->flow=0;
        this->head[u]=this->tail++;
        this->tail->next=this->head[v];
        this->tail->dual=this->tail-1;
        this->tail->dest=u;
        this->tail->cap=0;
        this->tail->cost=-cost;
        this->tail->flow=0;
        this->head[v]=this->tail++;
    }
    pii run(const int s, const int t){
        assert(s<this->maxv && t<this->maxv);
        int flow=0, cost=0;
        while(spfa(s, t)){
            int foo=inf;
            for(mcf_edge_t *edge=this->prev[t]; edge!=NULL; edge=this->prev[edge->dual->dest]){
                UPDMIN(foo, edge->cap-edge->flow);
            }
            flow+=foo;
            for(mcf_edge_t *edge=this->prev[t]; edge!=NULL; edge=this->prev[edge->dual->dest]){
                edge->flow+=foo;
                edge->dual->flow-=foo;
                cost+=edge->cost*foo;
            }
        }
        return MP(flow, cost);
    }
};

MinimumCostFlow mcf(256, 6100);

inline int dist(const int x, const int y){
    return ((y-x)%26+26)%26;
}

class EllysAnagrams {
    public:
    int getCount(string A, string B) {
        int n=A.length();
        int src=n*2;
        int dst=src+1;
        mcf.reset();
        for(int i=0; i<n; i++){
            mcf.add_edge(src, i, 1, 0);
            mcf.add_edge(n+i, dst, 1, 0);
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                mcf.add_edge(i, n+j, 1, dist(A[i]-'A', B[j]-'A'));
            }
        }
        return mcf.run(src, dst).second;
    }
};

// CUT begin
ifstream data("EllysAnagrams.sample");

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

bool do_test(string A, string B, int __expected) {
    time_t startClock = clock();
    EllysAnagrams *instance = new EllysAnagrams();
    int __result = instance->getCount(A, B);
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
        string A;
        from_stream(A);
        string B;
        from_stream(B);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(A, B, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1503219946;
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
        cout << "EllysAnagrams (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
