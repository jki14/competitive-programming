#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
//#include<cmath>
#include<ctime>
#include<climits>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<set>
#include<map>
using namespace std;

#define maxn 11000
#define maxm 110000
#define maxk 11

#define L (i<<1)+1
#define R (i<<1)+2

const int inf=0x3fffffff;
const int low=-inf;

int T;

int deb=0;

int n,k,q;
int exp[maxk],lev[maxk],head,tail;
int cha[maxk][maxm],top[maxk][maxm],pla[maxk][maxm];

char opt[10];

void build(const int &k,const int &i,const int &l,const int &r){
	cha[k][i]=0;top[k][i]=low;pla[k][i]=l;
	if(k==1)top[k][i]=0;
	if(l<r){int mid=(l+r)>>1;
		build(k,L,l,  mid);
		build(k,R,mid+1,r);
	}

	//printf("[%d][%d]===%d->%d\n",k,i,l,r);

}

void update(const int &k,const int &i){
	if(top[k][L]<top[k][R]){
		top[k][i]=top[k][R];
		pla[k][i]=pla[k][R];
	}else{
		top[k][i]=top[k][L];
		pla[k][i]=pla[k][L];
	}

	//printf("top[%d][%d]==%d\n",k,i,top[k][i]);
	//printf("pla[%d][%d]==%d\n",k,i,pla[k][i]);
}

void addexp(const int &k,const int &i,const int &l,const int &r,const int &u,const int &v,const int &w){
	
	//printf("AddExp level %d, at %d,(%d->%d) (%d->%d) %d\n",k,i,l,r,u,v,w);
	
	if(r<u || l>v)return;
	if(u<=l && r<=v){
		cha[k][i]+=w;
		top[k][i]+=w;

		//printf("top[%d][%d]=%d\n",k,i,top[k][i]);

	}else{int mid=(l+r)>>1;
		if(cha[k][i]){
			addexp(k,L,l,  mid,1,n,cha[k][i]);
			addexp(k,R,mid+1,r,1,n,cha[k][i]);
			cha[k][i]=0;
		}
		addexp(k,L,l,  mid,u,v,w);
		addexp(k,R,mid+1,r,u,v,w);
		update(k,i);
	}
}

int gettop(const int &k,int &p,const int &i,const int &l,const int &r,const int &u,const int &v){
	if(r<u || l>v)return low;
	if(u<=l && r<=v){
		p=pla[k][i];
		return top[k][i];
	}else{int wl,wr,pl,pr,mid=(l+r)>>1;
		if(cha[k][i]){
			addexp(k,L,l,  mid,1,n,cha[k][i]);
			addexp(k,R,mid+1,r,1,n,cha[k][i]);
			cha[k][i]=0;
		}
		wl=gettop(k,pl,L,l,  mid,u,v);
		wr=gettop(k,pr,R,mid+1,r,u,v);
		if(wl<wr){
			p=pr;
			return wr;
		}
		p=pl;
		return wl;
	}
}

void work(){
	int i,j,p,u,v,w;
	int tmp;
	exp[0]=0;exp[k]=inf;
	for(i=1;i<k;i++){
		scanf("%d",&exp[i]);
		//exp[i]+=exp[i-1];
		build(i,0,1,n);
	}build(k,0,1,n);
	memset(lev,0,sizeof(lev));
	//for(i=1;i<=n;i++)addexp(1,0,1,n,i,i,-gettop(1,tmp,0,1,n,i,i));
	head=tail=1;lev[1]=n;
	printf("Case %d:\n",T);
	while(q--){
		scanf("%s",opt);
		
		//printf("operation %s\n",opt);

		if(opt[0]=='W'){
			scanf("%d%d%d",&u,&v,&w);
			for(i=head;i<=tail;i++)addexp(i,0,1,n,u,v,w*i);
			for(i=head;i<=tail;i++){if(!lev[i])continue;
				while((w=gettop(i,p,0,1,n,1,n))>=exp[i]){
					
					/*deb++;if(deb>10)return;
					printf("p==%d w==%d\n",p,w);
					printf("i==%d p==%d\n",i,p);*/					

					//addexp(i+1,0,1,n,p,p,-gettop(i+1,tmp,0,1,n,p,p));
					for(j=i+1;w>=exp[j];j++);
					addexp(j,0,1,n,p,p,w-gettop(j,tmp,0,1,n,p,p));
					addexp(i  ,0,1,n,p,p,low);
					
					lev[j]++;lev[i]--;
					if(tail<j)tail=j;
				}
			}
			while(!lev[head])head++;
		}else{
			scanf("%d%d",&u,&v);
			for(i=tail;i;i--){
				if((w=gettop(i,p,0,1,n,u,v))>0){
					printf("%d\n",w);
					break;
				}
			}
		}
	}
	printf("\n");
}

int main(){
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++){
		scanf("%d%d%d",&n,&k,&q);
		work();
	}
	return 0;
}

