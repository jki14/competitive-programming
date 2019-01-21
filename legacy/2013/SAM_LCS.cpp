//============================================================================
// Name        : SAM_LCS
// Author      : JKi Wang
// Version     : 1.00
// Copyright   : WangZhe (Chongqing University Computer College)
// Description : SPOJ LCS; 求给定两个字符串的最长公共连续子串
//============================================================================

#define C 26
#define L 250000

struct samNode{
	samNode *prv,*nxt[C];
	int val;

	void clear(){ prv=0;val=0;memset(nxt,0,sizeof(nxt)); }

	int calc(){
		if(prv==0)return 0;
		return val-prv->val;
	}
} *head, *tail;

samNode samNodePool[L<<1], *cur;

int kind;

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
		q->prv=head;kind+=q->calc();
	}else{
		samNode *x=p->nxt[c];
		if(p->val+1==x->val){
			q->prv=x;kind+=q->calc();
		}else{
			samNode *y=cur++;
			y->clear();
			memcpy(y->nxt,x->nxt,sizeof(x->nxt));
			kind-=p->calc()+x->calc();
			y->val=p->val+1;y->prv=x->prv;
			x->prv=q->prv=y;
			kind+=p->calc()+x->calc()+q->calc()+y->calc();
			for(;p && p->nxt[c]==x;p=p->prv)p->nxt[c]=y;
		}
	}
	tail=q;
}

char a[L],b[L];
int ans,res;

int main(){
	while(scanf("%s%s",a,b)!=EOF){
		init();kind=0;ans=0;
		for(int i=0;a[i];i++)extend(a[i]-'a');
		samNode *p=head;res=0;
		for(int i=0;b[i];i++){int key=b[i]-'a';
			if(p->nxt[key]){
				p=p->nxt[key];res++;
			}else{
				for(;p && !p->nxt[key];p=p->prv);
				if(!p){
					p=head;res=0;
				}else{
					res=p->val+1;
					p=p->nxt[key];
				}
			}
			_updmax(ans,res);
		}
		printf("%d\n",ans);
	}
	return 0;
}
