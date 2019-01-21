#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

#define maxn 2100

int n;
int f[maxn][maxn];
int v[maxn],g[maxn];

int find(const int &i,const int &x){
	if(f[i][x]!=x){
		if(f[i][x]==0)
			f[i][x]=x;
		else
			f[i][x]=find(i,f[i][x]);
	}
	return f[i][x];
}

int sg(const int &p){
	int i,x,y,k;
	if(v[p])return g[p];
	v[p]=1;
	for(i=1;i<=p/2+1;i++){x=y=0;
		if(i-3>0){
			x=sg(i-3);
		}
		if(i+3<=p){
			y=sg(p-i-2);
		}
		k=x^y;
		//printf("p=%d k=%d\n",p,k);
		f[p][k]=find(p,k+1);
		//f[p][k]=1;
	}
	g[p]=find(p,0);
	/*for(k=0;f[p][k];k++);
	g[p]=k;*/
	return g[p];
}

void work(){
	if(sg(n)){
		printf("1\n");
	}else{
		printf("2\n");
	}
}

int main(){
	memset(v,0,sizeof(v));
	memset(f,0,sizeof(f));
	while(scanf("%d",&n)!=EOF && n)
		work();
	return 0;
}
