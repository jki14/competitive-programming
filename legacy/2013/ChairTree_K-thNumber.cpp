//============================================================================
// Name        : ChairTree_K-thNumber
// Author      : JKi Wang
// Version     : 1.00
// Copyright   : WangZhe (Chongqing University Computer College)
// Description : POJ 2104; 询问区间第k大的数
//============================================================================

#define N 110000
#define B 2
#define S 2100000

struct CTNode{
	int lef,rig,wht;
	CTNode *chd[B];
} *head[N],CTNodePool[S],*cur;

int n,m,a[N];
int r[N],top;

void empty(CTNode **p,const int &lef,const int &rig){
	*p=cur++;(*p)->wht=0;
	(*p)->lef=lef;(*p)->rig=rig;
	if((*p)->lef==(*p)->rig){
		(*p)->chd[0]=(*p)->chd[1]=0;
	}else{int mid=(lef+rig)>>1;
		empty(&(*p)->chd[0],lef,  mid);
		empty(&(*p)->chd[1],mid+1,rig);
	}
}

void init(){
	cur=CTNodePool;
	empty(&head[0],0,top-1);
}

void _extend(CTNode **p, CTNode *f, const int &k){
	*p=cur++;(*p)->wht=f->wht+1;
	(*p)->lef=f->lef;(*p)->rig=f->rig;

	if((*p)->lef==(*p)->rig){
		(*p)->chd[0]=(*p)->chd[1]=0;
	}else{
		for(int c=0;c<B;c++){
			if(f->chd[c]->lef<=k && k<=f->chd[c]->rig){
				_extend(&(*p)->chd[c],f->chd[c],k);
			}else (*p)->chd[c]=f->chd[c];
		}
	}
}

void extend(const int &p){
	_extend(&head[p],head[p-1],a[p]);
}

int _querry(CTNode *q, CTNode *p, const int &k){
	if(p->lef==p->rig)return p->lef;
	int sub=p->chd[0]->wht - q->chd[0]->wht;
	if(k<=sub)
		return _querry(q->chd[0],p->chd[0],k);
	else return _querry(q->chd[1],p->chd[1],k-sub);
}

int querry(const int &u, const int &v, const int &k){
	return _querry(head[u-1],head[v],k);
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=1;i<=n;i++){ scanf("%d",&a[i]);r[i-1]=a[i]; }
		sort(r,r+n);top=unique(r,r+n)-r;
		for(int i=1;i<=n;i++)a[i]=lower_bound(r,r+top,a[i])-r;

		init();
		for(int i=1;i<=n;i++)extend(i);
		for(int i=0;i<m;i++){
			int u,v,k;scanf("%d%d%d",&u,&v,&k);
			printf("%d\n",r[querry(u,v,k)]);
		}
	}
	return 0;
}
