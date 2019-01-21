#include <cstdio>
#include <cstring>

#define V 11000
#define E 21000
#define S 3

int n, m, ans;
int nbs[V], nxt[E], dst[E], enm;
int f[V][S];

const int inf=10086;

template<class T> inline void updmin(T &x, const T y){ if(x>y)x=y; }
template<class T> inline void updmax(T &x, const T y){ if(x<y)x=y; }

inline void add_edge(const int u, const int v){
	nxt[++enm]=nbs[u]; nbs[u]=enm; dst[enm]=v;
	nxt[++enm]=nbs[v]; nbs[v]=enm; dst[enm]=u;
}

int dp_entry(const int u, const int p, const int d){
	int sum=0;
	for(int i=nbs[u]; i; i=nxt[i]){
		int v=dst[i];
		if(v==p)continue;
		sum+=dp_entry(v, u, d+1);
	}
	f[u][0]=0;
	f[u][1]=0;
	f[u][2]=1;
	int bst=inf;
	for(int i=nbs[u]; i; i=nxt[i]){
		int v=dst[i];
		if(v==p)continue;
		f[u][0]+=f[v][1];
		f[u][1]+=f[v][1];
		updmin(bst, f[v][2]-f[v][1]);
		f[u][2]+=f[v][0];
	}
	f[u][1]+=bst;
	updmin(f[u][1], f[u][2]);
	updmin(f[u][0], f[u][1]);
	if(d<m){
		return sum;
	}else return f[u][0];
}

int main(){
	int T;if(!scanf("%d", &T))return 1;
	while(T--){
		if(scanf("%d%d", &n, &m)!=2)return 1;
		memset(nbs, 0, sizeof(nbs));enm=0;
		for(int i=1; i<n; i++){
			int u, v;
			if(scanf("%d%d", &u, &v)!=2)return 1;
			u--;v--;
			add_edge(u, v);
		}
		ans=inf;
		for(int i=0; i<n; i++){
			updmin(ans, dp_entry(i, -1, 0));
		}
		printf("%d\n", ans);
	}
}
