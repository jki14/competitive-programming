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
#include<deque>
#include<set>
#include<map>
using namespace std;

#define N 110000

typedef long long lld;

const lld inf=LONG_MAX;

lld ans,a[N];
lld path,outp,sum,len;
int n,f[N],g[N],v[N];

int cmp(const int &i,const int &j){ return a[i]<a[j]; }

void work(){
	outp=inf;
	for(int i=0;i<n;i++){g[i]=i;
		scanf("%lld",&a[i]);
		outp=min(outp,a[i]);
	}
	sort(g,g+n,cmp);for(int i=0;i<n;i++)f[g[i]]=i;
	memset(v,0,sizeof(v));ans=0LL;

	for(int i=0;i<n;i++)if(!v[i]){
		if(f[i]==i)continue;
		sum=len=0LL;path=inf;
		for(int j=i;!v[j];j=f[j]){v[j]=1;
			sum+=a[j];path=min(path,a[j]);len++;
		}
		ans+=min(sum+path*(len-2LL),sum+outp*(len+1LL)+path);
	}

	printf("%lld\n",ans);
}

int main(){
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}

