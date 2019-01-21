#include "bits/stdc++.h"
using namespace std;

#define N 51000
#define M 110000
#define Q 110000
#define Q2 210000

struct request_t{
    int u, v, a;
    int x, y;
    int offset;
} request[Q];

int n, q, root;
int c[N];
int nbs[N], nxt[M], dst[M], eid;
int pos[N], foo[N], til;
int seq[M], cnt, current;
int ans[Q];
int f[N];
int vec[Q], zik[Q2], qid;
request_t *req[Q2];

//map<int, int> dict;

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
    return lhs.v<rhs.v;
}

inline int dcmp(const int lhs, const int rhs){
    return c[lhs]<c[rhs];
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

void process(int u, int v, const int k){
    //printf("process %d %d %d\n", u, v, k);
    if(u==v)return;
    u=pos[u];
    v=pos[v];
    if(u<v){
        for(int i=u+1; ; i++){
            //printf("(%d)\n", seq[i]*k);
            if(seq[i]*k>0){
                if(!(foo[abs(seq[i])]++)){
                    current++;
                }
            }else{
                if(!(--foo[abs(seq[i])])){
                    current--;
                }
            }
            if(i==v)break;
        }
    }else{
        for(int i=u; i!=v; i--){
            //printf("(%d)\n", seq[i]*k*-1);
            if(seq[i]*k*-1>0){
                if(!(foo[abs(seq[i])]++)){
                    current++;
                }
            }else{
                if(!(--foo[abs(seq[i])])){
                    current--;
                }
            }
        }
    }
}

int main(){
    while(scanf("%d%d", &n, &q)!=EOF){
        //dict.clear();
        for(int i=0; i<n; i++){
            scanf("%d", &c[i]);
        }
        for(int i=0; i<n; i++)nbs[i]=-1;
        eid=0;
        for(int i=0; i<n; i++){
            int u, v;
            scanf("%d%d", &u, &v);
            if(u==0 || v==0){
                root=(u|v)-1;
                continue;
            }
            u--; v--;
            add_edge(u, v);
        }
        for(int i=0; i<q; i++){
            scanf("%d%d%d%d", &request[i].u, &request[i].v, &request[i].x, &request[i].y);
            if(request[i].x==request[i].y){
                request[i].x=request[i].y=0;
            }
            request[i].u--;
            request[i].v--;
            request[i].offset=i;
            request[i].a=-1;
        }
        til=0;
        build(root, -1);
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
        tarjan(root, -1);
        for(int i=0; i<=n; i++)foo[i]=0;
        current=1;foo[c[root]]++;
        //printf("(%d)\n", c[0]);
        for(int i=0; i<q; i++){
            process((i>0)?request[i-1].u:0, request[i].u, 1);
            process((i>0)?request[i-1].v:0, request[i].v, 1);
            process((i>0)?request[i-1].a:0, request[i].a, -1);
            ans[request[i].offset]=current-(foo[request[i].x]&&foo[request[i].y]);
        }
        for(int i=0; i<q; i++)printf("%d\n", ans[i]);
    }
    return 0;
}
