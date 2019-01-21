#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define maxn 30
#define maxl 10

int n,m,s;
int g[maxn][maxn],_g[maxn][maxn];
int d[maxn],vis[maxn];
char str[maxl],res[maxn];

/*
int allow(int u){
	for(int v=0;v<n;v++)if(g[u][v]){
		if(v==s)return 0;
		if(!allow(v))return 0;
	}
	return 1;
}
*/

int trysort(){
	int i,j,p;
	memset(vis,0,sizeof(vis));
	memset(d,0,sizeof(d));
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(g[i][j])d[j]++;
	for(i=0;i<n;i++){
		p=-1;
		for(j=0;j<n;j++)
			if(vis[j]==0 && d[j]==0){
				if(p!=-1){
					//cout<<"At "<<i<<" th ";
					return 0;
				}
				p=j;
			}
		res[i]=(char)((int)'A'+p);vis[p]=1;
		for(j=0;j<n;j++)
			if(g[p][j])d[j]--;
	}
	return 1;
}

void work(){
	int i,j,u,v;
	int err=0,acc=0;
	char x,y;
	memset(g,0,sizeof(g));
	memset(_g,0,sizeof(_g));
	for(i=1;i<=m;i++){
		scanf("%s",str);
		sscanf(str,"%c<%c",&x,&y);
		u=x-'A';v=y-'A';g[u][v]=1;
		s=u;
		if(!err && _g[v][u])err=i;
		if(!acc && !err && trysort()) acc=i;
		_g[u][v]=1;for(j=0;j<n;j++)if(_g[v][j])_g[u][j]=1;
	}
	if(err){
		printf("Inconsistency found after %d relations.\n",err);
		return;
	}
	if(acc==0){
		printf("Sorted sequence cannot be determined.\n");
		return;
	}
	printf("Sorted sequence determined after %d relations: ",acc);
	for(i=0;i<n;i++)
		printf("%c",res[i]);
	printf(".\n");
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF && !(n==0 && m==0))
		work();
	return 0;
}
