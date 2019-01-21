#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define L (i<<1)+1
#define R (i<<1)+2
#define N 110000
#define S 1100000
#define E 11

int n,m,s;
int nbs[N],nxt[N],dst[N],num;
int lef[N],rig[N];
int a[S],c[S],f[S];

char opt[E];

void addE(const int &u,const int &v){ nxt[++num]=nbs[u];nbs[u]=num;dst[num]=v; }

void dfs(const int &u){
	lef[u]=++s;
	for(int i=nbs[u];i;i=nxt[i]){ int v=dst[i];
		dfs(v);
	}
	rig[u]=++s;
}

void build(const int &i,const int &l,const int &r){
	c[i]=f[i]=0;
	if(l==r){
		a[i]=1;
	}else{
		int mid=(l+r)>>1;
		build(L,l,  mid);
		build(R,mid+1,r);
		a[i]=a[L]+a[R];
	}
}

void modif(const int &i,const int &l,const int &r,const int &u,const int &v){
	if(u>r || v<l)return;
	if(u<=l && r<=v){
		f[i]^=1;
		c[i]=a[i]-c[i];
	}else{
		int mid=(l+r)>>1;
		if(f[i]){
			modif(L,l,  mid,1,s);
			modif(R,mid+1,r,1,s);
			f[i]=0;
		}
		modif(L,l,  mid,u,v);
		modif(R,mid+1,r,u,v);
		c[i]=c[L]+c[R];
	}
}

int  query(const int &i,const int &l,const int &r,const int &u,const int &v){
	if(u>r || v<l)return 0;
	if(u<=l && r<=v){
		return c[i];
	}else{
		int mid=(l+r)>>1;
		if(f[i]){
			modif(L,l,  mid,1,s);
			modif(R,mid+1,r,1,s);
			f[i]=0;
		}
		return query(L,l,  mid,u,v)
		      +query(R,mid+1,r,u,v);
	}
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(nbs,0,sizeof(nbs));num=0;
		for(int v=2;v<=n;v++){ int u;scanf("%d",&u);addE(u,v); }
		//memset(c,0,sizeof(c));
		//memset(f,0,sizeof(f));
		s=0;dfs(1);build(0,1,s);
		for(int i=1;i<=m;i++){
			int x;scanf("%s%d",opt,&x);
			if(opt[0]=='o'){
				modif(0,1,s,lef[x],rig[x]);
			}else{
				printf("%d\n",query(0,1,s,lef[x],rig[x])/2);
			}
		}
		printf("\n");
	}
	return 0;
}
