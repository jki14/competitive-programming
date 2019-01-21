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
#define N 1100
//#define E 310000

const int inf=0x3fffffff;

//int pri;

int vex,edg,n,m,sum;
int a[V],ret;

/*int rec[E],ref[E],rew[E],reu[E],rev[E],rnext[E],rbe[E];*/
//int rnbs[V],rnum;

/*int ec[E],ef[E],ew[E],eu[E],ev[E],next[E],be[E];
int dis[V],nbs[V],vis[V],num,flow,cost;*/

int mat[N][N],cost[N][N],flow[N][N];
int netcost,source,sink,nodes;

int pre[N],cha[N],d[N];

vector<int> path;

/*void clr(){ memset(vis,0,sizeof(vis));path.clear(); }

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
}*/

int mincostMaxFlow(){
	int i,j,t,tag;
	if(source==sink)return inf;
	memset(flow,0,sizeof(flow));
	for(netcost=0;;){
		for(i=0;i<nodes;i++){
			pre[i]=0;
			cha[i]=inf;
		}
		pre[source]=source+1;
		cha[source]=0;
		d[source]=inf;
		for(tag=1;tag;){
			for(tag=t=0;t<nodes;t++){
				if(d[t]){
					for(i=0;i<nodes;i++){
						if((j=mat[t][i]-flow[t][i]) && cha[t]+cost[t][i]<cha[i]){
						tag=1;
						cha[i]=cha[t]+cost[t][i];
						pre[i]=t+1;
						d[i]=min(d[t],j);
						}else if((j=flow[i][t]) && cha[t]<inf && cha[t]-cost[i][t]<cha[i]){
							tag=1;
							cha[i]=cha[t]-cost[i][t];
							pre[i]=-t-1;
							d[i]=min(d[t],j);
						}
					}
				}
			}
		}
		if(!pre[sink])break;
		for(netcost+=cha[sink]*d[i=sink];i!=source;){
			if(pre[i]>0){
				flow[pre[i]-1][i]+=d[sink];
				i=pre[i]-1;
			}else{
				flow[i][-pre[i]-1]-=d[sink];
				i=-pre[i]-1;
			}
		}
	}
	for(j=i=0;i<nodes;j+=flow[source][i++]);
	//printf("flow=%d\n",j);
	return j;	
}

int bitnum(int x){int ret=0;
	for(;x;x>>=1){ if(x&1)ret++; }
	return ret;
}

void work(){//pri=1;

	scanf("%d%d",&vex,&edg);

	memset(mat,0,sizeof(mat));
	memset(cost,0,sizeof(cost));
	sum=0;ret=inf;
	source=0;sink=(vex<<1)+1;nodes=sink+1;

	for(int i=0;i<edg;i++){
		int u,v;scanf("%d%d",&u,&v);u++;v++;
		//printf("%d->%d\n",u,v);
		mat[vex+u][v]=mat[vex+v][u]=1;
	}

	scanf("%d",&n);m=n<<1;
	for(int i=0;i<m;i++){ scanf("%d",&a[i]);a[i]++; }
	for(int i=1;i<=vex;i++){
		int val;scanf("%d",&val);
		mat[i][vex+i]=1;
		cost[i][vex+i]=val;
		cost[vex+i][i]=-val;
		sum+=val;
	}


	int K=1<<m;
	for(int k=0;k<K;k++){
		if(bitnum(k)!=n)continue;
		if((k^(K-1))<k)continue;

		for(int i=0;i<m;i++){
			if(k&(1<<i)){
				mat[source][a[i]]=1;
			}else{
				mat[vex+a[i]][sink]=1;
			}
		}
	
		/*if(k==85 && edg>0){

			printf("a[]=");
			for(int x=0;x<m;x++)printf("%d ",a[x]);
			printf("\n");

			for(int y=-1;y<nodes;y++)printf("%3d ",y);
			printf("\n");
			for(int x=0;x<nodes;x++){
				printf("%3d ",x);
				for(int y=0;y<nodes;y++)printf("%3d ",mat[x][y]);
				printf("\n");
			}
		}*/	
		//memset(flow,0,sizeof(flow));
		if(mincostMaxFlow()==n && netcost<ret)ret=netcost;
		
		for(int i=0;i<m;i++){
			if(k&(1<<i)){
				mat[source][a[i]]=0;	
			}else{
				mat[vex+a[i]][sink]=0;
			}
		}
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

