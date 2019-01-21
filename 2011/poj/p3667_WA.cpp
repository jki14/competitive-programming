#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

#define maxn 1100000

#define L (i<<1)+1
#define R (i<<1)+2

int cov[maxn],len[maxn],pla[maxn];
int n,m;

void init(const int &i,const int &l,const int &r){
	cov[i]=0;pla[i]=l;len[i]=r-l+1;
	if(l!=r){
		int mid=(l+r)>>1;
		init(L,l,  mid);
		init(R,mid+1,r);
	}
}

int find(const int &i,const int &l,const int &r,const int &x){
	//printf("Len %d->%d = %d\n",l,r,len[i]);
	if(len[i]<x)return 0;
	if(l!=r){
		int mid=(l+r)>>1,ret;
		ret=find(L,l,  mid,x);
		//printf("find %d->%d %d L=%d\n",l,r,x,ret);
		if(ret)return ret;
		/*ret=find(R,mid+1,r,x);
		printf("find %d->%d %d R=%d\n",l,r,x,ret);
		if(ret)return ret;*/
	}
	//printf("find %d->%d %d Key=%d\n",l,r,x,pla[i]);
	return pla[i];
}

void checkout(const int &i,const int &l,const int &r,const int &u,const int &v);

void checkin(const int &i,const int &l,const int &r,const int &u,const int &v){
	if(u>r || v<l)return;
	if(u<=l && r<=v){
		cov[i]=1;pla[i]=r+1;len[i]=0;
		
		//printf("Checkin %d->%d (fact:%d->%d)\n",l,r,u,v);

	}else{
		int mid=(l+r)>>1;
		if(cov[i]==-1){cov[i]=0;
			checkout(L,l,  mid,1,n);
			checkout(R,mid+1,r,1,n);
		}
		checkin(L,l,  mid,u,v);
		checkin(R,mid+1,r,u,v);
		if(len[L] && len[R] &&  pla[R]==mid+1 && pla[L]+len[L]-1==mid){

			//printf("NextTo for %d->%d ",l,r);

			len[i]=len[L]+len[R];
			pla[i]=pla[L];

			//printf("len=L.len(%d)+R.len(%d)=%d pla=%d\n",len[L],len[R],len[i],pla[i]);
		}else{
			if(len[R]>len[L]){
				len[i]=len[R];pla[i]=pla[R];
			}else{
				len[i]=len[L];pla[i]=pla[L];
			}
		}
	}
}

void checkout(const int &i,const int &l,const int &r,const int &u,const int &v){
	if(u>r || v<l)return;
	if(u<=l && r<=v){
		cov[i]=-1;pla[i]=l;len[i]=l+r-1;
		
		//printf("Checkout %d->%d (fact:%d->%d)\n",l,r,u,v);


	}else{
		int mid=(l+r)>>1;
		if(cov[i]){cov[i]=0;
			checkin(L,l,  mid,1,n);
			checkin(R,mid+1,r,1,n);
		}
		checkout(L,l,  mid,u,v);
		checkout(R,mid+1,r,u,v);
		if(len[L] && len[R] && pla[R]==mid+1 && pla[L]+len[L]-1==mid){
			len[i]=len[L]+len[R];
			pla[i]=pla[L];
			
			//printf("NextTo for %d->%d ",l,r);
			//printf("len=L.len(%d)+R.len(%d)=%d pla=%d\n",len[L],len[R],len[i],pla[i]);


		}else{
			if(len[R]>len[L]){
				len[i]=len[R];pla[i]=pla[R];
			}else{
				len[i]=len[L];pla[i]=pla[L];
			}
		}
	}
}

int insert(const int &x){
	if(len[0]<x)return 0;
	int u=find(0,1,n,x),v;
	v=u+x-1;
	checkin(0,1,n,u,v);
	return u;
}

void work(){
	int cast,x,y;
	init(0,1,n);
	while(m--){
		scanf("%d",&cast);
		if(cast==1){
			//insert
			scanf("%d",&x);
			printf("%d\n",insert(x));
		}else{
			//checkout
			scanf("%d%d",&x,&y);
			//cout<<"CHECK OUT X="<<x<<" Y="<<y<<endl;
			checkout(0,1,n,x,x+y-1);
		}
	}
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF)
		work();
	return 0;
}

