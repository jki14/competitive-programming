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
int c[N][2],w[N];
int cx[S],cy[S],cd[S];
int qx[N],qy[N];
int ansx[N],ansy[N],ansd[N];
int sta[S],cur[S],top;

vector<int> a[N];

map<int,int> s;
map<int,int>::iterator it;

void build(const int &i,const int &l,const int &r){
	cx[i]=cy[i]=cd[i]=0;
	if(l!=r){int mid=(l+r)>>1;
		build(L,l,  mid);
		build(R,mid+1,r);
	}
}

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

void dfs(const int &_u){
	sta[top=1]=_u;for(int i=1;i<=n;i++)cur[i]=-1;
	while(top){int u=sta[top];
		//printf("sta[%d]==%d\n",top,u);
		//printf("w[%d]=%d\n",u,w[u]);
		if(cur[u]<0){
			for(int i=0;i<_size(a[u]);i++){ int v=a[u][i];
				query(0,1,m,qy[v],ansx[v],ansy[v],ansd[v]);
			}
			modif(0,1,m,w[u],w[u],0,0,-1);
			if(w[u]>1)modif(0,1,m,1,w[u]-1,0,1,0);
			if(w[u]<m)modif(0,1,m,w[u]+1,m,0,3,0);
			cur[u]=0;
		}
		if(cur[u]<2 && c[u][0]){
			int i=cur[u],v=c[u][i];
			if(i && w[u]<m)modif(0,1,m,w[u]+1,m,1,0,0);
			sta[++top]=v;cur[u]++;
		}else{
			if(c[u][0] && w[u]<m)modif(0,1,m,w[u]+1,m,-1,0,0);
			modif(0,1,m,w[u],w[u],0,0,1);
			if(w[u]>1)modif(0,1,m,1,w[u]-1,0,-1,0);
			if(w[u]<m)modif(0,1,m,w[u]+1,m,0,-3,0);
			top--;
		}
	}
}

#define LEN 11
char ch,cstr[LEN];

int readunsigned(){
	int ret;

	do{
		ch = getchar() ;
	}while(ch<'0');
	ret = ch - '0' ;

	while((ch = getchar()) >= '0'){
		ret = ret * 10 + ch - '0' ;
	}

	return ret;
}

void putunsigned(const int &x){
	int k=x,r=0;
	do{
		cstr[r++]=k%10+'0';
		k/=10;
	}while(k);
	while(r--){
		putchar(cstr[r]);
	}
	//putchar('\n');
}

int main(){
	int T;scanf("%d",&T);
	while(T--){
		n=readunsigned();s.clear();
		for(int i=1;i<=n;i++){ 
			w[i]=readunsigned();
			s.insert(_mkpr(w[i],0));
		       	a[i].clear();c[i][0]=c[i][1]=0;
		}
		m=readunsigned();
		for(int i=0;i<m;i++){
			int u,a,b;
			u=readunsigned();
			a=readunsigned();
			b=readunsigned();
			c[u][0]=a;c[u][1]=b;
		}
		q=readunsigned();m=0;
		for(int i=0;i<q;i++){
			qx[i]=readunsigned();
			qy[i]=readunsigned();
			s.insert(_mkpr(qy[i],0));
			a[qx[i]].push_back(i);
			ansx[i]=ansy[i]=ansd[i]=0;
		}
		for(it=s.begin();it!=s.end();it++)(*it).second=++m;
		for(int i=1;i<=n;i++)w[i]=s[w[i]];
		for(int i=0;i<q;i++)qy[i]=s[qy[i]];	
		build(0,1,m);dfs(1);
		for(int i=0;i<q;i++){
			if(ansd[i]<0)
				puts("0");
			else{
				putunsigned(ansx[i]);putchar(' ');
				putunsigned(ansy[i]);putchar('\n');
			}
		}
	}
	return 0;
}
