#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
#include <map>
using namespace std;

#define maxn 500
#define p (*it).first
#define lmt 1000000000

int g[maxn][maxn],a[maxn][maxn];
int n,m,q;
bool mark[maxn];

map<int,int> s;
map<int,int>::iterator it;

void doit(){
	int i,u,v,d;
	memset(g,0x7f,sizeof(g));
	memset(a,0x7f,sizeof(a));
	memset(mark,0,sizeof(mark));
	s.clear();
	for(i=0;i<n;i++)
		g[i][i]=0;
	for(i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&d);
		if(g[u][v]>d)g[u][v]=d;
	}
	for(i=0;i<q;i++){
		scanf("%d",&d);
		if(d){
			scanf("%d%d",&u,&v);
			if((!mark[u]) || (!mark[v])){

			}else{

			}
		}else{
			if(mark[v])
				printf("ERROR! At point %d\n",v);
			else{
				scanf("%d",&v);s.insert(pair<int,int>(v,0));
				for(it=s.begin();it!=s.end();it++){
					a[v][p]=g[v][p];a[p][v]=g[p][v];
				}
			}
		}
	}
}

int main(){
	while(scanf("%d%d%d",&n,&m,&q)!=EOF && (n || m || q))doit();
	return 0;
}
