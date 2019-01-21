//============================================================================
// Name        : ChairTree_COT
// Author      : JKi Wang
// Version     : 1.00
// Copyright   : WangZhe (Chongqing University Computer College)
// Description : SPOJ COT; 给定一棵点权树，询问指定两个节点路径上的第k大点权
//============================================================================

#define S 2100000
#define N 110000
#define M 210000
#define B 2

struct CTNode{
	int lef,rig,wht;
	CTNode *ch[B];
} *head[N], *cur, CTNodePool[S];

int n,m,a[N];
int f[N],g[N],r[N],top;
int nbs[N],nxt[M],dst[M],enm;
int nbq[N][B],nxq[N][B];
int p[N][B],k[N],ans[N];

inline int find(const int &u){ if(f[u]!=u)f[u]=find(f[u]);return f[u]; }

void addEdge(const int &u,const int &v){
	nxt[++enm]=nbs[u];nbs[u]=enm;dst[enm]=v;
	nxt[++enm]=nbs[v];nbs[v]=enm;dst[enm]=u;
}

void buildQry(){
	memset(nbq,0xff,sizeof(nbq));
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&p[i][0],&p[i][1],&k[i]);
		for(int b=0;b<B;b++){
			p[i][b]--;
			nxq[i][b]=nbq[p[i][b]][b];nbq[p[i][b]][b]=i;
		}
	}
}

void empty(CTNode **p,const int &lef,const int &rig){
	*p=cur++;(*p)->lef=lef;(*p)->rig=rig;(*p)->wht=0;
	if(lef==rig){
		(*p)->ch[0]=(*p)->ch[1]=0;
	}else{int mid=(lef+rig)>>1;
		empty(&(*p)->ch[0],lef,  mid);
		empty(&(*p)->ch[1],mid+1,rig);
	}
}

void init(){
	cur=CTNodePool;
	empty(&head[n],0,top-1);
}


void extend(CTNode **p, CTNode *s, const int &k){
	*p=cur++;(*p)->lef=s->lef;(*p)->rig=s->rig;(*p)->wht=s->wht+1;
	if(s->lef==s->rig){
		(*p)->ch[0]=(*p)->ch[1]=0;
	}else{
		for(int i=0;i<B;i++){
			if(s->ch[i]->lef<=k && k<=s->ch[i]->rig)
				extend(&(*p)->ch[i],s->ch[i],k);
			else (*p)->ch[i]=s->ch[i];
		}
	}
}

int  calc(CTNode *x, CTNode *y, CTNode *p, CTNode *q, const int &k){
	if(x->lef==x->rig)return x->lef;
	int sub=x->ch[0]->wht+y->ch[0]->wht-p->ch[0]->wht-q->ch[0]->wht;
	if(sub>=k)
		return calc(x->ch[0],y->ch[0],p->ch[0],q->ch[0],k);
	else return calc(x->ch[1],y->ch[1],p->ch[1],q->ch[1],k-sub);
}

void core(const int &u,const int &s){
	extend(&head[u],head[s],a[u]);g[u]=s;
	for(int i=nbs[u];i;i=nxt[i]){int v=dst[i];
		if(v==s)continue;
		core(v,u);
		f[find(v)]=find(u);
	}
	for(int b=0;b<B;b++){
		for(int i=nbq[u][b];i>=0;i=nxq[i][b]){int v=p[i][b^1];
			if(head[v]){
				ans[i]=r[calc(head[u],head[v],head[find(v)],head[g[find(v)]],k[i])];
			}
		}
	}
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=0;i<n;i++){ scanf("%d",&a[i]);r[i]=a[i]; }
		sort(r,r+n);top=unique(r,r+n)-r;
		for(int i=0;i<n;i++)a[i]=lower_bound(r,r+top,a[i])-r;

		memset(nbs,0,sizeof(nbs));enm=0;
		for(int i=1;i<n;i++){
			int u,v;scanf("%d%d",&u,&v);
			u--;v--;addEdge(u,v);
		}

		buildQry();

		for(int i=0;i<n;i++)g[i]=f[i]=i;
		init();core(0,n);

		for(int i=0;i<m;i++)printf("%d\n",ans[i]);
	}
	return 0;
}
