#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

const int maxn=30;

int g[maxn][maxn];
int n,m,k,ans;

void doit()
{
	int x,y,tmp,maxk;
	memset(g,0,sizeof(g));
	scanf("%d%d",&n,&m);
	ans=m;
	while(m--)
	{
		scanf("%d%d",&x,&y);
		g[x][y]++;
	}
	maxk=1<<n;
	for(k=0;k<maxk;k++)
	{
		tmp=0;
		for(x=0;x<n;x++)
			for(y=0;y<n;y++)
			{
				if((x!=y)&&(((k>>x)&1)==((k>>y)&1)))
					tmp+=g[x][y];
			}
		if(ans>tmp)ans=tmp;
	}
	printf("%d\n",ans);
}

int main()
{
	int t;scanf("%d",&t);
	while(t--)doit();
}
