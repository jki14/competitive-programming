#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define maxx 100
#define maxr maxx*maxx

#define xp(i) x+path[i][0]
#define yp(i) y+path[i][1]

const int path[8][2]={{-1,-2},{1,-2},{-2,-1},{2,-1},{-2,1},{2,1},{-1,2},{1,2}};

int timer;
int a[maxx][maxx];
int xr[maxr],yr[maxr];
int n,m;

int visable(const int &x,const int &y){
	if(x<0 || x>=n || y<0 || y>=m)return 0;
	if(a[x][y])return 0;
	return 1;
}

int dfs(const int &x,const int &y,const int &k){
	a[x][y]=1;xr[k]=x;yr[k]=y;
	if(k==n*m-1)return 1;
	for(int i=0;i<8;i++){
		//cout<<"Move "<<(char)('A'+yp(i))<<1+xp(i)<<endl;
		if(visable(xp(i),yp(i))){
			//cout<<"Try "<<(char)('A'+yp(i))<<1+xp(i)<<endl;
			if(dfs(xp(i),yp(i),k+1))
				return 1;
			else
				a[xp(i)][yp(i)]=0;
			//cout<<"Fault"<<endl;
		}
	}
	return 0;
}

void work(){
	scanf("%d%d",&n,&m);
	memset(a,0,sizeof(a));
	printf("Scenario #%d:\n",timer);
	if(!dfs(0,0,0))
		printf("impossible");
	else
		for(int i=0;i<n*m;i++){
			printf("%c%d",'A'+yr[i],1+xr[i]);
		}
	printf("\n\n");
}

int main(){
	int t;scanf("%d",&t);
	for(timer=1;timer<=t;timer++)work();
	return 0;
}
