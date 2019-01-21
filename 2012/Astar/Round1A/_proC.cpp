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

#define L (i<<1)+1
#define R (i<<1)+2
#define K 2
#define S 5000000

typedef long long lld;

const int minval=1;
const int maxval=1000000;

int n,key0,key1;
int segt[K][S];

void insert(const int &k,const int &i,const int &l,const int &r,const int &u,const int &v){

	if(!i)printf("insert %d %d->%d\n",k,u,v);

	if(v<u || u>r || v<l)return;
	if(segt[k][i]==r-l+1)return;
	if(u<=l && r<=v){
		segt[k][i]=r-l+1;
	}else{
		int mid=(l+r)>>1;
		insert(k,L,l,  mid,u,v);
		insert(k,R,mid+1,r,u,v);
		segt[k][i]=segt[k][L]+segt[k][R];
	}
}

int main(){
	scanf("%d",&n);
	memset(segt,0,sizeof(segt));
	for(int i=0;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		insert(0,0,minval,maxval,u,v);
		insert(1,0,minval,maxval,minval,u-1);
		insert(1,0,minval,maxval,v+1,maxval);

		printf("segt[0][0]=%d segt[1][0]=%d\n",segt[0][0],segt[1][0]);
	}
	key0=segt[0][0];key1=maxval-segt[1][0];
	lld ans=((lld)key0)*((lld)key1);
	printf("%d %d\n",key0,key1);
	printf("%lld\n",ans);
	return 0;
}
