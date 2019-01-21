//============================================================================
// Name        : ChairTree_COT2
// Author      : Seter
// Version     : 1.00
// Copyright   : WangZhe (Chongqing University Computer College)
// Description : SPOJ COT2; 给定一棵点权树，询问指定两个节点路径上的点权种数
//============================================================================

#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<algorithm>
#define N 40000
struct EDGE{EDGE*next;int y;};
inline int getint(){
    int re;char ch;
    while(!isdigit(ch=getchar()));re=ch-48;
    while(isdigit(ch=getchar()))re=re*10+ch-48;
    return re;
}using namespace std;
int n,m,num[N],que[N];bool v[N];
namespace COT2{
    EDGE*map[N],st[N<<1],*stp=st;
    int a[N];
    inline void ADDEDGE(int x,int y){
        stp->next=map[x];num[(map[x]=stp++)->y=y]++;
        stp->next=map[y];num[(map[y]=stp++)->y=x]++;
    }inline void Init(){
        int i=n=getint();m=getint();
        static pair<int,int>R[N];
        for(i=-1;++i!=n;)R[i]=make_pair(getint(),i);
        sort(R,R+n);
        for(a[R[0].second]=i=0;++i!=n;)a[R[i].second]=a[R[i-1].second]+(R[i].first!=R[i-1].first);
        while(--i)ADDEDGE(getint()-1,getint()-1);
    }
}namespace Prep{
    int f[N],d[N];
    void Init(int x){for(EDGE*p=COT2::map[x];p;p=p->next)if(f[x]!=p->y)d[p->y]=d[f[p->y]=x]+1,Init(p->y);}
    inline int Stupid(int x,int y){
        if(d[x]>d[y])swap(x,y);
        int px=x,py=y,ans=0;
#define Jump(x) ans+=!v[COT2::a[x]],v[COT2::a[x]]=1,x=f[x]
        while(d[x]!=d[y])Jump(y);
        while(x!=y)Jump(x),Jump(y);
        ans+=!v[COT2::a[x]];
        while(px!=x)v[COT2::a[px]]=0,px=f[px];
        while(py!=y)v[COT2::a[py]]=0,py=f[py];
        return ans;
    }
}namespace BIT{
    int a[N];
    inline void I(int x,int y){for(;x;x-=x&-x)a[x]+=y;}
    inline int S(int x){int ans=0;for(;x<=n;x+=x&-x)ans+=a[x];return ans;}
}namespace CT{
    struct ChairTree{ChairTree*c[2];int v;}*T[N],sT[N*18],*stt=sT,*tmp;
    ChairTree*Build(int l,int r){
        ChairTree*ND=stt++;
#define mid (l+r>>1)
        if(l+1!=r)ND->c[0]=Build(l,mid),ND->c[1]=Build(mid,r);
        return ND;
    }ChairTree*I(ChairTree*R,int l,int r,int x){
        ChairTree*ND=stt++;ND->v=R->v+1;if(l+1==r)return ND;
        if(x<mid)ND->c[0]=I(R->c[0],l,mid,x),ND->c[1]=R->c[1];
        else ND->c[0]=R->c[0],ND->c[1]=I(R->c[1],mid,r,x);
        return ND;
    }inline int Q(ChairTree*R,int x){
        int l=0,r=n;
        while(l+1!=r)if(x<mid)r=mid,R=R->c[0];
        else l=mid,R=R->c[1];
        return R->v;
    }
}namespace Solve{
    struct QUE{QUE*next;int u,v,ans;}*Q[N],sq[100000],*stq=sq;
    int f[N],d[N],D[N],b[N];
    inline int fa(int x){while(x!=f[x])x=f[x];return x;}
    inline void ADDQUERY(int u,int v){
        int fu=fa(u),fv=fa(v);
        if(fu==fv){stq++->ans=Prep::Stupid(u,v);return;}
        if(d[v])swap(u,v),fv=fu;stq->u=u;stq->v=v;stq->next=Q[fv];Q[fv]=stq++;
    }inline int Calc(int x,int U,int V){
        int a=0;
        while(d[x]){
            a+=(!v[COT2::a[x]])&&(CT::Q(CT::T[U],COT2::a[x])==CT::Q(CT::T[V],COT2::a[x]))&&(COT2::a[x]!=COT2::a[U]);
            v[COT2::a[x]]=1;x=f[x];
        }return a;
    }inline void Clean(int x){while(d[x])v[COT2::a[x]]=0,x=f[x];}
    void GO(int x,int fx){
        int px=b[COT2::a[x]];BIT::I(px,-1);BIT::I(b[COT2::a[x]]=D[x]=fx==-1?1:D[fx]+1,1);
        for(QUE*p=Q[x];p;p=p->next)if(!p->ans){
            int fu=fa(p->u);if(!D[fu])continue;
            p->ans=BIT::S(D[fu])+Calc(p->u,fu,x)+Calc(p->v,fu,x);
            Clean(p->u);Clean(p->v);
        }for(EDGE*p=COT2::map[x];p;p=p->next)if(!d[p->y]&&p->y!=fx)CT::T[p->y]=CT::I(CT::T[x],0,n,COT2::a[p->y]),GO(p->y,x);
        BIT::I(b[COT2::a[x]]=px,1);BIT::I(D[x],-1);D[x]=0;
    }inline bool Run(){
        int i=n,b=-1,e=0;
        while(i--)if(num[f[i]=i]==1)d[que[e++]=i]=1;
        while(d[que[++b]]&&b!=e)for(EDGE*p=COT2::map[que[b]];p;p=p->next)if(num[p->y]!=1&&--num[f[que[b]]=p->y]==1){
            que[e++]=p->y;
            if(d[que[b]]!=200)d[p->y]=d[que[b]]+1;
        }if(e==b||e-b>50)return 1;
        for(i=m;i--;)ADDQUERY(getint()-1,getint()-1);
        while(e--!=b)CT::stt=CT::tmp,CT::T[que[e]]=CT::I(CT::sT,0,n,COT2::a[que[e]]),GO(que[e],-1);
        while(++i!=m)printf("%d\n",sq[i].ans);
        return 0;
    }
}
int main(){
    COT2::Init();Prep::Init(0);
    CT::Build(0,n);CT::tmp=CT::stt;if(Solve::Run())while(m--)printf("%d\n",Prep::Stupid(getint()-1,getint()-1));
    return 0;
}
