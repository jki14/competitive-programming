#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

#define maxn 300

int n,m,res,x,y,xx,yy;
int a[maxn][maxn],b[maxn][maxn];


void work(){
	int i,j;res=-1;
	x=y=LONG_MAX;
	xx=yy=LONG_MIN;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&a[i][j]);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&b[i][j]);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			if(abs(a[i][j]-b[i][j])>5){
				res=0;
				x=min(x,i+1);xx=max(xx,i+1);
				y=min(y,j+1);yy=max(yy,j+1);
			}
	if(!res)
		printf("%d %d %d %d\n",x,y,xx,yy);
	else
		printf("-1\n");
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF)work();
	return 0;
}
