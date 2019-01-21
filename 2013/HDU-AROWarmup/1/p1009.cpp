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
#include<list>
#include<bitset>
#include<set>
#include<map>
#include<functional>
#include<numeric>
#include<utility>
#include<iomanip>
using namespace std;

#define N 1100000
#define M 2100000

const int inf=0x3f3f3f3f;

int n;
int vst[N],mrk;
int seq[N],l,r;
int f[N],g[N];
int nbs[N],nxt[M],dst[M],num;

int main(){
	int T;scanf("%d",&T);
	memset(vst,0,sizeof(vst));mrk=0;
	while(T--){
		scanf("%d",&n);
		memset(nbs,0,sizeof(nbs));num=0;
		for(int i=1;i<n;i++){
			int u,v;scanf("%d%d",&u,&v);
			nxt[++num]=nbs[u];nbs[u]=num;dst[num]=v;
			nxt[++num]=nbs[v];nbs[v]=num;dst[num]=u;	
		}
		//BFS
		l=r=0;seq[++r]=1;++mrk;
		while(l<r){int u=seq[++l];vst[u]=mrk;
			for(int i=nbs[u];i;i=nxt[i]){int v=dst[i];
				if(vst[v]==mrk)continue;
				seq[++r]=v;
			}
		}
		//DP
		++mrk;
		for(int i=r;i;i--){int u=seq[i];f[u]=0;
			int fir,sec;fir=sec=0;
			for(int i=nbs[u];i;i=nxt[i]){int v=dst[i];
				if(vst[v]!=mrk)continue;
				f[u]+=f[v]+1;
				int d=g[v]-f[v]-1;
				if(d<fir){
					sec=fir;
					fir=d;
				}else if(d<sec)sec=d;
			}
			g[u]=f[u];f[u]+=fir+sec;g[u]+=fir;
			vst[u]=mrk;
			//printf("f[%d]=%d g[%d]=%d\n",u,f[u],u,g[u]);
		}
		printf("%d\n",(f[1]<<1)|1);
	}
	return 0;
}

