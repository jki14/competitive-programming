#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
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

#define maxn 110000
#define maxm 710000
#define K 2

#define L (i<<1)+1
#define R (i<<1)+2

int n,m;
int a[maxn];
int c[maxm]/*,ope[maxm]*/,len[maxm],head[maxm][K],tail[maxm][K],subc[maxm][K];

/*int he,ta,su,le;
int hl,tl,sl,ll;
int hr,tr,sr,lr;*/

int top(const int &v,const int &w,const int &x,const int &y,const int &z){
	int ret=v;
	if(ret<w)ret=w;
	if(ret<x)ret=x;
	if(ret<y)ret=y;
	if(ret<z)ret=z;
	return ret;
}

void fresh(const int &i){
	for(int k=0;k<K;k++){
		if(len[L]==head[L][k])
			head[i][k]=head[L][k]+head[R][k];
		else
			head[i][k]=head[L][k];

		if(len[R]==tail[R][k])
			tail[i][k]=tail[R][k]+tail[L][k];
		else
			tail[i][k]=tail[R][k];

		subc[i][k]=top(head[i][k],tail[i][k],tail[L][k]+head[R][k],subc[L][k],subc[R][k]);
	}
}

void build(const int &i,const int &l,const int &r){len[i]=(r-l)+1;
	if(i>350000)while(1){ len[i]=len[i] ;}
	if(len[i]>1){int mid=(l+r)>>1;
		build(L,l,  mid);
		build(R,mid+1,r);
		
		fresh(i);

	}else{
		head[i][a[l]]=tail[i][a[l]]=subc[i][a[l]]=1;
	}
}

void update(const int &i,const int &l,const int &r,const int &u,const int &v){
	if(l>v || r<u)return;
	if(/*!ope[i] &&*/ u<=l && r<=v){c[i]^=1;
		swap(head[i][0],head[i][1]);
		swap(tail[i][0],tail[i][1]);
		swap(subc[i][0],subc[i][1]);
	}else{//ope[i]=1;
		int mid=(l+r)>>1;
		if(c[i]){c[i]=0;
			update(L,l,  mid,1,n);
			update(R,mid+1,r,1,n);
		}
		update(L,l,  mid,u,v);
		update(R,mid+1,r,u,v);

		fresh(i);
		
		//printf("[%d,%d] head=%d tail=%d subc=%d\n",l,r,head[i][1],tail[i][1],subc[i][1]);
	}
}

int que(const int &i,const int &l,const int &r,const int &u,const int &v,int &he,int &ta,int &su,int &length){
	if(l>v || r<u){
		he=ta=su=length=0;
		return 0;
	}
	if(u<=l && r<=v){
		he=head[i][1];
		ta=tail[i][1];
		su=subc[i][1];
		length=len[i];
	}else{int mid=(l+r)>>1;

		if(c[i]){c[i]=0;
			update(L,l,  mid,1,n);
			update(R,mid+1,r,1,n);
		}
		
		int hl,tl,sl,ll;
		int hr,tr,sr,lr;

		que(L,l,  mid,u,v,hl,tl,sl,ll);
		que(R,mid+1,r,u,v,hr,tr,sr,lr);

		length=ll+lr;

		if(ll==hl)
			he=hl+hr;
		else
			he=hl;

		if(lr==tr)
			ta=tr+tl;
		else
			ta=tr;

		su=top(he,ta,tl+hr,sl,sr);

		//printf("(%d,%d)X(%d,%d)[%d->%d] H=%d T=%d S=%d\n",l,r,u,v,max(l,u),min(r,v),he,ta,su);
	}
	return su;
}

void work(){
	int i,k,u,v;
	int w,x,y,z;

	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	memset(c,0,sizeof(c));
	//memset(ope,0,sizeof(ope));
	memset(head,0,sizeof(head));
	memset(tail,0,sizeof(tail));
	memset(subc,0,sizeof(subc));
	build(0,1,n);

	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d%d%d",&k,&u,&v);
		if(k)
			update(0,1,n,u,v);
		else
			printf("%d\n",que(0,1,n,u,v,x,y,z,w));
	}
}

int main(){
	while(scanf("%d",&n)!=EOF)work();
	return 0;
}		


