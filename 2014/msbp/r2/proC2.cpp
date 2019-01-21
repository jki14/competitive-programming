#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;

typedef long long i64d;

const int V=100100;
const int E=200100;

struct Tedge{
	int next,dest;
	i64d wght;
} edge[E];

int n,m,head[V];
i64d ans,a[V];

void run(int x, int y, i64d res, int p){
	if(a[p]<=a[x] && ans<a[p]*res)ans=a[p]*res;
	for(int i=head[x];i>=0;i=edge[i].next){
		if(edge[i].dest!=y)run(edge[i].dest,x,res+edge[i].wght,p);
	}
}

int main(){
	int T;scanf("%d",&T);
	for(int C=1;C<=T;C++){
		printf("Case %d: ",C);
		scanf("%d",&n);m=0;ans=0LL;
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++)head[i]=-1;
		for(int i=1;i< n;i++){
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			edge[m].next=head[x];edge[m].dest=y;edge[m].wght=z;head[x]=m++;
			edge[m].next=head[y];edge[m].dest=x;edge[m].wght=z;head[y]=m++;
		}
		for(int i=1;i<=n;i++)run(i,0,0LL,i);
		printf("%lld\n",ans);
	}
	return 0;
}

