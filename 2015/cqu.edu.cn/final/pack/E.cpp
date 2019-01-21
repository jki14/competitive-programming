#include <cstdio>
#include <cstring>

#define N 11000
#define E 21000
#define M 8
#define B 2

const int INF=10086;

int n, m;
int nbs[N], nxt[E], dst[E], enm;
int f[N][B][B][M], ans;

template<class T> void updmax(T &x, const T y){ if(x<y)x=y; }
template<class T> void updmin(T &x, const T y){ if(x>y)x=y; }

void add_edge(const int u, const int v){
	nxt[++enm]=nbs[u];nbs[u]=enm;dst[enm]=v;
	nxt[++enm]=nbs[v];nbs[v]=enm;dst[enm]=u;
}

void dp_entry(const int u, const int p){
	for(int i=nbs[u]; i; i=nxt[i]){
		int v=dst[i];
		if(v==p)continue;
		dp_entry(v, u);
	}
	/* GUARDED */
		//+EE
		f[u][1][1][m]=0;
		for(int i=nbs[u]; i; i=nxt[i]){
			int v=dst[i];
			if(v==p)continue;
			f[u][1][1][m]+=f[v][0][0][m];
		}
		//1EE
		for(int k=m-1; k>=0; k--){
			updmin(f[u][1][1][k], f[u][1][1][k+1]);
			//0AGENT
			int buf=0, bst=INF;
			for(int i=nbs[u]; i; i=nxt[i]){
				int v=dst[i];
				if(v==p)continue;
				updmin(bst, f[v][1][1][k+1]-f[v][0][0][k]);
				buf+=f[v][0][0][k];
			}
			updmin(f[u][1][1][k], buf+bst);
			if(k==1){
				//+AGENT
				buf=0; bst=INF;
				for(int i=nbs[u]; i; i=nxt[i]){
					int v=dst[i];
					if(v==p)continue;
					updmin(bst, f[v][0][1][1]-f[v][0][0][1]);
					buf+=f[v][0][0][1];
				}
				updmin(f[u][1][1][1], buf+bst+1);
			}else if(k==0){
				int x_fir, x_sec;
				int y_fir, y_sec;
				x_fir=x_sec=y_fir=y_sec=-1;
				buf=0;
				for(int i=nbs[u]; i; i=nxt[i]){
					int v=dst[i];
					if(v==p)continue;
					buf+=f[v][1][0][0];
					if(x_fir<0 || f[x_fir][1][1][0]-f[x_fir][1][0][0]>=f[v][1][1][0]-f[v][1][0][0]){
						x_sec=x_fir; x_fir=v;
					}else if(x_sec<0 || f[x_sec][1][1][0]-f[x_sec][1][0][0]>f[v][1][1][0]-f[v][1][0][0]){
						x_sec=v;
					}
					if(y_fir<0 || f[y_fir][1][0][1]-f[y_fir][1][0][0]>=f[v][1][0][1]-f[v][1][0][0]){
						y_sec=y_fir; y_fir=v;
					}else if(y_sec<0 || f[y_sec][1][0][1]-f[y_sec][1][0][0]>f[v][1][0][1]-f[v][1][0][0]){
						y_sec=v;
					}
				}
				if(!~x_fir && !~y_fir){
					if(x_fir!=y_fir){
						updmin(f[u][1][1][0], buf+f[x_fir][1][1][0]-f[x_fir][1][0][0]+f[y_fir][1][0][1]-f[y_fir][1][0][0]);
					}else{
						if(!~x_sec){
							updmin(f[u][1][1][0], buf+f[x_sec][1][1][0]-f[x_sec][1][0][0]+f[y_fir][1][0][1]-f[y_fir][1][0][0]);
						}
						if(!~y_sec){
							updmin(f[u][1][1][0], buf+f[x_fir][1][1][0]-f[x_fir][1][0][0]+f[y_sec][1][0][1]-f[y_sec][1][0][0]);
						}
					}
				}
			}
		}
		updmin(f[u][0][1][0], f[u][1][1][0]);
		//0EE
		//+AGENT
		int buf=0, bst=INF;
		for(int i=nbs[u]; i; i=nxt[i]){
			int v=dst[i];
			if(v==p)continue;
			buf+=f[v][0][0][1];
		}
		updmin(f[u][1][0][1], buf+1);
		//0AGENT
		updmin(f[u][1][0][0], f[u][1][0][1]);
		buf=0; bst=INF;
		for(int i=nbs[u]; i; i=nxt[i]){
			int v=dst[i];
			if(v==p)continue;
			updmin(bst, f[v][1][0][1]-f[v][1][0][0]);
			buf+=f[v][1][0][0];
		}
		updmin(f[u][1][0][0], buf+bst);
		updmin(f[u][0][0][0], f[u][1][0][0]);
	/* DANGER */
		//1EE
		for(int k=1; k<=m; k++){
			updmin(f[u][0][1][k], f[u][0][1][k-1]);
			//0AGENT
			int buf=0, bst=INF;
			for(int i=nbs[u]; i; i=nxt[i]){
				int v=dst[i];
				if(v==p)continue;
				updmin(bst, f[v][0][1][k-1]-f[v][0][0][k-1]);
				buf+=f[v][0][0][k-1];
			}
			updmin(f[u][0][1][k], buf+bst);
		}
		//0EE
		for(int k=1; k<=m; k++){
			//0AGENT
			updmin(f[u][0][0][k], f[u][0][0][k-1]);
			int buf=0;
			for(int i=nbs[u]; i; i=nxt[i]){
				int v=dst[i];
				if(v==p)continue;
				buf+=f[v][0][0][k-1];
			}
			updmin(f[u][0][0][k], buf);
		}
}

int main(){
	int T;scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &m);
		memset(nbs, 0, sizeof(nbs));enm=0;
		for(int i=1; i<n; i++){
			int u, v;
			scanf("%d%d", &u, &v);
			u--;v--;
			add_edge(u, v);
		}
		for(int w=0; w<n; w++){
			for(int x=0; x<B; x++){
				for(int y=0; y<B; y++){
					for(int z=0; z<=m; z++){
						f[w][x][y][z]=INF;
					}
				}
			}
		}
		dp_entry(0, -1);
		ans=f[0][1][1][0];
		printf("%d\n", ans);
	}
	return 0;
}
