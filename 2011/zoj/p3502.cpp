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

#define maxn 11
#define maxK 1100

int n,K;
int a[maxn][maxn];
int f[maxn][maxK];
string g[maxn][maxK];
double res;

set< int > s[maxn];
set< int >::iterator it;

int top(const int &k,const int &x){
	int ret=a[x][x],i;
	for(i=0;i<n;i++){
		if((k & (1<<i))==0)continue;
		ret=max(ret,a[i][x]);
	}
	return ret;
}

void work(){
	int i,j,k,p;
	int path;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	memset(f,0x8f,sizeof(f));
	for(i=0;i<=n;i++)s[i].clear();
	s[0].insert(0);g[0][0]="";f[0][0]=0;
	for(i=0;i<n;i++){
		for(it=s[i].begin();it!=s[i].end();it++){
			k=(*it);
			for(p=0;p<n;p++){
				if((k & (1<<p))!=0)continue;
				j=k|(1<<p);
				s[i+1].insert(j);
				path=top(k,p);
				//f[i][j]=max(f[i][j],f[i][k]+top(k,p));
				if(f[i+1][j]<f[i][k]+path || (f[i+1][j]==f[i][k]+path && g[i+1][j]>g[i][k]+((char)('A'+p)))){
					f[i+1][j]=f[i][k]+path;
					g[i+1][j]=g[i][k]+((char)('A'+p));
				}
			}
		}
	}
	it=s[n].begin();k=(*it);
	res=((double)f[n][k])/100.0;
	printf("%.2f\n%s\n",res,g[n][k].c_str());
}

int main(){
	int T;scanf("%d",&T);
	while(T--){scanf("%d",&n);
		work();
	}
	return 0;
}

