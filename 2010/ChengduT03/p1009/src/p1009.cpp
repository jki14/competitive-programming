#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

#define maxn 110
#define maxm 110000

int n,a[maxn],b[maxn];
int sy[maxm],cx[maxn],cy[maxm];

int path(int u){
	for(int v=a[u];v<=b[u];v++)if(!sy[v]){
		sy[v]=1;if(!cy[v] || path(cy[v])){
			cx[u]=v;cy[v]=u;
			return 1;
		}
	}
	return 0;
}

void work(){
	int i,fir=1,res=0;for(i=1;i<=n;i++)scanf("%d%d",&a[i],&b[i]);
	memset(cx,0,sizeof(cx));memset(cy,0,sizeof(cy));
	for(i=n;i>=1;i--){
		memset(sy,0,sizeof(sy));
		res+=path(i);
	}
	printf("%d\n",res);
	for(i=1;i<=n;i++)if(cx[i]){
		if(!fir)printf(" ");
		printf("%d",i);fir=0;
	}
	printf("\n");
}

int main(){
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		work();
	}
	return 0;
}
