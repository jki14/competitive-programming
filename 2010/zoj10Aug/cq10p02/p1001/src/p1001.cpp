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
    int k,i,v,q,vk;
};

const int maxk=2,maxn=110,maxm=1100,maxv=110,maxq=10,maxl=10,vk=2;

queue<item> list;
item tmp;

int n,m,q,ans;
int f[maxk][maxn][maxv][maxq][vk];
int a[maxn][maxm],c[maxn][maxm];
bool vis[maxk][maxn][maxv][maxq][vk];
char str[maxl];

bool doit()
{
    scanf("%d %d %d",&n,&m,&q);
    if((!n)&&(!m)&&(!q))return false;
    int i,j,k;
    while(!list.empty())list.pop();
    memset(a,0,sizeof(a));
    memset(c,0,sizeof(c));
    memset(f,0x8F,sizeof(f));
    memset(vis,0,sizeof(vis));
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
            scanf("%s",str);
            if(str[0]=='$')
                sscanf(str,"$%d",&a[i][j]);
            else
                if(i)sscanf(str,"v%d",&c[i][j]);
        }
    k=0;
    tmp.k=k;tmp.i=0;tmp.v=0;tmp.q=0;tmp.vk=1;
    f[tmp.k][tmp.i][tmp.v][tmp.q][tmp.vk]=a[0][0];
    list.push(tmp);
    for(i=1;i<m;i++)
    {
        memset(f[l],0x8F,sizeof(f[l]));
        while((!list.empty())&&(point.k==k))
        {
            vis[point.k][point.i][point.v][point.q][point.vk]=false;
            for(j=-1;j<=1;j++)
            {
                tmp.k=l;tmp.i=point.i+(point.v+j)*((point.vk)?1:-1);
                if(tmp.i>=n)tmp.i=n-1;
                if(tmp.i<0)tmp.i=0;
                tmp.v=(tmp.i)?(point.v+j)*((point.vk)?1:-1):0;
                if(tmp.i)tmp.v+=c[tmp.i][i];
                if((tmp.v>=maxv)||(tmp.v<=-maxv))continue;
                if(tmp.v>=0)
                    tmp.vk=1;
                else
                {
                    tmp.v=-tmp.v;
                    tmp.vk=0;
                }
                tmp.q=(tmp.i)?point.q+1:0;
                if(tmp.q>=q)continue;
                if(f[tmp.k][tmp.i][tmp.v][tmp.q][tmp.vk]<f[point.k][point.i][point.v][point.q][point.vk]+a[tmp.i][i])
                {
                    f[tmp.k][tmp.i][tmp.v][tmp.q][tmp.vk]=f[point.k][point.i][point.v][point.q][point.vk]+a[tmp.i][i];
                    //cout<<"Update:f["<<tmp.k<<"]["<<tmp.i<<"]["<<tmp.v<<"]["<<tmp.q<<"]["<<tmp.vk<<"] = "<<f[tmp.k][tmp.i][tmp.v][tmp.q][tmp.vk]<<endl;
                    if(!vis[tmp.k][tmp.i][tmp.v][tmp.q][tmp.vk])
                    {
                        vis[tmp.k][tmp.i][tmp.v][tmp.q][tmp.vk]=true;
                        list.push(tmp);
                    }
                }
            }
            list.pop();
        }
        k=l;
    }
    ans=f[k][0][0][0][1];
    printf("%d\n",ans);
    return true;
}

int main()
{
    while(doit());
    return 0;
}
