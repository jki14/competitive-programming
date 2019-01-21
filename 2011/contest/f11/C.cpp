#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<climits>
#include<algorithm>
#include<map>
#include<string>
using namespace std;

#define maxn 510

#define maxv 300000
#define maxe 2000000

#define maxd 10000000

#define ii (i+dx[k])
#define jj (j+dy[k])

const int inf=LONG_MAX>>1;

const int dx[4]={ -1,0,1,0 };
const int dy[4]={ 0,1,0,-1 };

int n,m,a[maxn][maxn],s,t;
char stmp[maxn];

int nv,ne,tot;
int head[maxv],next[maxe],adj[maxe];
int value[maxe];

int qs,q1,temp;
int q[maxv],dist[maxv],vtime[maxv];
bool v[maxv];

int spfa(int x,int y){
	qs=0;
	q1=1;
	q[qs]=x;
	memset(v,0,sizeof(v));
	v[q[qs]]=true;
	for(int i=0;i!=nv;++i)dist[i]=inf;
	dist[q[qs]]=0;
	memset(vtime,0,sizeof(vtime));
	vtime[q[qs]]=1;
	while(q1){
		temp =head[q[qs]];
		while(temp){
			if(dist[q[qs]]+value[temp]<dist[adj[temp]]){
				dist[adj[temp]]=dist[q[qs]]+value[temp];
				if(!v[adj[temp]]){
					v[adj[temp]]=true;
					++q1;
					q[(qs+q1-1)%nv]=adj[temp];
					++vtime[adj[temp]];
					if(vtime[adj[temp]]>nv)return -1;
				}
			}
			temp=next[temp];
		}
		v[q[qs]]=false;
		qs=(qs+1)%nv;
		--q1;
	}
	return dist[y];
}

void init(){
	tot=0;memset(head,0,sizeof(head));
}

void add_edge(int x,int y,int z){
	//cout<<"AddEdge "<<x<<"->"<<y<<endl;
	tot++;
	next[tot]=head[x];
	adj[tot]=y;
	value[tot]=z;
	head[x]=tot;
}

int allow(const int &x,const int &y){
	if(x<0 || x>=n)return 0;
	if(y<0 || y>=m)return 0;
	return 1;
}

void work(){
	int i,j,k,x,y;
	init();
	memset(a,0,sizeof(a));
	for(i=0;i<n;i++){
		scanf("%s",stmp);
		for(j=0;j<m;j++){
			if(stmp[j]!='#')a[i][j]=1;
			if(stmp[j]=='t')t=i*m+j;
			if(stmp[j]=='s')s=i*m+j;
		}
	}
	for(i=0;i<n;i++)
		for(j=0;j<m;j++){
			scanf("%d",&k);
			while(k--){
				scanf("%d%d",&x,&y);x--;y--;
				add_edge(i*m+j,x*m+y,1);
			}
		}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(a[i][j])
				for(k=0;k<4;k++)
					if(allow(ii,jj) && a[ii][jj])
						add_edge(i*m+j,ii*m+jj,1);
	nv=n*m;
	printf("%d\n",spfa(s,t));
}


int main(){
	while(scanf("%d%d",&n,&m)!=EOF)work();
	return 0;
}

