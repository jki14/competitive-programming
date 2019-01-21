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

#define P 11000
#define S 11000

#define NUM 1230
#define PRM 9974

const int maxp = 10000;

int n,m,k,T;
int prm[S],is[S],num;
int pos[P],f[NUM][PRM],g[NUM][PRM];


void getprm(const int &n){num=0;
	int i,j,d;
	int e=(int)(sqrt((double)n+1.0));
	memset(is,0xff,sizeof(is));
	prm[num++]=2;is[0]=is[1]=0;
	for(i=4;i<=n;i+=2)is[i]=0;
	for(i=3;i< e;i+=2)if(is[i]){
		prm[num++]=i;d=i<<1;
		for(j=i*i;j<=n;j+=d)is[j]=0;
	}
	for(;i<=n;i+=2)if(is[i])prm[num++]=i;
}

void build(){
	getprm(maxp);
	for(int i=0;i<num;i++){
		int k=prm[i];pos[k]=i;
		f[i][0]=f[i][1]=1;
		g[i][0]=g[i][1]=1;
		for(int j=2;j<k;j++){
			f[i][j]=j*f[i][j-1] % prm[i];
			g[i][j]=(-k/j*g[i][k%j]%k + k) % k;
		}
	}
	for(int i=0;i<num;i++){
		int k=prm[i];
		for(int j=1;j<k;j++){
			g[i][j]=g[i][j]*g[i][j-1]%k;
		}
	}
}

int call(const int &a,const int &b,const int &c){
	if(a<b)return 0;
	int p=pos[c];
	return f[p][a]*g[p][b]%c*g[p][a-b]%c;
}

int lucas(int a,int b,const int &c){
	if(a<b)return 0;int res=1;
	for(;a && b;a/=k,b/=k){
		res = res * call(a%c,b%c,c) % c;
		if(res==0)return 0;
	}
	return res;
}

void work(){T++;
	if(m>(n>>1))m=n-m;
	printf("Case #%d: %d\n",T,(lucas(n+1,m,k)+n-m)%k);
}

int main(){T=0;
	build();//printf("num=%d prm[num-1]=%d\n",num,prm[num-1]);
	while(scanf("%d%d%d",&n,&m,&k)!=EOF)
		work();
	return 0;
}

