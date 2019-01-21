#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

#define N 110000
#define M 110000

typedef long long lld;

int n,m,k,f[N],rnk[N];
int src[M],dst[M],wht[M],id[M];
lld ans;

inline int find(const int &u){ if(f[u]!=u)f[u]=find(f[u]);return f[u]; }

inline int cmp(const int &i,const int &j){ return wht[i]>wht[j]; }

int main(){
	int T;scanf("%d",&T);
	for(int _T=1;_T<=T;_T++){
		scanf("%d%d",&n,&k);m=n-1;ans=0;
		for(int i=0;i<m;i++){ scanf("%d%d%d",&src[i],&dst[i],&wht[i]);id[i]=i; }
		memset(rnk,0xff,sizeof(rnk));
		for(int i=0;i<k;i++){ int p;scanf("%d",&p);rnk[p]=i; }
		
		sort(id,id+m,cmp);for(int i=0;i<n;i++)f[i]=i;
		for(int _i=0;_i<m;_i++){int i=id[_i];
			int u=find(src[i]),v=find(dst[i]);
			if(u!=v && rnk[u]>=0 && rnk[v]>=0){
				ans+=(lld)wht[i];
			}else{
				if(rnk[u]>=0)f[v]=u;else f[u]=v;
			}
		}
		printf("%I64d\n",ans);
	}
}
