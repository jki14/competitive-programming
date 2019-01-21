#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;

#define N 10086

int n, m;
int d[N], f[N];
set<int> s;


inline int find(const int u){ if(f[u]!=u)f[u]=find(f[u]);return f[u]; }

int main(){
	int T;scanf("%d", &T);
	for(int _T=1; _T<=T; _T++){
		printf("Case #%d:\n", _T);
		scanf("%d%d", &n, &m);
		printf("n=%d m=%d\n" ,n ,m);
		memset(d, 0, sizeof(d));
		for(int i=0; i<n; i++)f[i]=i;
		int flag=1;s.clear();
		for(int i=1; i<n; i++){
			int u, v;
			scanf("%d%d", &u, &v);
			u--; v--;
			if(find(u)==find(v)){
				flag=0;
			}
			f[find(v)]=find(u);
			d[u]++; d[v]++;
			s.insert(u);
			s.insert(v);
		}
		if(!flag){
			printf("malformed tree.\n");
		}else{
			printf("logical tee.\n");
			printf("vertex = %d.\n", (int)s.size());
			sort(d, d+n);
			printf("d_min=%d d_max=%d d_mid=%d\n", d[0], d[n-1], d[(n+1)>>1]);
		}
	}
	return 0;
}
