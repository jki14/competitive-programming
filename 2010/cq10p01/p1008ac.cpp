#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<climits>
#include<algorithm>
#include<queue>
using namespace std;

#define point list.front()
#define l k^1

struct item
{
	int k,m,c,t;
};

const int maxn=101,maxm=101,maxt=256,maxk=2,maxc=9,zero=25,themax=200;

//queue<item> list;
//item tmp;

int n,m,ans;
int f[maxk][maxm][maxc][maxt],s;
bool vis[maxk][maxm][maxc][maxt];

int tsum(int x)
{
	int res=0;
	while(x)
	{
		if(x&1)res++;
		x>>=1;
	}
	return res;
}

bool doit(const int &timer)
{
	scanf("%d%d",&n,&m);
	//cout<<"n="<<n<<";"<<"m="<<m<<endl;
	if((!n)&&(!m))return false;
	int i,j,k=0,a,b,c,t,_t;
	//while(!list.empty())list.pop();
	memset(f,0x7F,sizeof(f));
	memset(vis,0,sizeof(vis));
	s=0;
	f[k][0][8][0]=0;
	//tmp.k=k;j=0;c=0;t=0;
	//list.push(tmp);
	for(i=1;i<=n;i++)
	{
		memset(f[l],0x7F,sizeof(f[l]));
		/*//De
		for(j=0;j<maxn;j++)
			for(c=0;c<maxc;c++)
				for(t=0;t<maxt;t++)
					if(f[l][j][c][t]<themax)
					{
						cout<<endl<<"DebugInfo:memset wrong!"<<endl;
						return false;
					}
		//Bug*/
		scanf("%d",&a);
		a=a-zero;
		b=1<<a;
		//while((!list.empty())&&(point.k==k))
		for(j=0;j<=m&&j<=i;j++)
		for(c=0;c<maxc;c++)
		for(t=0;t<maxt;t++)
		{
			if(f[k][j][c][t]>themax)continue;
			//vis[point.k][j][c][t]=false;
			if(a==c)
			{
				_t=((t&b)==b)?t^b:t;
				if(f[l][j][a][_t]>f[k][j][c][t])
					f[l][j][a][_t]=f[k][j][c][t];
					//cout<<"At: "<<i<<" "<<"f["<<j<<"]["<<a<<"]["<<_t<<"]="<<f[l][j][c][_t]<<endl;
			}
			else
			{
				_t=((t&b)==b)?t^b:t;
				if(f[l][j][a][_t]>f[k][j][c][t]+1)
				{
					f[l][j][a][_t]=f[k][j][c][t]+1;
					//cout<<"At: "<<i<<" "<<"f["<<j<<"]["<<a<<"]["<<_t<<"]="<<f[l][j][a][_t]<<endl;
				}
			}
			if(j<m)
			{
				_t=((t&b)==b)?t:(((s&b)==b)?t:t|b);
				//cout<<"This time t = "<<t<<endl;
				if(f[l][j+1][c][_t]>f[k][j][c][t])
				{
					f[l][j+1][c][_t]=f[k][j][c][t];
					//cout<<"At: "<<i<<" "<<"f["<<j+1<<"]["<<c<<"]["<<_t<<"]="<<f[l][j+1][c][_t]<<endl;
				}
			}
		}
		s|=b;
		//cout<<"b="<<b<<endl;
		//cout<<"s="<<s<<endl;
		k=l;
	}
	ans=LONG_MAX>>2;
	for(c=0;c<maxc;c++)
		for(t=0;t<maxt;t++)
			if(ans>f[k][m][c][t]+tsum(t))ans=f[k][m][c][t]+tsum(t);
	printf("Case %d: %d\n\n",timer,ans);
	return true;
}

int main()
{
	int t=1;
	while(doit(t++));
	return 0;
}
