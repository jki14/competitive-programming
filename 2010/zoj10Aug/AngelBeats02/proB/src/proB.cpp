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

#define maxn 16
#define maxv 256

#define ii i+vecx[k]
#define jj j+vecy[k]

#define p q[l]

const int vecx[4] = { 1,-1,0,0 };
const int vecy[4] = { 0,0,1,-1 };

const int maxt=1<<maxn;
const int inf=1000;

struct state{
	int u,t;
	state(){ }
	state(const int &v0,const int &v1){ u=v0;t=v1; }
};

int n,m,vex,num,tar,src;
int id[maxn*maxn];

vector<int> a[maxn*maxn];

int f[maxn*maxn][1<<maxn];
struct state q[maxn*(1<<maxn)];
char str[maxn],ss[maxn*maxn];

int getNum(const int &x,const int &y){ return x*m+y; }
int getMin(const int &x,const int &y){ return (x<y)?x:y; }

int bfs(const int &x){
	if(x<0)return 0;
	memset(f,0x8f,sizeof(f));
	int i,l,r,v,t;l=r=0;
	q[r++]=state(src,0);
	f[p.u][p.t]=x;
	while(l<r){
		//cout<<" f["<<p.u<<"]["<<p.t<<"]="<<f[p.u][p.t]<<endl;
		if((p.t&tar)==tar)return 1;
		for(i=0;i<(int)a[p.u].size();i++){
			v=a[p.u][i];
			if(id[v]<inf)t=p.t|(1<<id[v]);else t=p.t;
			if(f[v][t]<f[p.u][p.t]-1){
				f[v][t]=f[p.u][p.t]-1;if(f[v][t]<0)continue;
				if(ss[v]=='G' && !(p.t&(1<<id[v])))
					f[v][t]=x;
				q[r++]=state(v,t);
			}
		}
		l++;
	}
	return 0;
}

int getRes(){
	int l,r,mid;
	l=0;r=inf;
	if(!bfs(r))return -1;
	while(l<r){
		mid=(l+r)>>1;
		if(bfs(mid) && !bfs(mid-1))return mid;
		if(bfs(mid))r=mid-1;else l=mid+1;
	}
	return -1;
}

void work(){
	int i,j,k,u,v;
	memset(id,0x3f,sizeof(id));
	vex=n*m;num=tar=0;
	for(i=0;i<n;i++){
		scanf("%s",str);
		for(j=0;j<m;j++){
			ss[u=getNum(i,j)]=str[j];
			a[u].clear();
		}
	}
	for(i=0;i<n;i++)
		for(j=0;j<m;j++){
			u=getNum(i,j);
			if(ss[u]=='D')continue;
			if(ss[u]=='F')src=u;
			if(ss[u]=='G' || ss[u]=='Y'){
				id[u]=num++;
				if(ss[u]=='Y')tar|=(1<<id[u]);
			}
			for(k=0;k<4;k++){
				if(ii<0 || ii>n)continue;
				if(jj<0 || jj>m)continue;
				v=getNum(ii,jj);if(ss[v]=='D')continue;
				a[u].push_back(v);
			}
		}
	/*for(k=0;k<vex;k++)
		for(u=0;u<vex;u++)
			for(v=0;v<vex;v++)
				g[u][v]=getMin(g[u][v],g[u][k]+g[k][v]);
	for(u=0;u<vex;u++){
		if(ss[u]=='D' || ss[u]=='S')continue;
		id[num]=u;s[num]=ss[u];
		if(ss[u]=='F')src=num;
		if(ss[u]=='Y')tar|=(1<<num);
		num++;
	}
	for(u=0;u<num;u++)
		for(v=0;v<num;v++)
			a[u][v]=g[id[u]][id[v]];*/
	//cout<<tar<<endl;
	printf("%d\n",getRes());
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF && !(n==0 && m==0))work();
	return 0;
}
