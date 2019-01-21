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

#define maxn 30
#define maxv 1000

#define ii i+vecx[k]
#define jj j+vecy[k]

const int inf=1<<20;
const int vecx[4]={ -1,1,0,0 };
const int vecy[4]={ 0,0,-1,1 };

map<char,int> v;

int n,m,TIMER;
char a[maxn][maxn];
int g[maxv][maxv];
int mk[maxv],dis[maxv];

int cnum(int x,int y){ return x*m+y; }

int Dij(int n,int s,int t){
	int v,i;
	memset(mk,0,sizeof(mk));memset(dis,0x3f,sizeof(dis));
	dis[s]=0;for(int k=0;k<n;k++){
		v=n;for(i=0;i<n;i++)if(!mk[i] && dis[v]>dis[i])v=i;
		if(dis[v]>=inf)break;mk[v]=1;
		for(i=0;i<n;i++)
			if(!mk[i] && dis[i]>dis[v]+g[v][i])dis[i]=dis[v]+g[v][i];
	}
	//for(i=0;i<n;i++)cout<<" Dis["<<i<<"]="<<dis[i]<<endl;
	return dis[t];
}

void work(){
	int i,j,src,tai,res;
	int vp,vs,vt;
	memset(g,0x3f,sizeof(g));
	scanf("%d%d%d",&vp,&vs,&vt);v.clear();
	v.insert(pair<char,int>('T',vt));
	v.insert(pair<char,int>('.',vs));
	v.insert(pair<char,int>('#',vp));
	v.insert(pair<char,int>('@',inf));
	for(i=0;i<n;i++)scanf("%s",a[i]);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			for(int k=0;k<4;k++){
				if(ii<0 || ii>=n)continue;
				if(jj<0 || jj>=m)continue;
				g[cnum(i,j)][cnum(ii,jj)]=v[a[ii][jj]];
				//cout<<" g["<<cnum(i,j)<<"]["<<cnum(ii,jj)<<"]="<<g[cnum(i,j)][cnum(ii,jj)]<<endl;
			}
	scanf("%d%d",&i,&j);src=cnum(i,j);
	scanf("%d%d",&i,&j);tai=cnum(i,j);
	//cout<<" Dij("<<n*m<<","<<src<<","<<tai<<")="<<Dij(n*m,src,tai)<<endl;
	res=Dij(n*m,src,tai);if(res>=inf)res=-1;
	printf("Case %d: %d\n",TIMER,res);
}

int main(){
	for(TIMER=0;scanf("%d%d",&n,&m)!=EOF;work())TIMER++;
	return 0;
}
