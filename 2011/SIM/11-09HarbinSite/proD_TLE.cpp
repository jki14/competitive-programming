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

#define V 1100
#define E 310000

/*#define su u
 #define eu u<<1
 #define sv v
 #define ev v<<1*/

#define src 0
#define tar 1009 

const int inf=0x3fffffff;

//int pri;

int vex,edg,n,m,sum;
int a[V],ret;

/*int rec[E],ref[E],rew[E],reu[E],rev[E],rnext[E],rbe[E];*/
int rnbs[V],rnum;

int ec[E],ef[E],ew[E],eu[E],ev[E],next[E],be[E];
int dis[V],nbs[V],vis[V],num,flow,cost;

vector<int> path;

void clr(){ memset(vis,0,sizeof(vis));path.clear(); }

void AddEdge(const int &u,const int &v,const int &cc,const int &ww){
	//if(pri)printf("%d->%d C%d W%d\n",u,v,cc,ww);
	next[++num]=nbs[u];nbs[u]=num;be[num]=num+1;
	eu[num]=u;ev[num]=v;ec[num]=cc;ef[num]=0;ew[num]=ww;
	next[++num]=nbs[v];nbs[v]=num;be[num]=num-1;
	eu[num]=v;ev[num]=u;ec[num]=0;ef[num]=0;ew[num]=-ww;
}

void copyG(){
	memcpy(rnbs,nbs,sizeof(nbs));
	rnum=num;
}

void paseG(){
	memcpy(nbs,rnbs,sizeof(rnbs));
	num=rnum;
}

int getflow(const int &u,const int &s,const int &t,const int &k){
	if(u==t){ cost+=k*dis[s];flow+=k;return k; }vis[u]=1;path.push_back(u);
	int minflow,v;for(int i=nbs[u];i;i=next[i]){v=ev[i];
		if(ec[i]-ef[i] && !vis[v] && ew[i]+dis[v]==dis[u]){
			minflow=min(k,ec[i]-ef[i]);
			if(int d=getflow(v,s,t,minflow)){
				ef[i]+=d;ef[be[i]]-=d;
				return d;
			}
		}
	}
	return 0;
}

int renumber(){
	int adds=inf,i,u,v;
	for(i=1;i<=num;i++)if(vis[u=eu[i]] && ec[i]-ef[i] && !vis[v=ev[i]])
		adds=min(adds,dis[v]-dis[u]+ew[i]);
	if(adds==inf)return 0;
	for(i=0;i<(int)path.size();i++)dis[path[i]]+=adds;
	return 1;
}

void mcflow(const int &s,const int &t){
	cost=flow=0;memset(dis,0,sizeof(dis));
	for(clr();getflow(s,s,t,inf)||renumber();clr());
}

int bitnum(int x){int ret=0;
	for(;x;x>>=1){ if(x&1)ret++; }
	return ret;
}

void work(){//pri=1;

	scanf("%d%d",&vex,&edg);

	memset(nbs,0,sizeof(nbs));num=0;
	sum=0;ret=inf;

	for(int i=0;i<edg;i++){
		int u,v;scanf("%d%d",&u,&v);u++;v++;
		AddEdge(vex+u,v,1,0);
		AddEdge(vex+v,u,1,0);
	}

	scanf("%d",&n);m=n<<1;
	for(int i=0;i<m;i++){ scanf("%d",&a[i]);a[i]++; }
	for(int i=1;i<=vex;i++){
		int val;scanf("%d",&val);
		AddEdge(i,vex+i,1,val);
		sum+=val;
	}

	copyG();
	int K=1<<m;
	for(int k=0;k<K;k++){
		if(bitnum(k)!=n)continue;
		if((k^(K-1))<k)continue;

		//if(k==27)pri=1;else pri=0;

		paseG();
		for(int i=0;i<m;i++){
			if(k&(1<<i))
				AddEdge(src,a[i],1,0);
			else
				AddEdge(vex+a[i],tar,1,0);
		}
		
		memset(ef,0,sizeof(ef));
		mcflow(src,tar);//break;

		//printf("k=%d flow=%d cost=%d\n",k,flow,cost);

		if(flow==n && cost<ret)ret=cost;
	}

	if(ret==inf)
		printf("-1\n");
	else
		printf("%d\n",sum-ret);

}

int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}

