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

#define maxn 5100
#define maxm 5100
#define CI const int

#define L (i<<1)+1
#define R (i<<1)+2

const int len=10;

int n,m;
int cx[maxm],d[maxm],cy[maxn][maxm],num;

void my(CI &k,CI &i,CI &l,CI &r,CI &x1,CI &y1,CI &x2,CI &y2){
	if(y1>r || y2<l)return;
	if(y1<=l && r<=y2){
		cy[k][i]^=1;
	}else{
		int mid=(l+r)>>1;
		my(k,L,l,  mid,x1,y1,x2,y2);
		my(k,R,mid+1,r,x1,y1,x2,y2);
	}
}

void mx(CI &i,CI &l,CI &r,CI &x1,CI &y1,CI &x2,CI &y2){
	if(x1>r || x2<l)return;
	if(!d[i] && x1<=l && r<=x2){
		if(!cx[i])cx[i]=++num;
		my(cx[i],0,1,n,x1,y1,x2,y2);
	}else{
		int mid=(l+r)>>1;

		d[i]=1;
		if(cx[i]){
			cx[L]=cx[i];
			cx[R]=++num;
			cx[i]=0;
			memcpy(cy[cx[R]],cy[cx[L]],sizeof(cy[cx[L]]));
		}
		mx(L,l,  mid,x1,y1,x2,y2);
		mx(R,mid+1,r,x1,y1,x2,y2);
	}
}

int qy(CI &k,CI &i,CI &l,CI &r,CI &x,CI &y){
	if(y>r || y<l)return 0;
	if(l<r){
		int mid=(l+r)>>1;
		if(cy[k][i]){cy[k][i]=0;
			my(k,L,l,  mid,1,1,n,n);
			my(k,R,mid+1,r,1,1,n,n);
		}
		return qy(k,L,l,  mid,x,y)|qy(k,R,mid+1,r,x,y);
	}else return cy[k][i];
}

int qx(CI &i,CI &l,CI &r,CI &x,CI &y){
	if(x>r || x<l)return 0;
	if(!d[i]){
		return qy(cx[i],0,1,n,x,y);
	}else{
		int mid=(l+r)>>1;
		return qx(L,l,  mid,x,y)|qx(R,mid+1,r,x,y);
	}
}

void work(){
	char str[len];
	int i,x1,y1,x2,y2;
	memset(cx,0,sizeof(cx));
	memset(cy,0,sizeof(cy));
	num=0;
	for(i=0;i<m;i++){
		scanf("%s",str);
		if(str[0]=='C'){
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			mx(0,1,n,x1,y1,x2,y2);
		}else{
			scanf("%d%d",&x1,&y1);
			printf("%d\n",qx(0,1,n,x1,y1));
		}
	}
	printf("\n");
}

int main(){
	int t;scanf("%d",&t);
	while(t--){scanf("%d%d",&n,&m);
		work();
	}
	return 0;
}

