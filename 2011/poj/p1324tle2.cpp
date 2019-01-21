#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<climits>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

#define maxn 30
#define maxm 30
#define maxL 10
#define maxs 70000
#define maxp 1000000
#define K 4

#define xx (x+dx[i])
#define yy (y+dy[i])

const int dx[K]={ 0,-1,0,1 };
const int dy[K]={ -1,0,1,0 };

int cmpL=0;

struct SState{
	int dK[maxL];
	bool operator < (const SState &a) const{
		for(int i=1;i<cmpL;i++){
			if(a.dK[i]!=dK[i])return a.dK[i]<dK[i];
		}
		return 0;
	}
};

typedef SState state;

struct SPoint{
	int x,y;
	int S;
	bool operator < (const SPoint &a) const{
		if(a.x!=x)return a.x<x;
		if(a.y!=y)return a.y<y;
		return a.S<S;
	}
};

typedef SPoint point;

int T;

int n,m,L,tot;
map<state,int> s2i;
map<state,int>::iterator sit;
map<int,state> i2s;
map<int,state>::iterator iit;
map<point,int> p2i;
map<point,int>::iterator pit;
int a[maxs][K];
int c[maxn][maxm];
state s,s2;
point p,p2;
//vector<point> q;
point q[maxp];
int head,tail;

void makestate(const int &k,const int &x,const int &y){
	if(k==L){
		s2i.insert(pair<state,int>(s,++tot));
		i2s.insert(pair<int,state>(tot,s));
		return;
	}
	for(int i=0;i<K;i++){
		if(c[xx][yy])continue;
		c[xx][yy]=1;s.dK[k]=i;
		makestate(k+1,xx,yy);
		c[xx][yy]=0;
	}
}

void makea(){
	s2i.clear();
	i2s.clear();
	tot=0;
	memset(c,0,sizeof(c));
	c[10][10]=1;s.dK[0]=s2.dK[0]=0;
	makestate(1,10,10);
	int i,j,x,y,p;
	for(j=1;j<=tot;j++){s=i2s[j];
		memset(c,0,sizeof(c));
		x=y=10;
		for(i=0;i<L;i++){
			c[x][y]=1;
			x+=dx[s.dK[i+1]];
			y+=dy[s.dK[i+1]];
		}
		x=y=10;
		for(i=0;i<K;i++){
			if(c[xx][yy]){
				a[j][i]=0;
				continue;
			}
			for(p=L-1;p>=2;p--)s2.dK[p]=s.dK[p-1];
			s2.dK[1]=(i+2)%4;
			a[j][i]=s2i[s2];
		}
	}
	/*printf("--------------------Debug:void makea()--------------------\n");
	for(i=1;i<=tot;i++){
		printf("State %d:\n",i);
		s=i2s[i];
		memset(c,-1,sizeof(c));
		x=y=10;
		c[x][y]=0;
		for(j=1;j<L;j++){5
			x+=dx[s.dK[j]];
			y+=dy[s.dK[j]];
			c[x][y]=j;
		}
		for(x=10-L;x<=10+L;x++){
			for(y=10-L;y<=10+L;y++){
				if(c[x][y]<0){ printf(" ");continue; }
				printf("%d",c[x][y]);
			}
			printf("\n");
		}
		printf("  for State %d\n",i);
		for(j=0;j<K;j++)
			printf("    %d:->%d\n",j,a[i][j]);
	}
	printf("----------------------------------------------------------\n");*/
}

int getK(const int &x,const int &y){
	if(x) return (x==1)?3:1;
	if(y) return (y==1)?2:0;
	return -1;
}

void work(){ cmpL=L;
	makea();p2i.clear();
	//cout<<"tot ="<<tot<<endl;
	memset(c,0,sizeof(c));
	int i,j,x,y,x2,y2,sx,sy,tx,ty;
	for(i=0;i<=n+1;i++)c[i][0]=c[i][m+1]=1;
	for(i=0;i<=m+1;i++)c[0][i]=c[n+1][i]=1;
	for(i=0;i<L;i++){
		scanf("%d%d",&x2,&y2);
		if(i){
			s.dK[i]=getK(x2-x,y2-y);
		}else{
			sx=x2;sy=y2;
		}
		x=x2;y=y2;
	}
	for(scanf("%d",&i);i;i--){
		scanf("%d%d",&x,&y);
		c[x][y]=1;
	}
	p.x=sx;p.y=sy;p.S=s2i[s];
	//q.clear();q.push_back(p);
	head=tail=0;q[tail++]=p;
	p2i[p]=0;tx=ty=1;
	for(;head<tail;head++){p=q[head];j=p2i[p];
		if(j>250)break;
		x=p.x;y=p.y;
		//printf("px=%d,py=%d,ps=%d\n",x,y,p.S);
		if(x==tx && y==ty){
			printf("Case %d: %d\n",T,j);
			return;
		}
		for(i=0;i<K;i++){
			if(!a[p.S][i])continue;
			if(c[xx][yy])continue;
			p2.x=xx;p2.y=yy;p2.S=a[p.S][i];
			pit=p2i.find(p2);
			if(pit!=p2i.end())continue;
			p2i.insert(pair<point,int>(p2,j+1));
			//q.push_back(p2);
			q[tail++]=p2;
		}
	}
	printf("Case %d: -1\n",T);
}

int main(){
	T=0;
	while(scanf("%d%d%d",&n,&m,&L)!=EOF && !(n==0 && m==0 && L==0)){
		T++;
		work();
	}
	return 0;
}
