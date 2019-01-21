#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

#define maxv 110
#define maxe 11000
#define maxl 50

const int inf=1<<30;

char tmp[maxl];

string str;

map<string,int> s;
map<string,int>::iterator it;

int g[maxv][maxv],a[maxv][maxv],f[maxv],mk[maxv];

int n,m,k,res;
int id[maxe],eu[maxe],ev[maxe],ew[maxe],e;
int cmp(const int &i,const int &j){ return ew[i]<ew[j]; }

int find(const int &x){ if(x!=f[x])f[x]=find(f[x]); return f[x]; }

void Kruskal(){
	int i,j,p;
	for(int i=0;i<=n;i++)f[i]=i;
	for(i=0;i<e;i++)id[i]=i;
	sort(id,id+e,cmp);
	//cout<<"e="<<e<<endl;
	for(j=0;j<e;j++){
		p=id[j];
		if(find(eu[p])==find(ev[p]))continue;
		a[eu[p]][ev[p]]=a[ev[p]][eu[p]]=1;f[find(ev[p])]=find(eu[p]);
	}
	//cout<<"......"<<endl;
}

int minp(const int &u){
	int r=u;mk[u]=1;
	for(int v=1;v<n;v++)if(!mk[v] && a[u][v]){
		int p=minp(v);if(g[p][0]<g[r][0])r=p;
	}
	return r;
}

int maxw(const int &u,int &uu,int &vv){
	mk[u]=1;if(!u)return 1;
	for(int v=0;v<n;v++)if(!mk[v] && a[u][v]){
		if(maxw(v,uu,vv)){
			//cout<<"......g["<<u<<"]["<<v<<"]="<<g[u][v]<<endl;
			//cout<<"..old.g["<<uu<<"]["<<vv<<"]="<<g[uu][vv]<<endl;
			if(g[u][v]>g[uu][vv]){ uu=u;vv=v; }
			return 1;
		}
	}
	return 0;
}

void work(){
	memset(g,0x7f,sizeof(g));
	memset(a,0,sizeof(a));
	int i,u,v,w,best,x,y,xx,yy;res=e=0;
	n=1;s.clear();s.insert(pair<string,int>("Park",0));
	for(i=0;i<m;i++){
		scanf("%s",tmp);str=tmp;it=s.find(str);
		if(it==s.end())s[str]=n++;u=s[str];
		scanf("%s",tmp);str=tmp;it=s.find(str);
		if(it==s.end())s[str]=n++;v=s[str];
		scanf("%d",&w);
		if(w<g[u][v])g[u][v]=g[v][u]=w;
		if(u!=0 && v!=0){
			eu[e]=u;ev[e]=v;ew[e++]=g[u][v];
		}
	}
	//cout<<"  n="<<n<<endl;
	scanf("%d",&k);
	Kruskal();
	//AddMustEdge
	memset(mk,0,sizeof(mk));
	for(i=1;i<n;i++)if(!mk[i]){
		v=minp(i);k--;
		//cout<<" :Link "<<v<<" "<<g[0][v]<<endl;
		a[0][v]=a[v][0]=1;
	}
	//Updata
	while(k){
		best=0;
		for(u=1;u<n;u++){
			if(!a[0][u] && g[0][u]<inf){
				//cout<<" g[0]["<<u<<"]="<<g[0][u]<<endl;
				memset(mk,0,sizeof(mk));
				xx=0;yy=u;maxw(u,xx,yy);
				int patch=g[xx][yy]-g[0][u];
				if(patch>best){ best=patch;v=u;x=xx;y=yy; }
			}
		}
		//cout<<"BEST="<<best<<endl;
		if(!best)break;
		a[0][v]=a[v][0]=1;
		a[x][y]=a[y][x]=0;
		k--;
		//cout<<"   CudEdge "<<x<<" <-> "<<y<<" ="<<g[x][y]<<endl;
		//cout<<"   AddEdge "<<0<<" <-> "<<v<<" ="<<g[0][v]<<endl;
	}
	//GetRes
	for(u=0;u<n;u++)
		for(v=u+1;v<n;v++)
			if(a[u][v]){
				//cout<<g[u][v]<<endl;
				res+=g[u][v];
			}
	printf("Total miles driven: %d\n",res);
}

int main(){
	while(scanf("%d",&m)!=EOF)
		work();
	return 0;
}
