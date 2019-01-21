#include "bits/stdc++.h"
using namespace std;

inline void updmax(int &x, const int y){ if(x<y)x=y; }
inline void updmax(double &x, const double y){ if(x<y)x=y; }

const double eps=1e-9;

int n, m;
int w[1100], p[1100];

int f[2][110000];

struct queue_t{
    int foo[110000];
    int lef, rig;
    void clear(){
        this->lef=this->rig=0;
    }
    void push(const int x){
        this->foo[this->rig++]=x;
    }
    int pop(){
        if(this->lef<this->rig){
            return this->foo[this->lef++];
        }else{
            return -1;
        }
    }
} que[2];

int last[110000];

int main(){
    while(scanf("%d%d", &n, &m)!=EOF){
        for(int i=0; i<n; i++){
            scanf("%d%d", &p[i], &w[i]);
        }
        int cur=0;
        f[cur][0]=0;
        que[cur].clear();
        que[cur].push(0);
        memset(last, 0xff, sizeof(last));
        for(int i=0; i<n; i++){
            const int prv=cur;
            cur^=1;
            que[cur].clear();
            while(true){
                int x=que[prv].pop();
                if(!~x)break;
                updmax(f[cur][x], f[prv][x]);
                if(last[x]!=i+1){
                    que[cur].push(x);
                    last[x]=i+1;
                }
                if(x+p[i]<m+1000){
                    if(last[x+p[i]]!=i+1){
                        que[cur].push(x+p[i]);
                        last[x+p[i]]=i+1;
                    }
                    updmax(f[cur][x+p[i]], f[prv][x]+w[i]);
                }
            }
        }
        double ans=-1.0;
        while(true){
            int x=que[cur].pop();
            if(!~x)break;
            if(x>=m){
                updmax(ans, f[cur][x]*1.0/x);
            }
        }
        if(ans<-eps){
            printf("-1\n");
        }else{
            printf("%.6f\n", ans);
        }
    }
    return 0;
}
