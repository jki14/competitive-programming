#include<iostream>
#include<cstdio>
using namespace std;

#define N 110000
#define C 10

int n,m,g[C],pre[N],f[N],que[N];
int lef,rig;

void pout(const int &u){
    if(pre[u]>=0)pout(pre[u]);
    printf("%d",f[u]);
}

int main(){int T=0;
    while(scanf("%d",&n)!=EOF && n){printf("Case %d: ",++T);
        scanf("%d",&m);memset(g,0,sizeof(g));int flag=1;
        for(int i=0;i<m;i++){ int x;scanf("%d",&x);g[x]=1; }
        memset(f,0xff,sizeof(f));
        lef=rig=0;for(int i=1;i<C;i++){if(g[i])continue;
            int nex=i%n;
            if(nex==0){ printf("%d\n",i);flag=0;break; }
            if(f[nex]==-1){ que[rig++]=nex;f[nex]=i;pre[nex]=-1; }
        }
        for(;lef<rig && flag;lef++){
            int u=que[lef],x=f[u];
            for(int i=0;i<C;i++){if(g[i])continue;
                int nex=(u*10+i)%n;
                if(f[nex]==-1){ que[rig++]=nex;f[nex]=i;pre[nex]=u; }
                if(!nex){ pout(nex);printf("\n");flag=0;break; }
            }
        }
        if(flag)printf("-1\n");
    }
    return 0;
}