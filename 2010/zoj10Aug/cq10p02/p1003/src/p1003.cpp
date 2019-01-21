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

const int maxn=50,maxk=60;

struct ritem
{
	int x,y;
};

struct qitem
{
	int h,m,q;
	bool operator < (const qitem & x)const
    {
		return h<x.h || ((h==x.h)&&(m<x.m));
	}
};

ritem res[maxk];
map<qitem,int> s;
map<qitem,int>::iterator it;
qitem tmp;
bool vis[maxn][maxn];
int a[maxn][maxn];
int n,m,k;

bool mlay(int x,int y,int q)
{
	if(y+q>m+1)return false;
	for(int i=y;i<y+q;i++)
		if(vis[x][i])return false;
	return true;
}

bool doit()
{
	scanf("%d %d %d",&n,&m,&k);
	if((!n)&&(!m)&&(!k))return false;
	int i,j;
	ritem smax,mmax;
	memset(vis,0,sizeof(vis));
	s.clear();
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(i=1;i<=k;i++)
	{
		scanf("%d:%d %d",&tmp.h,&tmp.m,&tmp.q);
		s.insert(pair<qitem,int>(tmp,i));
	}
	for(it=s.begin();it!=s.end();it++)
	{
		//cout<<"Lay: "<<(*it).first.h<<":"<<(*it).first.m<<" "<<(*it).first.q<<" At: m->";
		smax.x=-1;mmax.x=-1;
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
			{
				if((!vis[i][j])&&((smax.x<0)||(a[smax.x][smax.y]<a[i][j])))
				{
					smax.x=i;smax.y=j;
				}
				if((mlay(i,j,(*it).first.q))&&((mmax.x<0)||(a[mmax.x][mmax.y]<a[i][j])))
				{
					mmax.x=i;mmax.y=j;
				}
			}
		//cout<<mmax.x<<":"<<mmax.y<<" s->"<<smax.x<<":"<<smax.y<<endl;
		if(mmax.x<0)
		{
			if(smax.x>0)vis[smax.x][smax.y]=true;
			res[(*it).second]=smax;
		}
		else
		{
			for(i=mmax.y;i<mmax.y+(*it).first.q;i++)
				vis[mmax.x][i]=true;
			res[(*it).second]=mmax;
		}
	}
	for(i=1;i<=k;i++)
		if(res[i].x>0)
			printf("%d %d\n",res[i].x,res[i].y);
		else
			printf("-1\n");
	return true;
}

int main()
{
	while(doit());
	return 0;
}
