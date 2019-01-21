//============================================================================
// Name        : ChairTree_COT
// Author      : JKi Wang
// Version     : 1.00
// Copyright   : WangZhe (Chongqing University Computer College)
// Description : ZOJ 2112; 询问区间第k大值，允许修改某特定位置的值
//============================================================================

#define N 61000
#define M 11000
#define L 21
#define S 2100000
#define B 2

struct CTNode{
    int lef,rig,wht;
    CTNode *chd[B];
}*head[N], *root[N], *cur, *pos[L], *neg[L], CTNodePool[S];

int n,m,a[N],x[M],y[M],z[M];
int r[N],s;

char cs[L];

void empty(CTNode **p, const int &lef, const int &rig){
    *p=cur++;(*p)->wht=0;
    (*p)->lef=lef;(*p)->rig=rig;
    if(lef==rig){
        (*p)->chd[0]=(*p)->chd[1]=0;
    }else{int mid=(lef+rig)>>1;
        empty(&(*p)->chd[0],lef,  mid);
        empty(&(*p)->chd[1],mid+1,rig);
    }
}

void extend0(CTNode **p, CTNode *q, const int &k){
    *p=cur++;(*p)->wht=q->wht+1;
    (*p)->lef=q->lef;(*p)->rig=q->rig;
    if(q->lef==q->rig){
        (*p)->chd[0]=(*p)->chd[1]=0;
    }else{
        for(int i=0;i<B;i++){
            if(q->chd[i]->lef<=k && k<=q->chd[i]->rig)
                extend0(&(*p)->chd[i],q->chd[i],k);
            else (*p)->chd[i]=q->chd[i];
        }
    }
}

void extend1(CTNode **p, const int &k, const int &w){
    CTNode *q = *p; *p=cur++;(*p)->wht=q->wht+w;
    (*p)->lef=q->lef;(*p)->rig=q->rig;
    for(int i=0;i<B;i++)(*p)->chd[i]=q->chd[i];
    if(q->lef!=q->rig){
        for(int i=0;i<B;i++)
            if(q->chd[i]->lef<=k && k<=q->chd[i]->rig)
                extend1(&(*p)->chd[i],k,w);
    }
}

void build(){
    cur=CTNodePool;empty(&head[0],0,s-1);
    for(int i=1;i<=n;i++)extend0(&head[i],head[i-1],a[i]);
    empty(&root[0],0,s-1);for(int i=1;i<=n;i++)root[i]=root[0];
}

void modify(const int &k, const int &w){
    for(int i=k;i<=n;i+=_lowbit(i)){
        extend1(&root[i],a[k],-1);
        extend1(&root[i],w   ,1 );
    }a[k]=w;
}

int query(const int &l, const int &r, int w){
    CTNode *p=head[r], *q=head[l-1];
    int posTop=0,negTop=0;
    for(int i=r  ;i;i-=_lowbit(i))pos[posTop++]=root[i];
    for(int i=l-1;i;i-=_lowbit(i))neg[negTop++]=root[i];
    while(p->lef != p->rig){
        int k=0,cnt=p->chd[0]->wht-q->chd[0]->wht;
        for(int i=0;i<posTop;i++)cnt+=pos[i]->chd[0]->wht;
        for(int i=0;i<negTop;i++)cnt-=neg[i]->chd[0]->wht;
        if(cnt<w){ w-=cnt;k=1; }
        p=p->chd[k];q=q->chd[k];
        for(int i=0;i<posTop;i++)pos[i]=pos[i]->chd[k];
        for(int i=0;i<negTop;i++)neg[i]=neg[i]->chd[k];
    }
    return p->lef;
}

int main(){
    int T=1;
    while(T--){
        scanf("%d%d",&n,&m);s=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            r[s++]=a[i];
        }
        for(int i=0;i<m;i++){
            scanf("%s",cs);
            if(cs[0]=='Q'){
                scanf("%d%d%d",&x[i],&y[i],&z[i]);
            }else{
                scanf("%d%d",&x[i],&y[i]);z[i]=0;
                r[s++]=y[i];
            }
        }

        sort(r,r+s);s=unique(r,r+s)-r;
        for(int i=1;i<=n;i++)a[i]=lower_bound(r,r+s,a[i])-r;
        for(int i=0;i<m ;i++)if(!z[i])y[i]=lower_bound(r,r+s,y[i])-r;

        build();
        for(int i=0;i<m;i++){
            if(!z[i]){
                modify(x[i],y[i]);
            }else{
                printf("%d\n",r[query(x[i],y[i],z[i])]);
            }
        }
    }
    return 0;
}
