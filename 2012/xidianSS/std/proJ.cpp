#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <vector>
#include <map>
using namespace std;

bool pri[1000010];

void privat()
{
    int i,j;
    for(i=2;i<=1000000;i++) pri[i]=true;
    pri[1]=false;
    for(i=2;i<=1000000;i++)
    {
        if(pri[i]==false) continue;
        for(j=i+i;j<=1000000;j+=i) pri[j]=false;
    }
}

int f[1000010];
int q[55];

int main()
{
    privat();
    int i,zz,j,teming;
    int haing=0;

    f[0]=0;
    f[1]=1;
    q[++haing]=0; q[++haing]=1;
    for(i=2;i<=1000000;i++)
    {
        for(j=1;j<=haing;j++)
        {
            teming=i-q[j];
            if(pri[teming]==false)
            {
                f[i]=f[q[j]]+1;
                break;
            }
        }
        j=haing;
        while(f[i]<f[q[j]]&&j>=1)
        {
            q[j+1]=q[j];
            j--;
        }
        q[j+1]=i;
        haing++;
        if(haing>30) haing=30;
    }
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",f[n]);
    }
    return 0;
}