#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

const int maxn=1100,maxm=110000,maxk=4,X=((int)'X')-1,maxl=5;

struct item
{
	int s,e;
};

item r[maxn][maxk];
bool vis[maxn][maxk];
vector<int> g[maxn][maxk];
int d[maxn][maxk];
stack<int> s;

int timer;
int n,m;

bool doit()
{
	int k,x,y;
	int i,j;
	char tmp[maxl];
	scanf("%d %d",&n,&m);
	if((!n)&&(!m))return false;
	memset(vis,0,sizeof(vis));
	memset(d,0,sizeof(d));
	for(i=1;i<=n;i++)
		for(k=0;k<=3;k++)
			g[i][k].clear();
	while(!s.empty())s.pop();
	while(m--)
	{
		scanf("%s %d %d",tmp,&x,&y);
		k=(tmp[0]=='I')?0:(int)tmp[0]-X;
		g[x][k].push_back(y);
		if(!k)
			g[y][k].push_back(x);
		else
		{
			d[y][k]++;
		}
	}
	for(k=1;k<=3;k++)
	{
		for(i=1;i<=n;i++)
			if((!vis[i][k])&&(!d[i][k]))
			{
				s.push(i);
			}
	}
	return true;
}

int main()
{
	timer=1;
	while(doit())timer++;
	return 0;
}
