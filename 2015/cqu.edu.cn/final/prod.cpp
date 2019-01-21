#include <cstdio>
#include <algorithm>
using namespace std;

#define N 11000

int n, m, t[N], id[N];
double w[N], ans, buf;

template<class T> inline T MIN(const T x, const T y){ return (x<y)?x:y; }

inline int cmp(const int x, const int y){ return (t[x]!=t[y])?t[x]<t[y]:w[x]>w[y]; }

int main(){
	int T;scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &m);
		n=MIN(n, m);
		for(int i=0; i<m; i++){
			scanf("%lf%d", &w[i], &t[i]);
			if(t[i])w[i]*=0.8;
			id[i]=i;
		}
		sort(id, id+m, cmp);
		ans=0.0;
		for(int i=0; i<n-1; i++){
			int k=id[i];
			if(!t[k]){
				ans+=w[k]*0.5;
			}else ans+=w[k];
		}
		buf=1024.0;
		if(t[id[n-1]])buf=0.0;
		for(int i=n-1; i<m; i++){
			int k=id[i];
			buf=MIN(buf, w[k]);
			ans+=w[k];
		}
		ans-=buf*0.5;
		printf("%.2f\n", ans);
	}
	return 0;
}
