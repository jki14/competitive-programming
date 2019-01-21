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

#define N 210000
#define S 410000

typedef long long lld;

int n,m,s,f[S];
int eu[N],ev[N],id[N];
lld ec[N],g[S],c[S],ans;

int cmp(const int &i,const int &j){ return ec[i]>ec[j]; }

int find(const int &x){
	if(x==f[x])return x;
	int old=f[x];
	f[x]=find(f[x]);
	g[x]+=g[old];
	return f[x];
}

int main(){
	while(scanf("%d",&n)!=EOF){m=n-1;s=n+n;
		for(int i=0;i<m;i++){
			scanf("%d%d%lld",&eu[i],&ev[i],&ec[i]);
			id[i]=i;
		}
		sort(id,id+m,cmp);
		for(int i=0;i<s;i++){
			f[i]=i;
			c[i]=1LL;
			g[i]=0LL;
		}
		for(int p=0;p<m;p++){int i=id[p];

			//printf("~%lld\n",ec[i]);

			int u=find(eu[i]),v=find(ev[i]);
			int tar=n+i+1;f[u]=f[v]=tar;c[tar]=c[u]+c[v];
			g[u]=c[v]*ec[i];g[v]=c[u]*ec[i];
		}
		ans=0LL;for(int i=1;i<=n;i++){
			find(i);ans=max(ans,g[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
