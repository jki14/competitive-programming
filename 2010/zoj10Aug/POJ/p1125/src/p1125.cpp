#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define maxn 110
#define maxl 11000
#define gmin(a,b) if(a>b)a=b
#define gmax(a,b) if(a<b)a=b

int n,resx,resy;
int a[maxn][maxn];

void doit(){
	int i,j,k,x,y;
	memset(a,0x1,sizeof(a));
	for(i=1;i<=n;i++){
		scanf("%d",&k);
		while(k--){
			scanf("%d%d",&x,&y);
			gmin(a[i][x],y);
		}
		a[i][i]=0;
	}
	for(i=1;i<=n;i++)
		for(x=1;x<=n;x++)
			for(y=1;y<=n;y++)
				gmin(a[x][y],a[x][i]+a[i][y]);
	y=LONG_MAX;resy=LONG_MAX;
	for(i=1;i<=n;i++){
		x=0;k=LONG_MIN;for(j=1;j<=n;j++){
			x+=a[i][j];
			gmax(k,a[i][j]);
		}
		if(y>x){ y=x;resy=k;resx=i; }
	}
	//cout<<":::"<<a[4][1]<<" "<<a[4][2]<<" "<<a[4][3]<<" "<<a[4][4]<<" "<<a[4][5]<<endl;
	if(resy>=maxl)
		printf("disjoint\n");
	else
		printf("%d %d\n",resx,resy);
}

int main(){
	while(scanf("%d",&n)!=EOF && n)doit();
	return 0;
}
