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

#define N 110
#define C 28
#define M 110000
#define P 4
#define L 1100
#define S 110000

#define src 26
#define res 27

#define tran(x,y) (x*1000+y)
#define mark(i) (cor[i].x*1000+cor[i].y)

const int dx[P]= { 0,-1,0,1 };	
const int dy[P]= { 1,0,-1,0 };

#define ii (i+dx[p])
#define jj (j+dy[p])

struct TPos{
	int x,y;
}now,tai,cor[C];

int n,m,k,v;
char c[N][N];
int d[C][S],f[C][S],w[C][S],vis[C];
int ev[M],ew[M],next[M],nbs[S],num;

char con[L];

queue<int> que;int inq[S];

int lis[S],rig;

void addEdge(const int &u,const int &v,const int &w){

	//printf("%d %d  --->  %d %d          %d\n",u/100,u%100,v/100,v%100,w);

	ev[++num]=v;ew[num]=w;next[num]=nbs[u];nbs[u]=num;
}

void spfa(const int &x){


	//printf("SPFA(%d)\n",x);

	int u=mark(x);
	while(!que.empty())que.pop();
	memset(inq,0,sizeof(inq));
	que.push(u);inq[u]=1;d[x][u]=0;f[x][u]=u;w[x][u]=0;
	for(;!que.empty();que.pop()){
		int u=que.front();

		//printf("	u=%d\n",u);

		for(int i=nbs[u];i;i=next[i]){int v=ev[i];

			//printf("		i=%d next[i]=%d\n",i,next[i]);

			if(!inq[v]){
				d[x][v]=d[x][u]+ew[i];f[x][v]=u;w[x][v]=ew[i];
				/*if(!inq[v]){
					inq[v]=1;que.push(v);
				}else while(1);*/
				que.push(v);inq[v]=1;
			}
		}
		//inq[u]=0;
	}

	//printf("DONE\n");

}

void find(const int &x,const int &t,int k){int s=mark(x);int ret=s;rig=0;
	for(int i=t;;i=f[x][i]){
		lis[++rig]=i;if(i==s)break;
		//printf("rig=%d\n",rig);	
	}
	while(w[x][lis[rig-1]]<=k){

		//printf("k=%d w[%d][lis[%d]=%d]=%d\n",k,x,i-1,lis[i-1],w[x][lis[i-1]]);
		k-=w[x][lis[--rig]];ret=lis[rig];
	}
	//if(!k)ret=lis[++rig];
	printf("%d %d\n",ret/1000,ret % 1000);	
}

int main(){
	while(scanf("%d%d%d",&n,&m,&k)!=EOF){int flag=0+0;
		for(int i=1;i<=n;i++){
			scanf("%s",c[i]);
			for(int j=m;j>0;j--)c[i][j]=c[i][j-1];c[i][0]=c[i][m+1]='#';
		}
		for(int j=0;j<=m+1;j++)c[0][j]=c[n+1][j]='#';
		memset(vis,0,sizeof(vis));
		memset(nbs,0,sizeof(nbs));num=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				//printf("%c",c[i][j]);
				if(c[i][j]!='#'){
					for(int p=0;p<P;p++){
						if(c[ii][jj]=='#')continue;
						if(c[i][j]>='0' && c[i][j]<='9')
							addEdge(tran(i,j),tran(ii,jj),c[i][j]-'0');
						else addEdge(tran(i,j),tran(ii,jj),1);
					}
				}
			}
			//printf("\n");
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(c[i][j]>='a' && c[i][j]<='z'){
					cor[c[i][j]-'a'].x=i;cor[c[i][j]-'a'].y=j;
					vis[c[i][j]-'a']=1;
				}

		scanf("%d%d",&now.x,&now.y);cor[src]=now;vis[src]=1;
		scanf("%s",con);
		scanf("%d%d",&tai.x,&tai.y);cor[res]=tai;vis[res]=1;
		

		//printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

		memset(d,0x3f,sizeof(d));
		for(int i=0;i<C;i++){
			if(!vis[i])continue;
			spfa(i);
			/*for(int x=1;x<=n;x++){
				for(int y=1;y<=m;y++)printf(" %d",d[i][tran(x,y)]);
				printf("\n");
			}*/
		}v=0;
		if(k>=d[src][mark(con[v]-'a')]){ 
			k-=d[src][mark(con[v]-'a')];v++;
		}else{
			find(src,mark(con[v]-'a'),k);
			flag=1;
		}

		if(!flag){
			for(;con[v] && d[con[v-1]-'a'][mark(con[v]-'a')]<=k;v++){

				//printf("con[%d]=%c d[%d][%d]=%d k=%d\n",v,con[v],con[v]-'a',tran(now.x,now.y),d[con[v]-'a'][tran(now.x,now.y)],k);

				k-=d[con[v-1]-'a'][mark(con[v]-'a')];//now=cor[con[v]-'a'];
			}

			//printf("k=%d v=%d\n",k,v);
			if(!con[v] && d[con[v-1]-'a'][mark(res)]<=k)
				printf("%d %d\n",tai.x,tai.y);
			else{
				if(!con[v])find(con[v-1]-'a',mark(res),k);
				else find(con[v-1]-'a',mark(con[v]-'a'),k);
			}
		}
	}
	return 0;
}
