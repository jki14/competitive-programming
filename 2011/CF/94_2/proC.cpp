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
#include<string>
#include<queue>
#include<deque>
#include<set>
#include<map>
using namespace std;

#define N 11
#define S 110
#define K 9

#define xx x+dx[k]
#define yy y+dy[k]

const int n = 8;

const int dx[K]={ -1,-1,-1,0,0,0,1,1,1 };
const int dy[K]={ -1,0,1,-1,0,1,-1,0,1 };

int fx[S],fy[S],num;
int g[N][N][N];
char c[N][N];

typedef long long lld;

void work(){
	for(int i=0;i<n;i++)scanf("%s",c[i]);num=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(c[i][j]=='S'){ fx[num]=i;fy[num]=j;num++; }
	memset(g,0,sizeof(g));g[7][0][0]=1;
	for(int i=0;;i++){int alive=0;
		for(int x=0;x<n;x++)
			for(int y=0;y<n;y++)
				if(g[x][y][i]){
					alive=1;
					for(int k=0;k<K;k++){
						if(xx==0 || yy==7){ printf("WIN\n");return; }
						if(xx<0 || xx>=n || yy<0 || yy>=n)continue;
						g[xx][yy][i+1]=1;
						
						//printf("open %d,%d\n",xx,yy);

					}
				}
		if(!alive){ printf("LOSE\n");return; }
		for(int j=0;j<num;j++){
			if(fx[j]>=n)continue;
			g[fx[j]][fy[j]][i+1]=0;
			fx[j]++;
			g[fx[j]][fy[j]][i+1]=0;
			//printf("close %d,%d\n",fx[j],fy[j]);

		}
		if(i>n){ printf("WIN\n");return; }
	}
}

int main(){	
	work();
	return 0;
}

