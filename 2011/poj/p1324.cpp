#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<ctime>
#include<algorithm>
using namespace std;

#define maxn 22
#define maxm 22
#define maxL 8
#define maxK 4

const int maxs=1<<((maxL-1)<<1);

const int maxq=maxs*maxn*maxm;

const int dx[maxK]={ 0,-1,0,1 };
const int dy[maxK]={ -1,0,1,0 };

const int px[maxK]={ 0,1,0,-1 };
const int py[maxK]={ 1,0,-1,0 };

int T;

int n,m,L;
int a[maxs][maxK];
int c[maxn][maxm];
int s[maxs],v[maxs],sum;
int mk[maxn][maxm][maxs];
int q[maxq],head,tail;
int path[maxK];
int state,point;

void dfs(const int &i,const int &x,const int &y){
	if(i==L){
		s[sum++]=state;
		v[state]=1;
		return;
	}
	int k,xx,yy;
	for(k=0;k<maxK;k++){xx=x+dx[k];yy=y+dy[k];
		if(c[xx][yy])continue;
		c[xx][yy]=1;
		state<<=2;
		state|=k;
		dfs(i+1,xx,yy);
		c[xx][yy]=0;
		state>>=2;
	}
}

void makea(){
	memset(c,0,sizeof(c));
	memset(v,0,sizeof(v));
	sum=state=0;
	c[10][10]=1;dfs(1,10,10);
	memset(a,-1,sizeof(a));
	int i,j,k,x,y;
	for(k=0;k<maxK;k++)path[k]=(k<<((L-2)<<1));
	for(i=0;i<sum;i++){state=s[i];
		memset(c,0,sizeof(c));
		x=y=10;c[x][y]=1;
		for(j=L-2;j>=0;j--){
			k=state>>(j<<1);state&=((1<<(j<<1))-1);
			x+=dx[k];y+=dy[k];
			c[x][y]=1;
		}
		for(k=0;k<maxK;k++){state=s[i];
			if(c[10+px[k]][10+py[k]])continue;
			state>>=2;state|=path[k];
			if(v[state])a[s[i]][k]=state;
		}
	}
	//cout<<"sum="<<sum<<endl;
}

int getk(const int &x,const int &y,const int &xx,const int &yy){
	for(int k=0;k<maxK;k++){
		if(x+dx[k]==xx && y+dy[k]==yy)return k;
	}
	printf("GetK Error!\n");
	return 0;
}

void work(){
	makea();head=tail=0;
	memset(mk,0x7f,sizeof(mk));
	memset(c,0,sizeof(c));
	int i,x,y,xx,yy,sx,sy;
	for(i=state=0;i<L;i++){
		scanf("%d%d",&xx,&yy);
		if(!i){
			sx=x=xx;sy=y=yy;
			continue;
		}
		state<<=2;
		state|=getk(x,y,xx,yy);
		//printf("getk=%d\n",getk(x,y,xx,yy));
		x=xx;y=yy;
	}
	//printf("state=%d\n",state);
	mk[sx][sy][state]=0;
	point=sx*10000000+sy*100000+state;
	q[tail++]=point;
	scanf("%d",&i);
	while(i--){
		scanf("%d%d",&x,&y);
		c[x][y]=1;
	}
	for(x=0;x<=n+1;x++)c[x][0]=c[x][m+1]=1;
	for(y=0;y<=m+1;y++)c[0][y]=c[n+1][y]=1;
	while(head<tail){
		//if(tail>7000000)break;
		//Get X,Y,State
		point=q[head];
		x=point/10000000;point%=10000000;
		y=point/100000;point%=100000;
		state=point;
		//printf("BFS: x=%d y=%d state=%d cost=%d\n",x,y,state,mk[x][y][state]);
		//PutResult
		if(x==1 && y==1){
			printf("Case %d: %d\n",T,mk[x][y][state]);
			return;
		}
		//move Test
		for(i=0;i<maxK;i++){xx=x+px[i];yy=y+py[i];
			if(c[xx][yy])continue;
			if(a[state][i]<0)continue;
			if(mk[xx][yy][a[state][i]]<=mk[x][y][state]+1)continue;
			mk[xx][yy][a[state][i]]=mk[x][y][state]+1;
			point=xx*10000000+yy*100000+a[state][i];
			q[tail++]=point;
		}
		head++;
	}
	printf("Case %d: -1\n",T);
}

int main(){
	for(T=1;scanf("%d%d%d",&n,&m,&L)!=EOF && !(n==0 && m==0 && L==0);T++)
		work();
	return 0;
}

