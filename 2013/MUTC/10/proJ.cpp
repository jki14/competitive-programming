#pragma comment(linker, "/STACK:16777216")

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define N 110000
#define M 210000

typedef long long lld;

int n,nbs[N],nxt[M],dst[M],eid;
int mrk[N],que[N],top;
lld f[N],g[N],s[N],ans;

void addEdge(const int &u, const int &v){
	nxt[++eid]=nbs[u];nbs[u]=eid;dst[eid]=v;
	nxt[++eid]=nbs[v];nbs[v]=eid;dst[eid]=u;
}

void getQue(const int &u){mrk[u]=1;
	for(int i=nbs[u];i;i=nxt[i]){int v=dst[i];
		if(mrk[v])continue;
		getQue(v);
	}
	que[top++]=u;
}

int main(){
	ios::sync_with_stdio(false);
	while(cin>>n){ans=0LL;
		memset(nbs,0,sizeof(nbs));eid=0;
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			addEdge(u,v);
		}
		memset(mrk,0,sizeof(mrk));top=0;
		getQue(1);
		for(int _i=0;_i<n;_i++){int u=que[_i];
			lld cnt=g[u]=f[u]=s[u]=0LL;mrk[u]=2;
			for(int i=nbs[u];i;i=nxt[i]){int v=dst[i];
				if(mrk[v]!=2)continue;
				s[u]+=s[v];
			}
			for(int i=nbs[u];i;i=nxt[i]){int v=dst[i];
				if(mrk[v]!=2)continue;
				f[u]+=cnt*s[v];
				g[u]+=cnt*s[v]*(s[u]-cnt-s[v]);
				cnt+=s[v];
			}s[u]++;
			//printf("%d:f=%lld g=%lld s=%lld\n",u,f[u],g[u],s[u]);
		}
		for(int u=1;u<=n;u++)ans+=f[u]*(((lld)n)-s[u])+g[u];
		cout<<ans<<endl;
	}
	return 0;
}
