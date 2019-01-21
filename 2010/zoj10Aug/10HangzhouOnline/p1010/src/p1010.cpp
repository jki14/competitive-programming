#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

#define maxn 110

int n;
int beg[maxn],end[maxn];
int g[maxn][maxn];

int p[maxn],l[maxn][3],total,status[maxn],visited[maxn];

bool crs(const int x,const int y){
	if(beg[x]>=beg[y] && beg[x]<=end[y])return true;
	if(end[x]>=beg[y] && end[x]<=end[y])return true;
	if(beg[y]>=beg[x] && beg[y]<=end[x])return true;
	if(end[y]>=beg[x] && end[y]<=end[x])return true;
	return false;
}

int path(int &x){
	return 0;
}

void solve(){
	int i,j,k,pass;
	memset(p,0,sizeof(p));
	do{ i=0;
		do{ if(p[++i])pass=0;else {
			memset(l,0,sizeof(l));
			l[i][2]=0xff; pass=path(i);
			for(j=1;j<=n;j++)for(k=1;k<=n;k++)
				if(g[j][k]<0)g[j][k]=-g[j][k];
		};
		}while(i!=n && !pass);
		if(pass)total+=2;
	}while(i!=n && total!=n);
}

void upgrade(int r){
	int j=r,i=l[r][1];
	for(p[i]=j;l[i][2]<0xff;){
		p[j]=i;j=l[i][2];i=l[j][1];p[i]=j;
	} p[j]=i;
}


void work(){
	int i,j;
	for(i=0;i<n;i++)
		scanf("%d%d",&beg[i],&end[i]);
	memset(g,0,sizeof(g));
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(crs(i,j))
				g[i][j]=g[j][i]=1;

}

int main(){
	while(scanf("%d",&n)!=EOF && n!=0)
		work();
	return 0;
}
