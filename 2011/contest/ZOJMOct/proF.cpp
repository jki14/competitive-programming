#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<climits>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<set>
#include<map>
using namespace std;

#define S 121
#define K 2
#define N 50
#define M 5

#define pre now^1

const int inf=0x3fffffff;
const int m = 3;

char /*f[K][S][S][S],*/g[S][S][S];
int n,ans,a[N][M];

queue<int> qx[K],qy[K],qz[K];

void clear(const int &k){
	while(!qx[k].empty())qx[k].pop();
	while(!qy[k].empty())qy[k].pop();
	while(!qz[k].empty())qz[k].pop();
}

void push(const int &k,const int &x,const int &y,const int &z){
	qx[k].push(x);qy[k].push(y);qz[k].push(z);
}

int  pull(const int &k,int &x,int &y,int &z){
	if(qx[k].empty())return 0;
	x=qx[k].front();qx[k].pop();
	y=qy[k].front();qy[k].pop();
	z=qz[k].front();qz[k].pop();
	return 1;
}

void work(){
	/* Init */
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	memset(g,0,sizeof(g));
	int now=0;clear(now);clear(pre);
	push(now,0,0,0);
	/* Core */ans=inf;
	for(int i=1;i<=n;i++){now=pre;
		int x,y,z;
		while(pull(pre,x,y,z)){
			for(int j=1;j<=m;j++){
				int xx,yy,zz;
				xx=x;yy=y;zz=z;
				switch(j){
					case 1:xx+=a[i][j];break;
					case 2:yy+=a[i][j];break;
					case 3:zz+=a[i][j];break;
				}
				if(g[xx][yy][zz]<i){
					g[xx][yy][zz]=i;
					push(now,xx,yy,zz);
					if(i==n && xx==yy && xx==zz){
						ans=min(ans,xx);
					}
				}
			}
		}
	}
	/* Printout */
	if(ans<inf){
		printf("%d\n",ans);
	}else{
		printf("NO\n");
	}
}

int main(){
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}

