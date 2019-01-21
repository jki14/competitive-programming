#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

const double eps=1e-8;
const int maxn=300,maxmid=3000000,limit=200000000;

struct Tpoint
{
    int x,y;
};

struct Tlich
{
    Tpoint p;
    int t,r;
};

struct Twisp
{
    Tpoint p;
};

struct Ttree
{
    Tpoint p;
    int r;
};

int lowtime[maxn],ptr[maxn],n,m,k,ans;
Tlich lich[maxn];
Twisp wisp[maxn];
Ttree tree[maxn];
bool g[maxn][maxn],v[maxn];

bool fsame(const double &x,const double &y)
{
  return fabs(x-y)<eps;
}

double fsqr(const double &x)
{
    return x*x;
}

double pdistance(const Tpoint &p1,const Tpoint &p2)
{
  return sqrt(fsqr(p1.x-p2.x)+fsqr(p1.y-p2.y));
}

double multi(const Tpoint &p1,const Tpoint &p2,const Tpoint &p0)
{
    return((p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y));
}

bool could(const int &x,const int &y)
{
    if(lich[y].r<pdistance(lich[y].p,wisp[x].p)-eps)
        return false;
    int i;
    for(i=1;i<=k;i++)
    {
        if(tree[i].r>pdistance(lich[y].p,tree[i].p)+eps)
            return false;
        if(fsqr(pdistance(lich[y].p,wisp[x].p))+fsqr(pdistance(tree[i].p,wisp[x].p))<fsqr(pdistance(lich[y].p,tree[i].p))-eps)
            continue;
        if(fsqr(pdistance(lich[y].p,wisp[x].p))+fsqr(pdistance(tree[i].p,lich[x].p))<fsqr(pdistance(wisp[y].p,tree[i].p))-eps)
            continue;
        if(fabs(multi(wisp[x].p,tree[i].p,lich[y].p))<pdistance(lich[y].p,wisp[x].p)*tree[i].r+eps)
            return false;
    }
    return true;
}

bool dfs(const int &x)
{
    for(int i=1;i<=m;i++)
    	if((g[i][x])&&(!v[i]))
    	{
    		v[i]=true;
    		if((!ptr[i])||(dfs(ptr[i])))
    		{
    			ptr[i]=x;
    			return true;
    		}
    	}
    return false;
}

int findans()
{
    int i,minp,kill=0,res=0;
    memset(lowtime,0,sizeof(lowtime));
    memset(ptr,0,sizeof(ptr));
    while(kill<m)
    {
    	minp=1;
    	for(i=2;i<=n;i++)minp=(lowtime[i]<lowtime[minp])?i:minp;
    	memset(v,0,sizeof(v));
    	if(lowtime[minp]>limit)return -1;
    	if(dfs(minp))
    	{
    		res=lowtime[minp];
    		lowtime[minp]+=lich[minp].t;
    		kill++;
    	}
    	else
    		lowtime[minp]=LONG_MAX;
    }
    return res;
}


void doit()
{
    int i,j;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=n;i++)
        scanf("%d%d%d%d",&lich[i].p.x,&lich[i].p.y,&lich[i].r,&lich[i].t);
    for(i=1;i<=m;i++)
        scanf("%d%d",&wisp[i].p.x,&wisp[i].p.y);
    for(i=1;i<=k;i++)
        scanf("%d%d%d",&tree[i].p.x,&tree[i].p.y,&tree[i].r);
    memset(g,0,sizeof(g));
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
            if(could(i,j))
                g[i][j]=true;
    }
    ans=findans();
    printf("%d\n",ans);
}

int main()
{
    int t;scanf("%d",&t);
    while(t--) doit();
    return 0;
}
