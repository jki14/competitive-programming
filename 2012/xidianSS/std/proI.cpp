#include <iostream>
#include <stdio.h>
#include<memory.h>
using namespace std;

int shu[300010];
int ershu[300010],v[300010];
int sanshu[300010];
int tt[300010];
int hei1,hei2,hei3,zz;
bool isshu[1000010];

int main()
{
    int i,tem,j,l,r,xiao,ans,n;
    shu[1]=1;
    for(i=2;;i++)
    {
        shu[i]=shu[i-1]+4;
        if(shu[i]>1000001) {hei1=i-1; break;}
    }
    memset(v,0,sizeof(v));
    for(i=2;i<=hei1;i++)
    {
        for(j=2;shu[j]*shu[j]<=shu[i];j++)
        {
            if(shu[i]%shu[j]==0)
            {
                tem=shu[i]/shu[j];
                if((tem-1)%4==0) { v[i]=1; break;}
            }
        }
    }
    hei2=0;
    memset(isshu,false,sizeof(isshu));
    for(i=1;i<=hei1;i++) 
    {
        if(v[i]==0) {ershu[++hei2]=shu[i]; isshu[ershu[hei2]]=true;}
    }
   

    memset(v,0,sizeof(v));
    for(i=2;i<=hei1;i++)
    {
        for(j=2;ershu[j]*ershu[j]<=shu[i];j++)
        {
            if(shu[i]%ershu[j]==0)
            {
                tem=shu[i]/ershu[j];
                if(isshu[tem]) {v[i]=1; break;}
            }
        }
    }
    hei3=0; v[1]=1;
    for(i=1;i<=hei1;i++)
    {
        if(v[i]==1) sanshu[++hei3]=shu[i];
    }
    ans=0;
    while(scanf("%d",&n)&&n)
    {
        ans=0;
        l=1,r=hei3;
        while(l<=r)
        {
            xiao=(l+r)>>1;
            if(sanshu[xiao]<=n)
            {
                ans=xiao;
                l=xiao+1;
            }
            else r=xiao-1;
        }
        printf("%d %d\n",n,ans-1);
    }
    return 0;
}