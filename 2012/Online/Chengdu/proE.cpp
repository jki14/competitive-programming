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

#define N 1000
#define M 1100000

template<typename T>
inline T mymin(const T &x,const T &y){ return x<y?x:y; }

const int inf=0x3fffffff;

const int S=0;
const int T=2900;

int n,m;
int ec[M],ef[M],eu[M],ev[M],be[M],next[M],num;
int nbs[N],cur[N],dis[N],sud[N],pre[N];

void AddEdge(const int &u,const int &v,const int &cc){
	next[++num]=nbs[u];nbs[u]=num;be[num]=num+1;
	eu[num]=u;ev[num]=v;ec[num]=cc;ef[num]=0;
	next[++num]=nbs[v];nbs[v]=num;be[num]=num-1;
	eu[num]=v;ev[num]=u;ec[num]=0;ef[num]=0;
}

int SAP(const int &s,const int &t,const int &n){
	memset(sud,0,sizeof(sud));
	memset(cur,0xff,sizeof(cur));
	memset(dis,0,sizeof(dis));
	sud[0]=n; pre[s]=s;
	int res=0, now=s, mod=inf;
	while(dis[s]<n){
		int flag = 0;
		if(now == s)mod=inf;
		if(cur[now]<0)cur[now]=nbs[now];
		for(int &i=cur[now];i;i=next[i]){int v=ev[i];
			if(i<be[i] && dis[now]==dis[v]+1 && ef[i]<ec[i]){
				flag=1; pre[v]=now; now=v;
				mod=mymin(mod,ec[i]-ef[i]);
				break;
			}
			if(i>be[i] && dis[now]==dis[v]+1 && ef[i]>0){
				flag=1; pre[v]=now; now=v;
				mod=mymin(mod,ef[i]);
				break;
			}
		}
		if(now==t){
			res+=mod;
			while(now !=s){
				now=pre[now];
				if(cur[now]<be[cur[now]]){
					ef[cur[now]]+=mod;ef[be[cur[now]]]+=mod;
				}else{
					ef[cur[now]]-=mod;ef[be[cur[now]]]-=mod;
				}
			}
		}
		if(flag)continue;
		cur[now]=-1;
		int mnd=n;
		for(int i=nbs[now];i;i=next[i]){int v=ev[i];
			if(i<be[i] && dis[v]<mnd && ef[i]<ec[i])mnd=dis[v];
			if(i>be[i] && dis[v]<mnd && ef[i]>0)mnd=dis[v];
		}
		sud[dis[now]]--;
		if(sud[dis[now]]==0)dis[s]=n;
		sud[dis[now]=mnd+1]++;
		now=pre[now];
	}
	return res;
}

#define src 801
#define des 802

#define food(x) (x+0)
#define peo0(x) (x+200)
#define peo1(x) (x+400)
#define drin(x) (x+600)

#define S 802
#define L 300

char sat[L];

int main(){int n,f,d;
	while(scanf("%d%d%d",&n,&f,&d)!=EOF){
		

		memset(nbs,0,sizeof(nbs));num=0;	

		for(int i=1;i<=n;i++)AddEdge(peo0(i),peo1(i),1);

		for(int i=1;i<=f;i++){
			int val;scanf("%d",&val);
			AddEdge(src,food(i),val);
		}	
		for(int i=1;i<=d;i++){
			int val;scanf("%d",&val);
			AddEdge(drin(i),des,val);
		}

		for(int i=1;i<=n;i++){
			scanf("%s",sat);
			for(int j=1;j<=f;j++)
				if(sat[j-1]=='Y')AddEdge(food(j),peo0(i),1);
		}
		
		for(int i=1;i<=n;i++){
			scanf("%s",sat);
			for(int j=1;j<=d;j++)
				if(sat[j-1]=='Y')AddEdge(peo1(i),drin(j),1);
		}

		printf("%d\n",SAP(src,des,S));
	}

	return 0;
}

