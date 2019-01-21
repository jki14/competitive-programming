//#pragma comment (linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <string>
#define ll long long
#define ci(val) scanf("%d",&val)
#define pi(val) printf("%d\n",val)
#define clr(a,val) memset(a,val,sizeof(a))
#define lowbit(x) ((x)&(-x))
#define inf 0x3f3f3f3f
#define inf64 1LL<<60
#define PI acos(-1.0)
#define eps 1e-8

//Game Theory
#define P "First"
#define N "Second"

#define maxn 1050000
#define mod 10009

using namespace std;

ll dp[2][maxn];
int n,y,m,i,j,k,t,x;
char s[25];
int que[2][maxn],top[2];
bool vis[maxn];

void readfile(char s[])
{
#ifndef ONLINE_JUDGE
	freopen(s,"r",stdin);
#endif
}

int main()
{
	//readfile("in.txt");
	while(scanf("%s",s)!=EOF)
    {
        n=strlen(s);
        m=1<<n;
       for(i=1;i<m;i++) dp[0][i]=0,dp[1][i]=0,vis[i]=0;
    /*
        for(x=0;x<2;x++)
        {
            for(i=0;i<top[x];i++) dp[x][que[x][i]]=0,vis[que[x][i]]=0;
            top[x]=0;
        }
        */
        top[0]=top[1]=0;
        if(s[0]=='+')
        {
            for(i=1;i<n;i++) que[0][top[0]++]=1<<i,dp[0][1<<i]++;
        }
        else
        {
            printf("0\n");
            continue;
        }
        t=0;
        for(i=0,j;i<n-1;i++)
        {
           for(j=0;j<top[1-t];j++) dp[1-t][que[1-t][j]]=0,vis[que[1-t][j]]=0;
            top[1-t]=0;
            while(top[t])
            {
                j=que[t][--top[t]];
                if(dp[t][j])
                {
                    if(s[i+1]=='+')
                    {
                        for(k=i+2;k<n;k++)
                        {
                            y=(1<<k)+j;
                            if(!((1<<k)&j))
                            {
                                if(!vis[y])
                                    que[1-t][top[1-t]++]=y,vis[y]=1;
                                dp[1-t][y]+=dp[t][j];
                            }
                        }
                    }
                    else
                    {
                        for(k=i;k>=0;k--)
                        {
                            y=(1<<k)+j;
                            if(!((1<<k)&j))
                            {
                                if(!vis[y])
                                que[1-t][top[1-t]++]=y,vis[y]=1;
                                dp[1-t][y]+=dp[t][j];
                            }
                        }
                    }
                }
            }
            t=1-t;
        }
        printf("%I64d\n",dp[t][m-1]);
    }
	return 0;
}
