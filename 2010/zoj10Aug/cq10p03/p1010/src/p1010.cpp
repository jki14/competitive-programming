#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

#define p a[v]

const int maxn=1100,maxk=20;

struct item
{
	int x,y,c;
};

int n,m,k;
int f[maxn][maxn];
item a[maxk];

void doit()
{
	int i,j,v;
	scanf("%d%d%d",&k,&n,&m);
	memset(f,0,sizeof(f));
	for(i=0;i<k;i++)
	{
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].c);
		if(f[a[i].x][a[i].y]<a[i].c)f[a[i].x][a[i].y]=a[i].c;
		if(f[a[i].y][a[i].x]<a[i].c)f[a[i].y][a[i].x]=a[i].c;
	}
	for(i=0;i<=n;i++)
		for(j=0;j<=m;j++)
		{
			for(v=0;v<k;v++)
			{
				if((i>=p.x)&&(j>=p.y)&&(f[i][j]<f[i-p.x][j]+f[p.x][j]))
					f[i][j]=f[i-p.x][j]+f[p.x][j];
				if((i>=p.y)&&(j>=p.x)&&(f[i][j]<f[i-p.y][j]+f[p.y][j]))
					f[i][j]=f[i-p.y][j]+f[p.y][j];
				if((i>=p.x)&&(j>=p.y)&&(f[i][j]<f[i][j-p.y]+f[i][p.y]))
					f[i][j]=f[i][j-p.y]+f[i][p.y];
				if((i>=p.y)&&(j>=p.x)&&(f[i][j]<f[i][j-p.x]+f[i][p.x]))
					f[i][j]=f[i][j-p.x]+f[i][p.x];
				if(f[j][i]<f[i][j])f[j][i]=f[i][j];
			}
		}
	printf("%d\n",f[n][m]);
}

int main()
{
	int t;scanf("%d",&t);
	while(t--)doit();
	return 0;
}
