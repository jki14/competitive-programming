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

queue<item> list;
item tmp;

int n,m,ans,s;
int f[maxk][maxm][maxc][maxt];
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
    if((!n)&&(!m))return false;
    int i,k,a,b,c,t;
    while(!list.empty())list.pop();
    memset(f,0x7F,sizeof(f));
    memset(vis,0,sizeof(vis));
    s=0;k=0;
    f[k][0][8][0]=0;
    tmp.k=k;tmp.m=0;tmp.c=8;tmp.t=0;
    list.push(tmp);
    for(i=1;i<=n;i++)
    {
        memset(f[l],0x7F,sizeof(f[l]));
        scanf("%d",&a);
        a=a-zero;
        b=1<<a;
        while((!list.empty())&&(point.k==k))
        {
        	//cout<<"Update From "<<point.k<<";"<<point.m<<";"<<point.c<<";"<<point.t<<" Value="<<f[point.k][point.m][point.c][point.t]<<endl;
            vis[point.k][point.m][point.c][point.t]=false;
            if(a==point.c)
            {
            	tmp.k=l;tmp.m=point.m;tmp.c=a;
                tmp.t=((point.t&b)==b)?point.t^b:point.t;
                if(f[tmp.k][tmp.m][tmp.c][tmp.t]>f[point.k][point.m][point.c][point.t])
                {
                	f[tmp.k][tmp.m][tmp.c][tmp.t]=f[point.k][point.m][point.c][point.t];
                    if(!vis[tmp.k][tmp.m][tmp.c][tmp.t])
                    {
                        list.push(tmp);
                        vis[tmp.k][tmp.m][tmp.c][tmp.t]=true;
                    }
                }
            }
            else
            {
            	tmp.k=l;tmp.m=point.m;tmp.c=a;
                tmp.t=((point.t&b)==b)?point.t^b:point.t;
                if(f[tmp.k][tmp.m][tmp.c][tmp.t]>f[point.k][point.m][point.c][point.t]+1)
                {
                	f[tmp.k][tmp.m][tmp.c][tmp.t]=f[point.k][point.m][point.c][point.t]+1;
                    if(!vis[tmp.k][tmp.m][tmp.c][tmp.t])
                    {
                        list.push(tmp);
                        vis[tmp.k][tmp.m][tmp.c][tmp.t]=true;
                    }
                }
            }
            if(point.m<m)
            {
            	tmp.k=l;tmp.m=point.m+1;tmp.c=point.c;
            	tmp.t=((point.t&b)==b)?point.t:(((s&b)==b)?point.t:point.t|b);
                if(f[tmp.k][tmp.m][tmp.c][tmp.t]>f[point.k][point.m][point.c][point.t])
                {
                	f[tmp.k][tmp.m][tmp.c][tmp.t]=f[point.k][point.m][point.c][point.t];
                    if(!vis[tmp.k][tmp.m][tmp.c][tmp.t])
                    {
                    	list.push(tmp);
                        vis[tmp.k][tmp.m][tmp.c][tmp.t]=true;
                    }
                }
            }
            list.pop();
        }
        s|=b;
        k=l;
    }
    ans=LONG_MAX>>2;
    for(c=0;c<maxc;c++)
    	for(t=0;t<maxt;t++)
    		if(ans>f[k][m][c][t]+tsum(t))ans=f[k][m][c][t]+tsum(t);
    printf("Case %d: %d\n",timer,ans);
    printf("\n");
    return true;
}

int main()
{
    int t=1;
    while(doit(t++));
    return 0;
}
