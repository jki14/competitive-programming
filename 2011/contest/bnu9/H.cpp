#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
#include<map>
using namespace std;

#define maxn 110

const int dx[4][4]={ {0,-1,0,1},{-1,0,1,0},{0,1,0,-1},{1,0,-1,0} };
const int dy[4][4]={ {-1,0,1,0},{0,1,0,-1},{1,0,-1,0},{0,-1,0,1} };
const int dk[4][4]={ {3,0,1,2},{0,1,2,3},{1,2,3,0},{2,3,0,1} };

int n,m,x,y,k;
int vis[maxn][maxn][4];
int tar[maxn][maxn];
int rck[maxn][maxn];
char s[maxn];

int route(){
	for(int i=0;i<4;i++)
		if(!rck[x+dx[k][i]][y+dy[k][i]])return i;
	return 4;
}

void work(){
	int i,j;
	memset(tar,0,sizeof(tar));
	memset(rck,0,sizeof(rck));
	memset(vis,0,sizeof(vis));
	for(i=0;i<n;i++){
		scanf("%s",s);
		for(j=0;j<m;j++){
			if(s[j]=='#')rck[i][j]=1;
			if(s[j]=='T')tar[i][j]=1;
			if(s[j]=='S'){ x=i;y=j; }
		}
	}
	scanf("%s",s);
	switch(s[0]){
		case 'N':
			k=0;
			break;
		case 'E':
			k=1;
			break;
		case 'S':
			k=2;
			break;
		case 'W':
			k=3;
			break;
	}
	vis[x][y][k]=1;
	while(true){
		if(tar[x][y]){
			printf("YES\n");
			return;
		}
		i=route();
		if(i>3)break;
		x+=dx[k][i];
		y+=dy[k][i];
		k=dk[k][i];
		if(vis[x][y][k])break;
		vis[x][y][k]=1;
	}
	printf("NO\n");
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF)work();
	return 0;
}

