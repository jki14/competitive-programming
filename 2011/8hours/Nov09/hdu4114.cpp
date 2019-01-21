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

#define N 61
#define M 3100
#define K 11
#define S 310

const int dis=0xffffffff;
const int inf=0x3fffffff;

int T;

int n,m,k,e,ans,bit[K];
int ev[M],ew[M],next[M],nbs[N],num;
int flag[N],g[N][N][S],mk[N][S];
int thepos[K],tim[K],stm[K];

int f[S][S][N],inque[S][S][N];
queue<int> quepos,quevis,questa;

void AddEdge(const int &u,const int &v,const int &w){
	++num;ev[num]=v;ew[num]=w;next[num]=nbs[u];nbs[u]=num;
	++num;ev[num]=u;ew[num]=w;next[num]=nbs[v];nbs[v]=num;
}

void clear(){
	while(!quepos.empty())quepos.pop();
	while(!questa.empty())questa.pop();
	while(!quevis.empty())quevis.pop();

}

void pushback(const int &pos,const int &sta){
	quepos.push(pos);questa.push(sta);
}

int  getfront(int &pos,int &sta){
	if(quepos.empty())return 0;
	pos=quepos.front();quepos.pop();
	sta=questa.front();questa.pop();
	return 1;
}

void pushback(const int &vis,const int &sta,const int &pos){
	quevis.push(vis);questa.push(sta);quepos.push(pos);
}

int  getfront(int &vis,int &sta,int &pos){
	if(quevis.empty())return 0;
	vis=quevis.front();quevis.pop();
	sta=questa.front();questa.pop();
	pos=quepos.front();quepos.pop();

	//printf("getfront: vis=%d sta=%d pos=%d val=%d\n",vis,sta,pos,f[vis][sta][pos]);

	return 1;
}

void spfa(const int &src){
	g[src][src][flag[src]]=0;mk[src][flag[src]]=src;
	clear();pushback(src,flag[src]);
	for(int u,sta;getfront(u,sta);){mk[u][sta]=dis;
		for(int i=nbs[u];i;i=next[i]){int v=ev[i];
			int newsta=sta|flag[v];
			if(g[src][v][newsta]>g[src][u][sta]+ew[i]){
				g[src][v][newsta]=g[src][u][sta]+ew[i];
				if(mk[v][newsta]!=src){
					pushback(v,newsta);
					mk[v][newsta]=src;
				}
			}
		}
	}
}

void work(){
	/* Init */
	scanf("%d%d%d",&n,&m,&k);e=bit[k]-1;
	memset(nbs,0,sizeof(nbs));
	for(int i=0;i<m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		AddEdge(u,v,w);
	}
	memset(flag,0,sizeof(flag));
	for(int i=0;i<k;i++){
		scanf("%d%d%d",&thepos[i],&tim[i],&stm[i]);
		int posnum;scanf("%d",&posnum);
		for(int j=0;j<posnum;j++){
			int sps;scanf("%d",&sps);
			flag[sps]|=bit[i];
			
			//printf("flag[%d]=%d\n",sps,flag[sps]);
		
		}
	}
	/* Build */
	memset(g,0x3f,sizeof(g));
	memset(mk,0xff,sizeof(mk));
	for(int i=1;i<=n;i++)spfa(i);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int state=e;state;state--)
				for(int p=0;p<k;p++)
					if(state&bit[p])g[i][j][state^bit[p]]=min(g[i][j][state^bit[p]],g[i][j][state]);


	/*for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int state=0;state<=e;state++)
				printf("g[%d][%d][%d]=%d\n",i,j,state,g[i][j][state]);*/

	//printf("Build Successed\n");

	/* Core */
	memset(f,0x3f,sizeof(f));clear();

	//printf("f[0][0][0]=%d\n",f[0][0][0]);

	memset(inque,0,sizeof(inque));
	for(int i=0;i<k;i++)
		for(int sta=0;sta<=e;sta++){
			f[bit[i]][sta&(~bit[i])][thepos[i]]=min(f[bit[i]][sta&(~bit[i])][thepos[i]],g[1][thepos[i]][sta]+((sta&bit[i])?stm[i]:tim[i]));

			/*printf("g[%d][%d][%d]=%d ",1,thepos[i],sta,g[1][thepos[i]][sta]);
			printf("stm[i]=%d tim[i]=%d\n",stm[i],tim[i]);
			printf("	path=%d f[%d][%d][%d]=%d\n",g[1][thepos[i]][sta]+((sta&bit[i])?stm[i]:tim[i]),bit[i],sta&(~bit[i]),thepos[i],f[bit[i]][sta&(~bit[i])][thepos[i]]);*/

			if(!inque[bit[i]][sta&(~bit[i])][thepos[i]]){
				pushback(bit[i],sta&(~bit[i]),thepos[i]);
				inque[bit[i]][sta&(~bit[i])][thepos[i]]=1;
			}
		}
	for(int vis,sta,pos;getfront(vis,sta,pos);){
		for(int newsta=0;newsta<=e;newsta++){
			if((sta&newsta)!=sta)continue;
			if(newsta&vis)continue;
			for(int i=0;i<k;i++){
				if(vis&bit[i])continue;
				int newvis=vis|bit[i];
				int newpos=thepos[i];
				int cost=f[vis][sta][pos]+g[pos][newpos][newsta^sta]+((newsta&bit[i])?stm[i]:tim[i]);	
				if(f[newvis][newsta&(~bit[i])][newpos]>cost){
					f[newvis][newsta&(~bit[i])][newpos]=cost;
					if(!inque[newvis][newsta&(~bit[i])][newpos]){
						pushback(newvis,newsta&(~bit[i]),newpos);
						inque[newvis][newsta&(~bit[i])][newpos]=1;
					}
				}
			}
		}
	}
	/* Output */
	ans=inf;
	for(int i=0;i<k;i++)
		ans=min(ans,f[e][0][thepos[i]]+g[thepos[i]][1][0]);
	printf("Case #%d: %d\n",T,ans);
}

int main(){
	for(int i=0;i<K;i++)bit[i]=1<<i;
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++)work();
	return 0;
}

