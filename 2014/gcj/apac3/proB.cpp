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

#define F 1314
#define N 3100
#define M 9100

const int inf=0x3f3f3f3f;

int dst[M],wht[M],nxt[M],nbs[N],enm;
int dis[N],mrk[N],pos[N],hip[N],len;

int n,m,q;
int s[N],d[N],c[N];

void AddEdge(const int &u,const int &v,const int &w){
	dst[++enm]=v;wht[enm]=w;nxt[enm]=nbs[u];nbs[u]=enm;
}

void update(const int &r){
	int q=pos[r],p=q>>1;
	while(p && dis[hip[p]]>dis[r]){
		pos[hip[p]]=q; hip[q]=hip[p];
		q=p; p=q>>1;
	}
	hip[q]=r;pos[r]=q;
}

int getmin(){
	int ret=hip[1],p=1,q=2,r=hip[len--];
	while(q<=len){
		if(q<len && dis[hip[q+1]]<dis[hip[q]])q++;
		if(dis[hip[q]]<dis[r]){
			pos[hip[q]]=p;hip[p]=hip[q];
			p=q;q=p<<1;
		}else break;
	}
	hip[p]=r;pos[r]=p;
	return ret;
}

void dijkstra(const int &src){
	for(int i=0;i<s[n]+F;i++){ dis[i]=inf;mrk[i]=pos[i]=0; }
	dis[src]=0;hip[len=1]=src;pos[src]=1;
	while(len){
		int u=getmin();mrk[u]=1;
		for(int j=nbs[u];j;j=nxt[j]){int v=dst[j];
			if(!mrk[v] && dis[u]+wht[j]<dis[v]){
				if(!pos[v]){ hip[++len]=v;pos[v]=len; }
				dis[v]=dis[u]+wht[j];update(v);
			}
		}
	}
}

int main(){
	int T;scanf("%d", &T);
	for(int _T=1;_T<=T;_T++){
		printf("Case #%d:\n", _T);
		scanf("%d", &n);s[0]=0;
		memset(nbs,0,sizeof(nbs));enm=0;
		for(int i=0;i<n;i++){
			scanf("%d%d", &c[i], &d[i]);
			s[i+1]=s[i]+c[i];
			for(int j=0;j<c[i]-1;j++){
				int tim;scanf("%d",&tim);
				AddEdge(s[i]+j, s[i]+j+1, tim);
				AddEdge(s[i]+j+1, s[i]+j, tim);
			}
			for(int j=0;j<c[i];j++){
				AddEdge(s[i]+j, s[i]+j+F, 0);
				AddEdge(s[i]+j+F, s[i]+j, d[i]);
			}
		}
		scanf("%d", &m);
		for(int i=0;i<m;i++){
			int ux,uy,vx,vy,t;
			scanf("%d%d%d%d%d",&ux,&uy,&vx,&vy,&t);
			ux--;uy--;vx--;vy--;
			AddEdge(s[ux]+uy+F, s[vx]+vy+F, t);
			AddEdge(s[vx]+vy+F, s[ux]+uy+F, t);
		}
		scanf("%d",&q);
		for(int i=0;i<q;i++){
			int ux,uy,vx,vy;
			scanf("%d%d%d%d", &ux, &uy, &vx, &vy);
			ux--;uy--;vx--;vy--;
			dijkstra(s[ux]+uy+F);
			if(dis[s[vx]+vy+F]!=inf)
				printf("%d\n",dis[s[vx]+vy+F]);
			else printf("-1\n");
		}
	}
	return 0;
}

