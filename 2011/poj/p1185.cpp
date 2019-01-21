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
#include<set>
#include<map>
using namespace std;

#define maxn 110
#define maxm 21
#define maxk 110
#define maxK 11000
#define L 2

#define X xque[i-1][tail[i-1]]
#define Y yque[i-1][tail[i-1]]

int bit[maxm];
int s[maxk],path[maxk],num;
vector<int> g[maxk][maxk];

int n,m,ans;
int a[maxn];
int f[maxn][maxk][maxk],xque[maxn][maxK],yque[maxn][maxK],tail[maxn];

char cs[maxm];

int able(const int &k){path[num]=0;
	for(int i=0;i<m;i++){
		if(!(bit[i]&k))continue;
		path[num]++;
		if(i+1<m){
			if(bit[i+1]&k)return 0;
			if(i+2<m && (bit[i+2]&k))return 0;
		}
	}
	return 1;
}

int suit(const int &x,const int &y,const int &z){
	for(int i=0;i<m;i++)
		if((bit[i]&x || bit[i]&y) && bit[i]&z)return 0;
	return 1;
}

void build(){
	int i,j,k,K;
	num=0;K=1<<m;
	for(i=0;i<m;i++)bit[i]=1<<i;
	for(i=0;i<K;i++)
		if(able(i))s[num++]=i;
	for(i=0;i<num;i++)
		for(j=0;j<num;j++){
			g[i][j].clear();
			for(k=0;k<num;k++)
				if(suit(s[i],s[j],s[k]))g[i][j].push_back(k);
		}
}

void work(){
	int i,j,k,size;
	build();ans=0;
	//printf("num=%d\n",num);
	for(i=1;i<=n;i++){
		scanf("%s",cs);
		for(a[i]=j=0;j<m;j++){
			a[i]<<=1;
			if(cs[j]=='H')a[i]|=1;
		}
	}
	memset(f,0x8f,sizeof(f));
	tail[0]=1;xque[0][tail[0]]=0;yque[0][tail[0]]=0;
	f[0][0][0]=0;
	for(i=1;i<=n;i++){
		tail[i]=0;
		for(;tail[i-1];tail[i-1]--){size=g[X][Y].size();
			for(j=0;j<size;j++){k=g[X][Y][j];
				if(s[k]&a[i])continue;
				if(f[i][Y][k]<f[i-1][X][Y]+path[k]){
					if(f[i][Y][k]<0){ xque[i][++tail[i]]=Y;yque[i][tail[i]]=k; }
					f[i][Y][k]=f[i-1][X][Y]+path[k];
					if(i==n)ans=max(ans,f[i][Y][k]);
				}
			}
		}
	}
	printf("%d\n",ans);
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF)
		work();
	return 0;
}

