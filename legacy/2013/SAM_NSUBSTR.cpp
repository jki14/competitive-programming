//============================================================================
// Name        : SAM_NSUBSTR
// Author      : JKi Wang
// Version     : 1.00
// Copyright   : WangZhe (Chongqing University Computer College)
// Description : SPOJ NSUBSTR; 求给定字符串的所有指定长度的连续子串重复出现的最多次数
//============================================================================

#define C 26
#define L 260000

struct samNode{
	samNode *prv,*nxt[C];
	int val,res;

	void clear(){ prv=0;val=0;res=0;memset(nxt,0,sizeof(nxt)); }

	int calc(){
		if(prv==0)return 0;
		return val-prv->val;
	}
} *head, *tail;

samNode samNodePool[L<<1], *cur;

void init(){
	cur=samNodePool;
	head=tail=cur++;
	head->clear();
}

void extend(const int &c){
	samNode *p=tail, *q=cur++;
	q->clear();q->val=p->val+1;
	for(;p && !p->nxt[c];p=p->prv)p->nxt[c]=q;

	if(!p){
		q->prv=head;
	}else{
		samNode *x=p->nxt[c];
		if(p->val+1==x->val){
			q->prv=x;
		}else{
			samNode *y=cur++;
			y->clear();
			memcpy(y->nxt,x->nxt,sizeof(x->nxt));
			y->val=p->val+1;y->prv=x->prv;
			x->prv=q->prv=y;
			for(;p && p->nxt[c]==x;p=p->prv)p->nxt[c]=y;
		}
	}
	tail=q;
}

char a[L];
int n,ans[L];

int rnk[L],num;
samNode *que[L<<1], *p;

int main(){
	while(scanf("%s",a)!=EOF){

		init();n=strlen(a);
		for(int i=0;a[i];i++)extend(a[i]-'a');
		for(int i=0;a[i];i++){
			if(!i)p=head;
			(p=p->nxt[a[i]-'a'])->res++;
		}

		memset(rnk,0,sizeof(rnk));num=0;
		for(samNode *p=head;p!=cur;p++){ rnk[p->val]++;num++; }
		for(int i=1;i<=n;i++)rnk[i]+=rnk[i-1];
		for(samNode *p=head;p!=cur;p++)que[--rnk[p->val]]=p;

		memset(ans,0,sizeof(ans));
		for(int i=num-1;i>=0;i--){samNode *p=que[i];
			_updmax(ans[p->val],p->res);
			if(p->prv)p->prv->res+=p->res;
		}

		for(int i=n-1;i>=0;i--)_updmax(ans[i],ans[i+1]);
		for(int i=1;i<=n;i++)printf("%d\n",ans[i]);
	}
	return 0;
}
