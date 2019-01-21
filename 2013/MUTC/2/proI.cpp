#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
using namespace std;

#define N 1100

#define _size(x) (int)x.size()

int n,m,ans;
int c[N][N],mrk[N],pnt[N];
vector<int> w[N];

int find(const int &u,const int &sgn){
	if(mrk[u]==sgn)return 0;mrk[u]=sgn;
	for(int i=0;i<_size(w[u]);i++){int v=w[u][i];
		if(pnt[v]<0 || find(pnt[v],sgn)){
			pnt[v]=u;
			return 1;
		}
	}
	return 0;
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF && !(n==0 && m==0)){
		memset(c,0xff,sizeof(c));
		for(int i=0;i<n;i++){
			int x,y;scanf("%d%d",&x,&y);
			c[x][y]=c[x+1][y]=i;
			//w[i].clear();
		}
		for(int i=0;i<m;i++){
			int x,y;scanf("%d%d",&x,&y);
			int a=c[x][y],b=c[x][y+1];
			w[i].clear();
			if(a>=0){
				w[i].push_back(a);
				//rig[a].push_back(i);
			}
			if(b>=0 && b!=a){
				w[i].push_back(b);
				//rig[b].push_back(i);
			}
		}
		ans=n+m;
		memset(mrk,0xff,sizeof(mrk));
		memset(pnt,0xff,sizeof(pnt));
		for(int i=0;i<m;i++){
			if(find(i,i))ans--;
		}
		printf("%d\n",ans);
	}
	return 0;
}
