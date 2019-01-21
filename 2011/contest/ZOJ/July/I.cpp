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
#include<set>
#include<map>
using namespace std;

#define maxn 110000
#define maxm 2100000

#define L (i<<1)+1
#define R (i<<1)+2

map<int,int> s;
map<int,int>::iterator it;

int Len,n1,n2,m;
int rev[maxm];
int c[maxm],d[maxm],res;
int ax[maxn],ay[maxn];
int bx[maxn],by[maxn];

void modify(const int &i,const int &l,const int &r,const int &u,const int &v,const int &d){
	if(u>r || v<l)return;
	if(u<=l && r<=v){
		c[i]|=d;
	}else{
		int mid=(l+r)>>1;
		modify(L,l,  mid,u,v,d);
		modify(R,mid+1,r,u,v,d);
	}
}

void build(const int &i,const int &l,const int &r){
	if(l<r){
		int mid=(l+r)>>1;
		c[L]|=c[i];c[R]|=c[i];
		build(L,l,  mid);
		build(R,mid+1,r);
	}else{
		d[l]=c[i];
	}
}

void work(){
	int i,l,r;
	s.clear();m=0;
	for(i=0;i<n1;i++){
		scanf("%d%d",&ax[i],&ay[i]);
		s.insert(pair<int,int>(ax[i],0));
		s.insert(pair<int,int>(ay[i],0));
		s.insert(pair<int,int>(ax[i]-1,0));
		s.insert(pair<int,int>(ay[i]+1,0));

	}
	for(i=0;i<n2;i++){
		scanf("%d%d",&bx[i],&by[i]);
		s.insert(pair<int,int>(bx[i],0));
		s.insert(pair<int,int>(by[i],0));
		s.insert(pair<int,int>(bx[i]-1,0));
		s.insert(pair<int,int>(by[i]+1,0));
	}
	for(it=s.begin();it!=s.end();it++){
		(*it).second=++m;
		rev[m]=(*it).first;
	}		
	memset(c,0,sizeof(c));
	for(i=0;i<n1;i++){
		ax[i]=s[ax[i]];ay[i]=s[ay[i]];
		
		//printf("M %d(%d)->%d(%d)\n",ax[i],rev[ax[i]],ay[i],rev[ay[i]]);
		
		modify(0,1,m,ax[i],ay[i],1);
	}
	for(i=0;i<n2;i++){
		bx[i]=s[bx[i]];by[i]=s[by[i]];

		//printf("M %d(%d)->%d(%d)\n",bx[i],rev[bx[i]],by[i],rev[by[i]]);

		modify(0,1,m,bx[i],by[i],2);
	}
	memset(d,0,sizeof(d));
	build(0,1,m);
	res=l=0;r=-1;
	for(i=1;i<=m;i++){
		//printf("d[%d]=%d rev[%d]=%d\n",i,d[i],i,rev[i]);
		if(d[i]==1 || d[i]==2){
			if(/*d[i]==d[i-1]*/d[i-1]==1 || d[i-1]==2)r=rev[i];
			else{
				res=max(res,r-l+1);
				l=r=rev[i];
			}
		}else{
			res=max(res,r-l+1);
			l=0;r=-1;
		}
	}
	printf("%d\n",res);
}

int main(){
	while(scanf("%d%d%d",&Len,&n1,&n2)!=EOF)
		work();
	return 0;
}

