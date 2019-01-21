#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;

#define maxn 1100
#define maxm 210000

const int inf=0x3fffffff;

int n,m,num,len,next[maxm],eu[maxm],ev[maxm],ew[maxm],del[maxm];
int value[maxn],mk[maxn],nbs[maxn],ps[maxn],heap[maxn];
int minval,res,_next[maxm],path[maxn];

int fec[maxm],fef[maxm],feu[maxm],fev[maxm],fbe[maxm],fnext[maxm],fnum=0;
int fnbs[maxn],fcur[maxn],fdis[maxn],fq[maxn];

vector<int> edges[maxn];

void fAddEdge(int u,int v,int cc){
	//cout<<" fAddEdge "<<u<<" --> "<<v<<"     "<<cc<<endl;
	fnext[++fnum]=fnbs[u];fnbs[u]=fnum;fbe[fnum]=fnum+1;
	feu[fnum]=u;fev[fnum]=v;fec[fnum]=cc;fef[fnum]=0;
	fnext[++fnum]=fnbs[v];fnbs[v]=fnum;fbe[fnum]=fnum-1;
	feu[fnum]=v;fev[fnum]=u;fec[fnum]=0;fef[fnum]=0;
}

int fbfs(int s,int t){
	int head,tail,u,v,i;
	head=tail=0;fq[tail++]=s;
	memset(fdis,0,sizeof(fdis));fdis[s]=1;
	while(head<tail){
		for(u=fq[head++],i=fnbs[u];i;i=fnext[i]){v=fev[i];
			//cout<<" u="<<u<<" v="<<v<<endl;
			//cout<<" fec[i]="<<fec[i]<<"  fef[i]="<<fef[i]<<endl;
			if(fec[i]-fef[i]>0 && !fdis[v]){
				fdis[v]=fdis[u]+1;fq[tail++]=v;
				//cout<<" Arrive "<<v<<endl;
				if(v==t)return 1;
			}
		}
	}
	return 0;
}

int Dinic(int s,int t){
	int flow=0,tmp,i,u,tail;
	while(fbfs(s,t)){
		//cout<<" fbfs succ"<<endl;
		u=s,tail=0;memcpy(fcur,fnbs,sizeof(fnbs));
		while(fcur[s])
			if(u!=t && fcur[u] && fec[fcur[u]]-fef[fcur[u]]>0 && fdis[u] && fdis[u]+1==fdis[fev[fcur[u]]]){
				fq[tail++]=fcur[u];u=fev[fcur[u]];
			}else if(u==t){
				for(tmp=inf,i=tail-1;i>=0;i--)tmp=min(tmp,fec[fq[i]]-fef[fq[i]]);
				//cout<<" tmp="<<tmp<<endl;
				for(flow+=tmp,i=tail-1;i>=0;i--){
					fef[fq[i]]+=tmp;
					fef[fbe[fq[i]]]-=tmp;
					if(!(fec[fq[i]]-fef[fq[i]]))tail=i;
				}
				u=feu[fq[tail]];
			}else{
				while(tail>0 && u!=s && !fcur[u])u=feu[fq[--tail]];
				fcur[u]=fnext[fcur[u]];
			}
	}
	return flow;
}

void AddEdge(int u,int v,int w){
	next[++num]=nbs[u];_next[nbs[u]]=num;
	nbs[u]=num;
	eu[num]=u;ev[num]=v;ew[num]=w;
}

void update(int r){
	int q=ps[r],p=q>>1;
	while(p && value[heap[p]]>value[r]){
		ps[heap[p]]=q;heap[q]=heap[p];
		q=p;p=q>>1;
	}
	heap[q]=r;ps[r]=q;
}

int getmin(){
	int ret=heap[1],p=1,q=2,r=heap[len--];
	while(q<=len){
		if(q<len && value[heap[q+1]]<value[heap[q]])q++;
		if(value[heap[q]]<value[r]){
			ps[heap[q]]=p;heap[p]=heap[q];
			p=q;q=p<<1;
		}else break;
	}
	heap[p]=r;ps[r]=p;
	return ret;
}

void dijkstra(int src,int dst){
	int j,u,v;
	memset(value,0x3f,sizeof(value));memset(path,0,sizeof(path));
	memset(mk,0,sizeof(mk));memset(ps,0,sizeof(ps));
	value[src]=0;heap[len=1]=src;ps[src]=1;edges[src].clear();
	while(!mk[dst]){
		if(len==0)return;
		u=getmin();mk[u]=1;
		for(j=nbs[u];j;j=next[j]){
			if(del[j])continue;
			v=ev[j];if(value[u]+ew[j]<=value[v]){
				if(value[u]+ew[j]==value[v]){
					edges[v].push_back(j);
				}else{
					if(ps[v]==0){ heap[++len]=v;ps[v]=len; }
					value[v]=value[u]+ew[j];update(v);
					edges[v].clear();edges[v].push_back(j);
				}
			}
		}
	}
}

void work(){
	memset(nbs,0,sizeof(nbs));num=0;
	memset(fnbs,0,sizeof(fnbs));fnum=0;
	memset(del,0,sizeof(del));memset(_next,0,sizeof(_next));minval=1000000000;
	int i,j,u,v,w;for(i=res=0;i<m;i++){ scanf("%d%d%d",&u,&v,&w);AddEdge(u,v,w); }
	scanf("%d%d",&u,&v);dijkstra(u,v);
	for(i=1;i<=n;i++)
		for(j=0;j<(int)edges[i].size();j++)
			fAddEdge(eu[edges[i][j]],ev[edges[i][j]],1);
	res=Dinic(u,v);
	printf("%d\n",res);
}

int main(){
	int t;scanf("%d",&t);while(t--){
		scanf("%d%d",&n,&m);work();
	}
	return 0;
}
//我草你大爷,敢不敢不要TLE!!!
