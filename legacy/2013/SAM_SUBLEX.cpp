//============================================================================
// Name        : SAM_SUBLEX
// Author      : JKi Wang
// Version     : 1.00
// Copyright   : WangZhe (Chongqing University Computer College)
// Description : SPOJ SUBLEX; 求给定字符串的所有不同连续子串中字典序第k的子串
//============================================================================

#define C 26
#define L 160000

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
int n,m,k;

int rnk[L],num,len;
samNode *que[L<<1], *p;

int cnt[L<<1],acc[L<<1][C];

char ans[L];

int main(){
	//while(scanf("%s",a)!=EOF){
		//scanf("%s",a);
		gets(a);
		init();n=strlen(a);
		for(int i=0;a[i];i++)extend(a[i]-'a');

		memset(rnk,0,sizeof(rnk));num=0;
		for(samNode *p=head;p!=cur;p++){ rnk[p->val]++;num++; }
		for(int i=1;i<=n;i++)rnk[i]+=rnk[i-1];
		for(samNode *p=head;p!=cur;p++)que[--rnk[p->val]]=p;

		for(int i=num-1;i>=0;i--){samNode *p=que[i];
			p->res++;int k=p-samNodePool;
			cnt[k]=0;
			for(int j=0;j<C;j++){
				if(!p->nxt[j])continue;
				p->res+=p->nxt[j]->res;
				acc[k][cnt[k]++]=j;
			}
		}

		scanf("%d",&m);for(int i=0;i<m;i++){
			scanf("%d",&k);len=0;
			samNode *p=head;
			for(;k;k--){
				int x=p-samNodePool;
				for(int _i=0;_i<cnt[x];_i++){int i=acc[x][_i];
					//if(!p->nxt[i])continue;
					if(p->nxt[i]->res>=k){
						//printf("%c",'a'+i);
						ans[len++]='a'+i;
						p=p->nxt[i];
						break;
					}
					k-=p->nxt[i]->res;
				}
			}
			ans[len++]=0;
			puts(ans);
			//printf("\n");
		}
	//}
	return 0;
}
