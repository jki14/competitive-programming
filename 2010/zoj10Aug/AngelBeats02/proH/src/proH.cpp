#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define maxn 100
#define maxn2 10000

int n,tot,m,s,res;
int x[maxn2],y[maxn2],id[maxn2];

int cmpy(const int &v0,const int &v1){ return y[v0]<y[v1]; }
int cmp(const int &v0,const int &v1){ return (x[v0]==x[v1])?y[v0]<y[v1]:x[v0]<x[v1]; }

void work(){
	int i,j,k;tot=n*n;
	for(i=0;i<tot;i++){
		scanf("%d%d",&x[i],&y[i]);
		id[i]=i;
	}
	if(tot<1){
		printf("0\n");
		return;
	}
	sort(id,id+tot,cmpy);s=y[id[(tot+1)/2-1]]-(n+1)/2+1;
	if(s<0)s=0;if(s+n-1>m)s=m-n+1;
	sort(id,id+tot,cmp);
	for(i=k=res=0;i<n;i++)
		for(j=0;j<n;j++,k++)
			res+=abs(y[id[k]]-(s+j));
	printf("%d\n",res);
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF && !(n==0 && m==0))work();
	return 0;
}
