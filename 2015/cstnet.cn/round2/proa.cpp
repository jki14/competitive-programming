#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
using namespace std;

typedef long long lld;
typedef unsigned long long u64;
typedef double dou;
typedef pair<int, int> pii;

template<class T> inline T MIN(const T x, const T y){ return (x<y)?x:y; }
template<class T> inline T MAX(const T x, const T y){ return (x>y)?x:y; }

template<class T> inline void UPDMIN(T &x, const T y){ if(x>y)x=y; }
template<class T> inline void UPDMAX(T &x, const T y){ if(x<y)x=y; }

#define N 110000
#define M 210000

int n,r;
int nbs[N],nxt[M],dst[M],enm;
lld a[N],c[N],f[N],g[N];

void add_edge(const int u, const int v){
	nxt[++enm]=nbs[u];nbs[u]=enm;dst[enm]=v;
	nxt[++enm]=nbs[v];nbs[v]=enm;dst[enm]=u;
}

void calc(const int u, const int p){
	c[u]=a[u];f[u]=0LL;if(a[u])g[u]=0LL;
	for(int i=nbs[u];i;i=nxt[i]){
		int v=dst[i];
		if(v==p)continue;
		calc(v,u);
		c[u]+=c[v];
		if(c[v])
			UPDMAX(f[u],g[v]+c[v]);
		UPDMIN(g[u],g[v]+1);
	}
}

int main(){
	int T;scanf("%d",&T);
	for(int _T=1;_T<=T;_T++){
		printf("Case #%d: ",_T);
		scanf("%d%d",&n,&r);
		r--;
		memset(nbs,0,sizeof(nbs));enm=0;
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			u--;v--;
			add_edge(u,v);
		}
		for(int i=0;i<n;i++){
			scanf("%lld",&a[i]);
		}
		memset(f,0x3f,sizeof(f));
		memset(g,0x3f,sizeof(g));
		calc(r,-1);
		printf("%lld\n",f[r]);
	}
	return 0;
}

