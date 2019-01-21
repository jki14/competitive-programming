#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
#include<map>
using namespace std;

#define maxv 1100
#define maxe 1100

typedef pair<int,int> pii;

map<pii,int> gmap;
map<pii,int>::iterator it;

const int inf=0x3fffffff;

int ec[maxe],ef[maxe],eu[maxe],ev[maxe],next[maxe],be[maxe];
int mk[maxv],nbs[maxv],dis[maxv],gap[maxv],flow,lmt,stop,vex,num;

int min(int x,int y){ return (x<y)?x:y; }

void AddEdge(int u,int v,int cc){
	it=gmap.find(pii(u,v));if(it==gmap.end()){
		next[++num]=nbs[u];nbs[u]=num;be[num]=num+1;
		eu[num]=u;ev[num]=v;ec[num]=cc;ef[num]=0;
		next[++num]=nbs[v];nbs[v]=num;be[num]=num-1;
		eu[num]=v;ev[num]=u;ec[num]=0;ef[num]=0;
		gmap.insert(pair<pii,int>(pii(u,v),num-1));
		gmap.insert(pair<pii,int>(pii(v,u),num));
		if(!mk[u]){ mk[u]=1;vex++; }
		if(!mk[v]){ mk[v]=1;vex++; }
	}else ec[(*it).second]+=cc;
}

void getflow(int u,int s,int t)
{
	if(u==t){ stop=1;flow+=lmt;return; }
	int mind=vex-1,oldlmt=lmt,i,v;
	for(i=nbs[u];i;i=next[i]){v=ev[i];
		if(ec[i]-ef[i]){
			if(dis[u]==dis[v]+1){
				lmt=min(lmt,ec[i]-ef[i]);getflow(v,s,t);
				if(dis[s]>=vex)return;if(stop)break;
				lmt=oldlmt;
			}
			mind=min(mind,dis[v]);
		}
	}
	if(stop){ ef[i]+=lmt;ef[be[i]]-=lmt; }
	else{
		gap[dis[u]]--;
		if(gap[dis[u]]==0)dis[s]=vex;
		dis[u]=mind+1;gap[dis[u]]++;
	}
}

int sap(int s,int t){
	memset(dis,0,sizeof(dis));memset(gap,0,sizeof(gap));
	flow=0;gap[0]=num;
	while(dis[s]<vex){
		lmt=inf;stop=0;getflow(s,s,t);
	}
	return flow;
}

void test(){
	memset(nbs,0,sizeof(nbs));memset(mk,0,sizeof(mk));
	num=0;vex=0;gmap.clear();
	AddEdge(0,1,3);
	AddEdge(0,2,4);
	AddEdge(1,2,1);
	AddEdge(1,4,1);
	AddEdge(2,4,5);
	cout<<" Start!"<<endl;
	cout<<" SAP="<<sap(0,4)<<endl;
}

void bsoj2132(){
	int n,m,u,v,c;
	scanf("%d%d",&m,&n);
	while(m--){
		scanf("%d%d%d",&u,&v,&c);
		AddEdge(u,v,c);
	}
	printf("%d\n",sap(1,n));
}

int main(){
	//test();
	bsoj2132();
	return 0;
}
