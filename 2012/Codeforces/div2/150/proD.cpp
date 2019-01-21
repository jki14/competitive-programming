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

//HEAD_OF_TEMPLATE_BY_JKI14

	//TYPEDEF
	
	typedef long long lld;
	typedef double dou;
	typedef pair<int,int> pii;

	//COMPARE
	
	inline int min(const int &x, const int &y){ return x<y?x:y; }
	inline lld min(const lld &x, const lld &y){ return x<y?x:y; }
	inline dou min(const dou &x, const dou &y){ return x<y?x:y; }

	inline int max(const int &x, const int &y){ return x>y?x:y; }
	inline lld max(const lld &x, const lld &y){ return x>y?x:y; }
	inline dou max(const dou &x, const dou &y){ return x>y?x:y; }

	template<class T> inline void _updmin(T &x,const T &y){ if(x>y)x=y; }
	template<class T> inline void _updmax(T &x,const T &y){ if(x<y)x=y; }

	//STL
	
	#define _size(x) ((int)(x.size()))
	#define _mkpa(x,y) make_pair(x,y)

	//BIT
	
	#define _ni(x) (1<<(x))
	#define _niL(x) (1LL<<(x))
	#define _has(s,x) ((s&(_ni(x)))!=0)
	#define _hasL(s,x) ((s&(_niL(x)))!=0LL)
	
	template<class T> inline T _lowbit(const int &x){ return (x^(x-1))&x; }
	template<class T> inline int _bitsize(const T &x){ return (x==0)?0:(1+bitsize(x&(x-1))); }

	//CONST VALUE
	
	const dou _pi=acos(-1.0);
	const dou _eps=1e-5;

	//CALCULATE
	
	template<class T> inline T _sqr(const T &x){ return x*x; }



//TAIL_OF_TEMPLATE_BY_JKI14

#define N 110000
#define M 1100000

int n,m,h,t;
int s[N];
int nbs[N],ev[M],next[M],num;

int mk[N],sign;
queue<int> que;

void AddEdge(const int &u,const int &v){
	ev[++num]=v;next[num]=nbs[u];nbs[u]=num;
	ev[++num]=u;next[num]=nbs[v];nbs[v]=num;
}

int find(){
	for(int u=1;u<=n;u++){
		if(s[u]<=h)continue;sign++;
		for(int i=nbs[u];i;i=next[i]){ mk[ev[i]]=sign; }
		for(int i=nbs[u];i;i=next[i]){int v=ev[i];
			if(s[v]<=t)continue;
			int cov=0,k;
			for(int j=nbs[v];j;j=next[j]){ if(mk[ev[j]]==sign)cov++; }
			cov=max(0,h-(s[u]-1-cov));
			//printf("cov=%d\n",cov);
			if(s[v]-cov<=t)continue;

			while(!que.empty())que.pop();
			for(int j=nbs[v];j;j=next[j]){ if(mk[ev[j]]==sign){ mk[ev[j]]=-sign;que.push(ev[j]); } }

			printf("YES\n");
			printf("%d %d\n",u,v);k=0;
			for(int j=nbs[u];k<h && j;j=next[j]){int p=ev[j];
				if(p==v)continue;if(mk[p]<0)continue;
				if(k)printf(" ");k++;
				printf("%d",p);
			}
			for(;k<h;que.pop()){
				if(k)printf(" ");k++;
				printf("%d",que.front());
				mk[que.front()]=sign;
			}printf("\n");k=0;
			for(int j=nbs[v];k<t;j=next[j]){int p=ev[j];
				if(p==u)continue;
				if(mk[p]==sign)continue;
				if(k)printf(" ");k++;
				printf("%d",p);
			}printf("\n");
			return 1;
		}
	}
	return 0;
}

int main(){
	while(scanf("%d%d%d%d",&n,&m,&h,&t)!=EOF){
		memset(mk,0,sizeof(mk));sign=0;
		memset(nbs,0,sizeof(nbs));num=0;
		memset(s,0,sizeof(s));
		for(int i=0;i<m;i++){
			int u,v;scanf("%d%d",&u,&v);
			AddEdge(u,v);s[u]++;s[v]++;
		}
		//h++;t++;
		if(!find())printf("NO\n");
	}	
	return 0;
}

