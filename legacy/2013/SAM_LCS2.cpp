//============================================================================
// Name        : SAM_LCS2
// Author      : JKi Wang
// Version     : 1.00
// Copyright   : WangZhe (Chongqing University Computer College)
// Description : SPOJ LCS2; 求给定多个字符串的最长公共连续子串
//============================================================================

#define C 26
#define L 110000

const int inf=0x3f3f3f3f;

struct samNode{
	samNode *prv,*nxt[C];
	int val,res,ans;

	void clear(){ prv=0;val=0;res=0;ans=inf;memset(nxt,0,sizeof(nxt)); }

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
			x->prv=y;q->prv=y;
			for(;p && p->nxt[c]==x;p=p->prv)p->nxt[c]=y;
		}
	}
	tail=q;
}

char a[L],b[L];
int ans,res,num;

samNode *que[L<<1];

int cmp(const samNode *x,const samNode *y){ return x->val>y->val; }

int main(){
	init();
	scanf("%s",a);ans=0;
	for(int i=0;a[i];i++)extend(a[i]-'a');

	num=0;for(samNode *p=head;p!=cur;p++)que[num++]=p;
	sort(que,que+num,cmp);

	while(scanf("%s",b)!=EOF){
		samNode *p=head;ans=res=0;
		for(int i=0;b[i];i++){int k=b[i]-'a';
			if(p->nxt[k]){
				p=p->nxt[k];res++;
			}else{
				for(;p && !p->nxt[k];p=p->prv);
				if(!p){
					p=head;res=0;
				}else{
					res=p->val+1;
					p=p->nxt[k];
				}
			}
			_updmax(p->res,res);
		}
		for(int i=0;i<num;i++){p=que[i];
			_updmin(p->ans,p->res);
			if(p->prv)
				_updmax(p->prv->res,min(p->prv->val,p->res));
			p->res=0;
		}
	}

	for(samNode *p=head;p!=cur;p++)_updmax(ans,p->ans);

	printf("%d\n",ans);
	return 0;
}
