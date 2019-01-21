#include "bits/stdc++.h"
using namespace std;

#define N 41000
#define M 81000
#define Q 110000
#define Q2 210000

struct request_t{
    int u, v, a;
    int offset;
} request[Q];

int n, m, q;
int c[N];
int nbs[N], nxt[M], dst[M], eid;
int pos[N], foo[N], til;
int seq[M], cnt, current;
int ans[Q];
int f[N];
int vec[Q], zik[Q2], qid;
request_t *req[Q2];

map<int, int> dict;

inline void add_edge(const int u, const int v){
    nxt[eid]=nbs[u]; dst[eid]=v; nbs[u]=eid++;
    nxt[eid]=nbs[v]; dst[eid]=u; nbs[v]=eid++;
}

inline void add_query(const int u, const int v, const int q){
    zik[qid]=vec[u]; req[qid]=&request[q]; vec[u]=qid++;
    zik[qid]=vec[v]; req[qid]=&request[q]; vec[v]=qid++;
}

inline int cmp(const request_t &lhs, const request_t &rhs){
    const int lc=pos[lhs.u]/cnt;
    const int rc=pos[rhs.u]/cnt;
    if(lc!=rc)return lc<rc;
    return pos[lhs.v]<pos[rhs.v];
}

inline int find(const int u){ if(f[u]!=u)f[u]=find(f[u]); return f[u]; }

void build(const int u, const int p){
    pos[u]=til;
    seq[til++]=c[u];
    for(int i=nbs[u]; ~i; i=nxt[i]){
        const int v=dst[i];
        if(v==p)continue;
        build(v, u);
    }
    seq[til++]=-c[u];
}

void tarjan(const int u, const int p){
    f[u]=u;
    for(int i=nbs[u]; ~i; i=nxt[i]){
        const int v=dst[i];
        if(v==p)continue;
        tarjan(v, u);
        f[v]=u;
    }
    //for(auto req:hook[u]){
    for(int i=vec[u]; ~i; i=zik[i]){
        const int v=req[i]->u^req[i]->v^u;
        if(~f[v] && !~req[i]->a){
            req[i]->a=find(f[v]);
        }
    }
}

void process(int u, int v){
    if(u==v)return;
    //printf("process %d %d\n", u, v);
    u=pos[u];
    v=pos[v];
    if(u<v){
        for(int i=u+1; ; i++){
            //printf("(%d)\n", seq[i]);
            if(seq[i]>0){
                if(!foo[abs(seq[i])])current++;
                foo[abs(seq[i])]++;
                if(!foo[abs(seq[i])])current--;
            }else{
                if(!foo[abs(seq[i])])current++;
                foo[abs(seq[i])]--;
                if(!foo[abs(seq[i])])current--;
            }
            //assert(foo[abs(seq[i])]>=0);
            if(i==v)break;
        }
    }else{
        for(int i=u; i!=v; i--){
            //printf("(%d)\n", seq[i]*-1);
            if(seq[i]>0){
                if(!foo[abs(seq[i])])current++;
                foo[abs(seq[i])]--;
                if(!foo[abs(seq[i])])current--;
            }else{
                if(!foo[abs(seq[i])])current++;
                foo[abs(seq[i])]++;
                if(!foo[abs(seq[i])])current--;
            }
            //assert(foo[abs(seq[i])]>=0);
        }
    }
}

void process2(int u, int v){
    if(u==v)return;
    //printf("process2 %d %d\n", u, v);
    u=pos[u];
    v=pos[v];
    if(u<v){
        for(int i=u; ; i++){
            //printf("(%d)\n", seq[i]);
            if(seq[i]>0){
                if(!foo[abs(seq[i])])current++;
                foo[abs(seq[i])]-=(i!=u && i!=v)?2:1;
                if(!foo[abs(seq[i])])current--;
            }else{
                if(!foo[abs(seq[i])])current++;
                foo[abs(seq[i])]+=(i!=u && i!=v)?2:1;
                if(!foo[abs(seq[i])])current--;
            }
            //assert(foo[abs(seq[i])]>=0);
            if(i==v)break;
        }
    }else{
        for(int i=u; ; i--){
            //printf("(%d)\n", seq[i]);
            if(seq[i]>0){
                if(!foo[abs(seq[i])])current++;
                foo[abs(seq[i])]+=(i!=u && i!=v)?2:1;
                if(!foo[abs(seq[i])])current--;
            }else{
                if(!foo[abs(seq[i])])current++;
                foo[abs(seq[i])]-=(i!=u && i!=v)?2:1;
                if(!foo[abs(seq[i])])current--;
            }
            //assert(foo[abs(seq[i])]>=0);
            if(i==v)break;
        }
    }
}

int main(){
    while(scanf("%d%d", &n, &q)!=EOF){
        dict.clear();
        for(int i=0; i<n; i++){
            scanf("%d", &c[i]);
            dict.insert(make_pair(c[i], 0));
        }
        for(int i=0; i<n; i++)nbs[i]=-1;
        eid=0;
        for(int i=1; i<n; i++){
            int u, v;
            scanf("%d%d", &u, &v);
            u--; v--;
            add_edge(u, v);
        }
        for(int i=0; i<q; i++){
            scanf("%d%d", &request[i].u, &request[i].v);
            request[i].u--;
            request[i].v--;
            request[i].offset=i;
            request[i].a=-1;
        }
        m=0;
        for(map<int, int>::iterator it=dict.begin(); it!=dict.end(); it++){
            it->second=++m;
        }
        for(int i=0; i<n; i++){
            c[i]=dict[c[i]];
        }
        til=0;
        build(0, -1);
        cnt=max((int)sqrt(n*2.0), 1);
        sort(request, request+q, cmp);
        for(int i=0; i<n; i++)vec[i]=-1;
        qid=0;
        for(int i=0; i<q; i++){
            //hook[request[i].u].push_back(&request[i]);
            //hook[request[i].v].push_back(&request[i]);
            add_query(request[i].u, request[i].v, i);
        }
        for(int i=0; i<n; i++)f[i]=-1;
        tarjan(0, -1);
        for(int i=1; i<=m; i++)foo[i]=0;
        current=1;foo[c[0]]++;
        //printf("(%d)\n", c[0]);
        for(int i=0; i<q; i++){
            //printf("request[%d] %d, %d, %d\n", i, request[i].u, request[i].v, request[i].a);
            process((i>0)?request[i-1].u:0, request[i].u);
            process((i>0)?request[i-1].v:0, request[i].v);
            process2((i>0)?request[i-1].a:0, request[i].a);
            ans[request[i].offset]=current;
        }
        for(int i=0; i<q; i++)printf("%d\n", ans[i]);
    }
    return 0;
}
