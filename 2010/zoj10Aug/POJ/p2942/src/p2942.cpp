#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define maxn 1100

int n,m,g[maxn][maxn],mk[maxn],d[maxn],low[maxn],len,que[maxn];
int color,ti,cutvertexnum,cutvertexlist[maxn],blocknum;
int b[maxn],bit[maxn],mark[maxn],res;

int SCircle(int u,int c){
	if(bit[u]!=-1)return (bit[u]==c)?0:1;
	bit[u]=c;
	for(int v=1;v<=n;v++)
		if(g[u][v] && b[v])
			if(SCircle(v,c^1))return 1;
	return 0;
}

void dvsvisit(int u,int p){
	int v,k,s=0,bCutvertex=0;low[u]=d[u]=++ti;mk[u]=-color;que[++len]=u;
	for(v=1;v<=n;v++)if(g[u][v]&&v!=p){
		if(mk[v]==0){dvsvisit(v,u);s++;
			if(low[v]<low[u])low[u]=low[v];
			if(low[v]>=d[u]){
				memset(b,0,sizeof(b));
				memset(bit,-1,sizeof(bit));
				k=0;while(que[len]!=v){
					b[que[len--]]=1;k++;
					cout<<que[len+1]<<" ";
				}
				b[que[len--]]=b[u]=1;k+=2;
				cout<<que[len+1]<<" "<<u<<" ";
				bCutvertex=1;blocknum++;
				if(k>2 && SCircle(u,0))
					for(k=1;k<=n;k++)mark[k]|=b[k];
				cout<<endl<<"....."<<endl;
			}
		}else if(d[v]<low[u]) low[u]=d[v];
	}
	if((p&&bCutvertex)||(!p&&s>1))cutvertexlist[cutvertexnum++]=u;
	mk[u]=color;
}

void Block(){
	int i,k;; memset(mk,0,sizeof(mk));
	color=ti=cutvertexnum=blocknum=0;
	for(i=1;i<=n;i++)if(!mk[i]){
		++color;len=0;dvsvisit(i,0);
		if(len>1 || d[i]==ti){
			memset(b,0,sizeof(b));
			memset(bit,-1,sizeof(bit));
			k=0;while(len>1){
				b[que[len--]]=1;k++;
				cout<<que[len+1]<<" ";
			}
			cout<<i<<" ";
			b[i]=1;k++;
			if(k>2 && SCircle(i,0))
				for(k=1;k<=n;k++)mark[k]|=b[k];
			blocknum++;
			cout<<endl<<"....."<<endl;
		}
	}
		memset(b,0,sizeof(b));
		memset(bit,-1,sizeof(bit));
		for(i=0;i<cutvertexnum;i++){
			b[cutvertexlist[i]]=1;
			cout<<cutvertexlist[i]<<" ";
		}
		if(SCircle(cutvertexlist[0],0)){
			for(k=1;k<=n;k++)mark[k]|=b[k];
		}
		cout<<endl<<"....."<<endl;
}

void work(){
	memset(g,1,sizeof(g));
	memset(mark,0,sizeof(mark));
	int i;
	for(i=1;i<=n;i++)g[i][i]=0;
	while(m--){ int u,v;scanf("%d%d",&u,&v);g[u][v]=g[v][u]=0; }
	Block();res=0;
	for(i=1;i<=n;i++)if(!mark[i])res++;
	//printf("%d\n",res);
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF && !(n==0 && m==0))work();
	return 0;
}
