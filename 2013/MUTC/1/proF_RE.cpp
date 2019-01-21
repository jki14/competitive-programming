#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<set>
#include<map>
#include<vector>
using namespace std;

#define N 110000
#define S 1100000

#define L (i<<1)+1
#define R (i<<1)+2

#define _size(x) (int)x.size()
#define _mkpr(x,y) make_pair(x,y)

const int inf = 0x3f3f3f3f;

int n,m,q;
int c[N][3],w[N];
int cx[S],cy[S],cd[S];
int qx[N],qy[N];
int ansx[N],ansy[N],ansd[N];

vector<int> a[N];

map<int,int> s;
map<int,int>::iterator it;

void modif(const int &i,const int &l,const int &r,const int &u,const int &v
	  ,const int &dx,const int &dy,const int &dd){
	if(u>r || v<l)return;
	if(u<=l && r<=v){
		cx[i]+=dx;cy[i]+=dy;cd[i]+=dd;
	}else{int mid=(l+r)>>1;
		modif(L,l,  mid,u,v,dx,dy,dd);
		modif(R,mid+1,r,u,v,dx,dy,dd);
	}
}

void query(const int &i,const int &l,const int &r,const int &p,int &x,int &y,int &d){
	if(p<l || p>r)return;
	x+=cx[i];y+=cy[i];d+=cd[i];
	if(l!=r){
		int mid=(l+r)>>1;
		query(L,l,  mid,p,x,y,d);
		query(R,mid+1,r,p,x,y,d);
	}
}

void dfs(const int &u){
	for(int i=0;i<_size(a[u]);i++)
		query(0,1,m,qy[a[u][i]],ansx[a[u][i]],ansy[a[u][i]],ansd[a[u][i]]);
	modif(0,1,m,w[u],w[u],0,0,-1);
	if(w[u]>1)modif(0,1,m,1,w[u]-1,0,1,0);
	if(w[u]<m)modif(0,1,m,w[u],  m,0,3,0);
	for(int i=0;i<2;i++){int v=c[u][i];
		if(!v)continue;
		if(i && w[u]<m)modif(0,1,m,w[u], m, 1,0,0);
		dfs(v);
		if(i && w[u]<m)modif(0,1,m,w[u], m,-1,0,0);
	}
	modif(0,1,m,w[u],w[u],0,0,1);
	if(w[u]>1)modif(0,1,m,1,w[u]-1,0,-1,0);
	if(w[u]<m)modif(0,1,m,w[u],  m,0,-3,0);
}

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);memset(c,0,sizeof(c));
		s.clear();
		for(int i=1;i<=n;i++){ 
			scanf("%d",&w[i]);
			s.insert(_mkpr(w[i],0));
		       	a[i].clear();	
		}
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			int u,a,b;scanf("%d%d%d",&u,&a,&b);
			c[u][0]=a;c[u][1]=b;
		}
		scanf("%d",&q);m=0;
		for(int i=0;i<q;i++){
			scanf("%d%d",&qx[i],&qy[i]);
			s.insert(_mkpr(qy[i],0));
			a[qx[i]].push_back(i);
		}
		for(it=s.begin();it!=s.end();it++)(*it).second=++m;
		for(int i=1;i<=n;i++)w[i]=s[w[i]];
		for(int i=0;i<q;i++)qy[i]=s[qy[i]];	
		memset(cx,0,sizeof(cx));
		memset(cy,0,sizeof(cy));
		memset(cd,0,sizeof(cd));
		dfs(1);
		for(int i=0;i<q;i++){
			if(ansd[i]<0)
				printf("0\n");
			else printf("%d %d\n",ansx[i],ansy[i]);
		}
	}
	return 0;
}
