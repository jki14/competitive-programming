#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn=200,limit=100000;

int n,m,ans;
int g[maxn][maxn],p[maxn],l[maxn],x[maxn],d[maxn];
bool vis[maxn];
vector<int> s;

void doit()
{
	int i,j,t,v,k=-1;
	scanf("%d%d",&m,&n);
	ans=LONG_MAX;
	memset(g,0x7,sizeof(g));
	s.clear();
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&p[i],&l[i],&x[i]);
		s.push_back(l[i]);
		if(g[0][i]>p[i])g[0][i]=p[i];
		for(j=0;j<x[i];j++)
		{
			scanf("%d%d",&t,&v);
			if(g[t][i]>v)g[t][i]=v;
		}
	}
	sort(s.begin(),s.end());
	do
	{
		k++;
		memset(d,0x7,sizeof(d));
		memset(vis,0,sizeof(vis));
		d[0]=0;
		for(i=0;i<=n;i++)
		{
			v=0;
			for(j=0;j<=n;j++)
				if((l[j]>=s[k])&&(l[j]-s[k]<=m)&&((vis[v])||(d[v]>d[j]))&&(!vis[j]))
					v=j;
			vis[v]=true;
			//cout<<v<<":"<<d[v]<<",";
			if(d[v]>limit)break;
			for(j=0;j<=n;j++)
				if((l[j]>=s[k])&&(l[j]-s[k]<=m)&&(d[j]>d[v]+g[v][j]))
					d[j]=d[v]+g[v][j];
		}
		//cout<<endl;
		//cout<<" "<<s[k]<<"->"<<s[k]+m<<endl;
		//for(i=0;i<=n;i++)cout<<d[i]<<",";
		//cout<<endl;
		if(ans>d[1])ans=d[1];
	}while(s[k]+m<s[s.size()-1]);
	printf("%d",ans);
}

int main()
{
	doit();
	return 0;
}
