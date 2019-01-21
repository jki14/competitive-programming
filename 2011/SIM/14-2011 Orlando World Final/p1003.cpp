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

#define N 210
#define W 110
#define P 41000
#define K 4

const int reschr[6]={ 'W','A','K','J','S','D' };

const int dx[K]={ -1,0,1,0 };
const int dy[K]={ 0,1,0,-1 };

int T;

set<int> hash;

int n,m,w;
int c[N][N],b[N][N];
int num,blk,mk[N][N];

char s[W],ans[P];

inline int trans(const char &c){
	if(c<='9')return c-'0';
	return 10+c-'a';
}

void dfs1(const int &x,const int &y){
	if(x<0 || x>n+1 || y<0 || y>m+1)return;
	if(mk[x][y])return;
	if(!c[x][y]){
		hash.insert(b[x][y]);
		return;	
	}
	mk[x][y]=1;
	for(int i=0;i<K;i++)dfs1(x+dx[i],y+dy[i]);
}

void dfs0(const int &x,const int &y){
	if(x<0 || x>n+1 || y<0 || y>m+1)return;
	if(c[x][y] || b[x][y])return;
	b[x][y]=blk;
	for(int i=0;i<K;i++)dfs0(x+dx[i],y+dy[i]);
}

void work(){T++;
	/* init */
	m=w<<2;num=blk=0;
	memset(c,0,sizeof(c));
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		for(int j=0;j<w;j++){
			int val=trans(s[j]);
			for(int k=0;k<4;k++){
				if(val&(8>>k)){
					c[i][j*4+k+1]=1;
				}
			}
		}
	}

	/* mark white */
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=m+1;j++){
			if(c[i][j] || b[i][j])continue;
			++blk;
			dfs0(i,j);
		}

	/* core */
	memset(mk,0,sizeof(mk));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(!c[i][j] || mk[i][j])continue;
			hash.clear();
			dfs1(i,j);
			ans[num++]=reschr[hash.size()-1];
		}

	/* print-out */
	ans[num]=0;sort(ans,ans+num);
	printf("Case %d: %s\n",T,ans);
}

int main(){T=0;
	while(scanf("%d%d",&n,&w)!=EOF && (n || w))
		work();
	return 0;
}

