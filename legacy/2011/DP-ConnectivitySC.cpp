//============================================================================
// Name        : ConnectivityDP-SingleCircle
// Author      : J.Ki
// Version     : 1.00
// Copyright   : WangZhe (Chongqing University Computer College)
// Description : 插头DP，单回路完全遍历方案数，例为Ural(timus)1519
//============================================================================

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
#include<deque>
#include<set>
#include<map>
using namespace std;

#define N 15
#define M 30
#define S 21000
#define K 2
#define E 1100000

#define pre (now^1)
#define d0(x) (x<<1)
#define d1(x) ((x<<1)+1)


typedef long long lld;

const int inf=0x3fffffff;
const int key=10003;

char c[N][N];

int n,m,tarx,tary;
int bit[M],now=0;
int tot[K],s[K][S];
int ev[E],nxt[E],nbs[key],num;
lld f[K][S],ans;

void clear(){ memset(nbs,0,sizeof(nbs));num=0; }

void AddEdge(const int &u,const int &v){
	num++;ev[num]=v;
	nxt[num]=nbs[u];nbs[u]=num;
}

int kind(const int &x,const int &y){
	if(!x && !y)return 0;
	return (x)?1:2;
}

void add(const int &sta,const lld &val){
	int u=sta%key;

	for(int i=nbs[u];i;i=nxt[i]){int v=ev[i];
		if(s[now][v]==sta){
			f[now][v]+=val;
			return;
		}
	}
	s[now][++tot[now]]=sta;
	f[now][tot[now]]=val;
	AddEdge(u,tot[now]);
}

void dis(const int &y){
	for(int i=1;i<=tot[pre];i++){
		int sta=s[pre][i];
		if((sta&bit[d0(y)]) || (sta&bit[d1(y)]) || (sta&bit[d0(m)]) || (sta&bit[d1(m)]))continue;
		add(sta,f[pre][i]);
	}
}

void pas(const int &x,const int &y){
	for(int i=1;i<=tot[pre];i++){
		int sta=s[pre][i];
		lld val=f[pre][i];
		int nor=kind(sta&bit[d0(y)],sta&bit[d1(y)]);
		int lef=kind(sta&bit[d0(m)],sta&bit[d1(m)]);
		if(!y && lef)continue;

		int newsta=(~(bit[d0(y)]|bit[d1(y)]|bit[d0(m)]|bit[d1(m)]))&sta;
		switch(lef){
			case 0:
				switch(nor){
					case 0:add(newsta|bit[d0(y)]|bit[d1(m)],val);break;
					case 1:add(newsta|bit[d0(y)],val);add(newsta|bit[d0(m)],val);break;
					case 2:add(newsta|bit[d1(y)],val);add(newsta|bit[d1(m)],val);break;
				}break;

			case 1:
				switch(nor){
					case 0:add(newsta|bit[d0(y)],val);add(newsta|bit[d0(m)],val);break;
					case 1:
					       for(int j=y,top=0;1;j++){
						       int stak=kind(sta&bit[d0(j)],sta&bit[d1(j)]);
						       if(stak==1)
							       top++;
						       else if(stak==2)top--;
						       if(!top){
							       add((newsta^bit[d1(j)])|bit[d0(j)],val);
							       break;
						       }
					       }break;
					case 2:if(x==tarx && y==tary && !newsta)ans+=val;break;
				}break;
			case 2:
				switch(nor){
					case 0:add(newsta|bit[d1(y)],val);add(newsta|bit[d1(m)],val);break;
					case 1:add(newsta,val);break;
					case 2:
					       for(int j=y,top=0;1;j--){
						       int stak=kind(sta&bit[d0(j)],sta&bit[d1(j)]);
						       if(stak==1)
							       top++;
						       else if(stak==2)top--;
						       if(!top){
							       add((newsta^bit[d0(j)])|bit[d1(j)],val);
							       break;
						       }
					       }break;
				}break;
		}
	}
}

void work(){
	/* Input */
	ans=0LL;now=1;
	tot[now]=0;clear();
	memset(f,0,sizeof(f));
	for(int i=0;i<n;i++)scanf("%s",c[i]);
	if(c[0][0]=='*')
		add(0,1LL);
	else add(bit[d1(m)]+1,1LL);
	tarx=tary=-1;
	for(int i=n-1;tarx==-1 && i>=0;i--)
		for(int j=m-1;tary==-1 && j>=0;j--)
			if(c[i][j]=='.'){ tarx=i;tary=j; }
	if(tarx==-1){ printf("0\n");return; }
	/* Core */
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			if(!i && !j)continue;
			now=pre;tot[now]=0;clear();
			if(c[i][j]=='*')
				dis(j);
			else pas(i,j);
		}
	/* Output */
	printf("%lld\n",ans);
}

int main(){
	for(int i=0;i<M;i++)bit[i]=1<<i;
	while(scanf("%d%d",&n,&m)!=EOF && n)
		work();
	return 0;
}

