#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<climits>
#include<algorithm>
using namespace std;

const int maxv=600,maxn=500;
const int sv=500000;

int v1,v2,n;
int f[maxv][maxv][2];

bool doit(int &t)
{
	scanf("%d %d %d",&v1,&v2,&n);
	if((!v1)&&(!v2)&&(!n))return false;
	int i,j,k;
	int p,h,s,min=0,max;
	t++;
	memset(f,0,sizeof(f));
	for(k=0;k<n;k++)
	{
		scanf("%d %d %d",&p,&h,&s);
		if(s==1)
		{
			h+=sv;
			min+=sv;
		}
		for(i=v1;i>=0;i--)
			for(j=v2;j>=0;j--)
			{
				if(f[i][j][1]<f[i][j][0]+h)
					f[i][j][1]=f[i][j][0]+h;
				if((i>=p)&&(f[i][j][0]<f[i-p][j][0]+h))
					f[i][j][0]=f[i-p][j][0]+h;
				if((j>=p)&&(f[i][j][0]<f[i][j-p][0]+h))
					f[i][j][0]=f[i][j-p][0]+h;
				if((i>=p)&&(f[i][j][1]<f[i-p][j][1]+h))
					f[i][j][1]=f[i-p][j][1]+h;
				if((j>=p)&&(f[i][j][1]<f[i][j-p][1]+h))
					f[i][j][1]=f[i][j-p][1]+h;
			}
	}
	max=f[v1][v2][0];
	if(max<f[v1][v2][1])max=f[v1][v2][1];
	if(max<min)
		printf("Case %d: %d\n",t,-1);
	else
	{
		while(max>sv)max%=sv;
		printf("Case %d: %d\n",t,max%sv);
	}
	printf("\n");
	return true;
}

int main()
{
	int t=0;
	while(doit(t));
	return 0;
}
