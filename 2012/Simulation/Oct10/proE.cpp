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

const int inf=0x7fffffff;

#define C 5100
#define N 2100

struct city{
	int p,r;
	bool operator < (const city &a) const{
		return p<a.p;
	}
}a[C];

int c,n,k,m,f[N],v[N],ans;
int mk[N]={ 0 },hash;

int find(int x){ if(f[x]==x)return f[x];return f[x]=find(f[x]); }

inline int min(const int &x,const int &y){ return x<y?x:y; }

int main(){
	int T;scanf("%d",&T);
	for(int caseT=1;caseT<=T;caseT++){printf("Case #%d: ",caseT);hash=caseT*C;
		scanf("%d%d%d%d",&c,&n,&k,&m);
		for(int i=1;i<=n;i++)f[i]=i;
		for(int i=0;i<c;i++)scanf("%d%d",&a[i].p,&a[i].r);
		sort(a,a+c);	//for(int i=0;i<c;i++)printf("<%d,%d>\n",a[i].p,a[i].r);
		for(int i=0;i<m;i++){
			int u,v;scanf("%d%d",&u,&v);
			f[find(u)]=find(v);
		}
		for(int i=0;i<c;i++)a[i].r=find(a[i].r);ans=inf;
		for(int i=0;i<c;i++){int now=0,des=1;

			//printf("(%d,%d)\n",a[i].p,a[i].r);

			mk[a[i].r]=++hash;
			for(int j=i+1;des<k && j<c;j++){
				if(mk[a[j].r]!=hash){
					des++;mk[a[j].r]=hash;
				}
				if((now=a[j].p-a[i].p)>ans)break;
			}
			if(des==k)ans=min(ans,now);
		}
		if(ans<inf)
			printf("%d\n",ans);
		else printf("-1\n");
	}
	return 0;
}

