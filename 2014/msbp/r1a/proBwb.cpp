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

#define N 100010
#define S 1000010

typedef long long L;

const L MOD=1000000007LL;
const L MAGIC=12347LL;

int n,m,q;
int u[N],l[N],r[N],id[N];
lld ans,a[N],c[S],d[N];
int mrk[N],lev[N];

vector<int> son[N],opt[N];

void modify(const int &i, const int &l, const int &r, const int &u, const int &v, const lld &d){
	if(v<l || u>r)return;
	if(u<=l && r<=v){
		c[i]=(c[i]+d)%mod;
	}else{
		int mid=(l+r)>>1;
		modify(L,l,  mid,u,v,d);
		modify(R,mid+1,r,u,v,d);
	}
}

lld query(const int &i,const int &l,const int &r,const int &p){
	if(p<l || p>r)return 0LL;
	lld ret=c[i];
	if(l!=r){
		int mid=(l+r)>>1;
		ret=(ret+query(L,l,  mid,p))%mod;
		ret=(ret+query(R,mid+1,r,p))%mod;
	}
	return ret;
}

void mark(const int &u){
	if(mrk[u])return;mrk[u]=1;
	a[u]=query(0,1,m,lev[u]);
	for(int i=0;i<_size(son[u]);i++){int v=son[u][i];
		mark(v);
	}
}

void core(const int &x){
	for(int i=0;i<_size(opt[x]);i++){int k=opt[x][i];
		modify(0,1,m,l[k],r[k],d[k]);
	}
	for(int i=0;i<_size(son[x]);i++){int v=son[x][i];
		core(v);
	}
	mark(x);
	for(int i=0;i<_size(opt[x]);i++){int k=opt[x][i];
		modify(0,1,m,l[k],r[k],-d[k]);
	}
}

int main(){
	int T;cin>>T;
	for(int caseNum=1;caseNum<=T;caseNum++){
		cin>>n;
		memset(nbs,0,sizeof(nbs));enm=0;	
		for(int i=2;i<=n;i++){ 
			int u,v=i;cin>>u;
			addEdge(u,v);
		}
		cin>>q;
		for(int i=1;i<=n;i++){ castVct[i].clear(); }
		for(int i=0;i<q;i++){
			cast newCast;
			cin>>newCast.u>>newCast.l>>newCast.r>>newCast.w;
			castVct[i].push_back(newCast);
		}

		memset(val,0,sizeof(val));
		memset(res,0,sizeof(res));
		memset(vst,0,sizeof(vst));

		core(1);
		mark(1);ans=0LL;
		for(int i=1;i<=n;i++){
			//printf("A[%d]=%lld\n",i,(query(0,1,m,lev[i]))%mod);
			ans=(ans*msk+a[i])%mod;
		}
		ans=(ans%MOD+MOD)%MOD;
		cout<<"Case "<<caseNum<<": "<<ans<<endl;
	}
	return 0;
}

