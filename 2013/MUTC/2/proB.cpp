#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define N 210000
#define M 2100000

#define rev(x) (x&1)?(x+1):(x-1)

int n,m,root;
int src[M],dst[M],nxt[M];
int nbs[N],mrk[N],low[N],d[N],num,bnum,ti;
int f[N],tmpu[M],tmpv[M],tnum,w;

int sta[N],cur[N],stw[N],top;

char usd[M],bri[M];

void addEdge(const int &u,const int &v){

	//printf("addEdge %d->%d\n",u,v);

	nxt[++num]=nbs[u];nbs[u]=num;
	src[num]=u;dst[num]=v;
	bri[num]=usd[num]=0;
}

void TarjanBridge(const int &root){
	sta[top=1]=root;
	memset(cur,0xff,sizeof(cur));
	while(top){int u=sta[top];
		if(cur[u]<0){
			low[u]=d[u]=++ti;mrk[u]=1;
			cur[u]=nbs[u];stw[u]=0;
		}

		if(stw[u]){
			int v=dst[stw[u]];
			low[u]=min(low[u],low[v]);	
			if(low[v]==d[v]){
				bnum++;
				bri[stw[u]]=1;
				bri[rev(stw[u])]=1;
			}
			stw[u]=0;
		}

		if(cur[u]){int v=dst[cur[u]];
			if(!usd[cur[u]]){
				if(!mrk[v]){
					sta[++top]=v;
					stw[u]=cur[u];
				}else low[u]=min(low[u],d[v]);
			}
			usd[cur[u]]=usd[rev(cur[u])]=1;
			cur[u]=nxt[cur[u]];
		}else top--;
	}
}

void MarkBridge(){
	memset(mrk,0,sizeof(mrk));
	ti=bnum=0;
	TarjanBridge(1);
	//printf("bnum=%d, ti=%d\n",bnum,ti);
}

int find(const int &u){
	if(f[u]!=u){++ti;
		sta[top=1]=u;
		while(top){int v=sta[top];//printf("sta[%d]=%d\n",top,sta[top]);
			if(mrk[v]!=ti){
				mrk[v]=ti;
				if(f[v]!=v)sta[++top]=f[v];
			}else{
				f[v]=f[f[v]];
				top--;
			}
		}
	}
	//printf("f[%d]=%d\n",u,f[u]);
	return f[u];
}

void dfs(int _root){
	sta[top=1]=_root;stw[top]=0;
	memset(cur,0xff,sizeof(cur));
	while(top){int u=sta[top];
		//printf("root=%d u=%d w=%d\n",root,u,stw[top]);
		if(cur[u]<0){
			cur[u]=nbs[u];
			mrk[u]=1;
			if(stw[top]>w){
				w=stw[top];
				root=u;
			}
		}
		if(cur[u]){int v=dst[cur[u]];
			if(!mrk[v]){
				sta[++top]=v;
				stw[  top]=stw[top-1]+1;
			}
			cur[u]=nxt[cur[u]];
		}else top--;
	}
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF && !(n==0 && m==0)){
		memset(nbs,0,sizeof(nbs));num=0;
		for(int i=0;i<m;i++){
			int u,v;scanf("%d%d",&u,&v);
			addEdge(u,v);addEdge(v,u);
		}
		MarkBridge();tnum=0;
		for(int i=1;i<=n;i++)f[i]=i;
		memset(mrk,0,sizeof(mrk));ti=0;
		for(int i=1;i<=num;i++){
			int u,v;
			tmpu[tnum]=u=src[i];
			tmpv[tnum]=v=dst[i];
			tnum++;
			if(bri[i])continue;
			//printf("link %d->%d >>>",find(u),find(v));
			if(find(u)!=find(v))f[find(u)]=find(v);
			//printf(" find(%d)=%d find(%d)=%d",u,find(u),v,find(v));
		}
		memset(nbs,0,sizeof(nbs));num=w=0;root=-1;
		for(int i=0;i<tnum;i++){
			int u=find(tmpu[i]),v=find(tmpv[i]);
			if(u==v)continue;
			if(root==-1)root=u;
			addEdge(u,v);//addEdge(v,u);
		}
		memset(mrk,0,sizeof(mrk));
		dfs(root);
		//printf("----------\n");
		memset(mrk,0,sizeof(mrk));
		dfs(root);
		printf("%d\n",bnum-w);
	}
}
