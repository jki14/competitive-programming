#pragma GCC optimize(2)

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
typedef long long lld;

inline lld _euc(const lld &a,const lld &b,lld &x,lld &y){ 
	if(a<0LL){lld d=_euc(-a,b,x,y);x=-x;return d;} 
	if(b<0LL){lld d=_euc(a,-b,x,y);y=-y;return d;} 
	if(b==0LL){
		x=1LL;y=0LL;return a;
	}else{
		lld d=_euc(b,a%b,x,y);lld t=x;x=y;y=t-(a/b)*y;
		return d;
	}
}	

inline lld _inv(const lld &a,const lld &b){
	lld x,y;_euc(a,b,x,y);
	if(x==0LL)x=1LL;return x;
}


const lld mod=1000000007LL;
	
inline lld _cmd(const lld &x){ return (x%mod+mod)%mod; }
inline lld _amd(const lld &x,const lld &y){ return (x+y)%mod; }
inline lld _mmd(const lld &x,const lld &y){ return x*y%mod; }

int n,nbs[N],nxt[M],dst[M],enm,T;
int s[N],pnt[N],mrk[N],que[N],top;
lld p[N],f[N],g[N],ans;

void addEdge(const int &u, const int &v){ 
	nxt[++enm]=nbs[u];nbs[u]=enm;dst[enm]=v;
	nxt[++enm]=nbs[v];nbs[v]=enm;dst[enm]=u;
}

void getQue(const int &u, const int &f){
	pnt[u]=f;mrk[u]=T;
	for(int i=nbs[u];i;i=nxt[i]){int v=dst[i];
		if(mrk[v]==T)continue;
		getQue(v,u);
	}
	que[top++]=u;
}

int main(){
	//ios::sync_with_stdio(false);
	p[0]=1LL;for(int i=1;i<N;i++)p[i]=_mmd(p[i-1],((lld)i));
	memset(mrk,0,sizeof(mrk));
	scanf("%d",&T);
	for(;T;T--){
		//cin>>n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)nbs[i]=0;enm=0;
		//memset(nbs,0,sizeof(nbs));enm=0;
		for(int i=1;i<n;i++){
			int u,v;//cin>>u>>v;
			scanf("%d%d",&u,&v);
			addEdge(--u,--v);
		}
		top=0;getQue(0,-1);ans=0LL;
		for(int _i=0;_i<n;_i++){int u=que[_i];
			s[u]=0;for(int i=nbs[u];i;i=nxt[i]){int v=dst[i];
				if(v==pnt[u])continue; 
				s[u]+=s[v];
			}
			f[u]=p[s[u]++];
			for(int i=nbs[u];i;i=nxt[i]){int v=dst[i];
				if(v==pnt[u])continue;
				f[u]=_mmd(f[u],_inv(p[s[v]],mod));
				f[u]=_mmd(f[u],f[v]);
			}
			//cout<<"f["<<u<<"]="<<f[u]<<endl;
		}
		for(int _i=n-1;_i>=0;_i--){int u=que[_i];
			if(pnt[u]==-1){
				g[u]=f[u];
			}else{
				lld sol=p[n-1];
				lld anc=g[pnt[u]];
				lld det=_mmd(p[n-1],_inv(p[n-s[u]-1],mod));
				anc=_mmd(anc,p[s[u]]);
				anc=_mmd(anc,_inv(det,mod));
				anc=_mmd(anc,_inv(f[u],mod));
				//cout<<u<<":anc("<<pnt[u]<<")="<<anc<<endl;
				sol=_mmd(sol,_inv(p[n-s[u]],mod));
				sol=_mmd(sol,anc);
				for(int i=nbs[u];i;i=nxt[i]){int v=dst[i];
					if(v==pnt[u])continue;
					sol=_mmd(sol,_inv(p[s[v]],mod));
					sol=_mmd(sol,f[v]);
				}
				g[u]=sol;
			}
			//cout<<"g["<<u<<"]="<<g[u]<<endl;
			ans=_amd(ans,_mmd(g[u],g[u]));
		}
		//cout<<_cmd(ans)<<endl;
		printf("%d\n",(int)(_cmd(ans)));
	}	
	return 0;
}

