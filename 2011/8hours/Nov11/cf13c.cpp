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

#define N 5100
#define K 2

#define pre now^1

typedef long long lld;

const lld inf = 1LL<<60;

set<lld> s;
set<lld>::iterator it;

lld a[N],b[N],ans;
int n,num,now=0,hig[N];
lld f[K][N];

inline lld mymin(const lld &x,const lld &y){ return (x<y)?x:y; }

inline lld myabs(const lld &x){ return x>0LL?x:-x; }

void work(){
	s.clear();num=0;ans=inf;
	for(int i=1;i<=n;i++){
		scanf("%I64d",&a[i]);
		s.insert(a[i]);
	}
	for(it=s.begin();it!=s.end();it++)b[num++]=(*it);
	//for(int i=0;i<=n;i++)for(int j=0;j<num;j++)f[i][j] = i>0 ? inf:0LL;
	for(int j=0;j<num;j++)f[now][j]=0LL;
	for(int i=1;i<=n;i++){now=pre;
		lld best=inf;
		for(int j=0;j<num;j++){
			best=mymin(best,f[pre][j]);
			f[now][j]=myabs(b[j]-a[i])+best;
		}
	}
	for(int j=0;j<num;j++)ans=mymin(ans,f[now][j]);
	printf("%I64d\n",ans);
}

int main(){
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}

