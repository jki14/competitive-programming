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

#define N 12
#define L 10
#define K 2

#define pre now^1

typedef long long lld;

const lld modulo=1000000007;

struct gsta{
	int top,bot,rig;
	bool operator < (const gsta &a) const{
		if(a.top!=top)return a.top<top;
		if(a.bot!=bot)return a.bot<bot;
		return a.rig<rig;
	}
}gs0,gs1;

map<gsta, lld> g[K];
map<gsta, lld>::iterator git,git2;

map<int , lld> f[K];
map<int , lld>::iterator fit,fit2;

int T;

int n,m,k,ans;
int a[N][N][L],dbit[N];

char c[N][N][L];

int c2i(const char &c){
	switch(c){
		case 'C': return 0;
		case 'R': return 1;
		case 'F': return 2;
	}
	return -1;
}

void init(){
	for(int i=0;i<N;i++){
		dbit[i]=i<<1;
	}
}

void getg(const int &x){k=0;
	g[0].clear();g[1].clear();

	/* head */
	for(int d=0;d<4;d++){
		gs0.top=a[x][0][(0+d)%4];
		gs0.bot=a[x][0][(2+d)%4];
		gs0.rig=a[x][0][(1+d)%4];
		git=g[k].find(gs0);
		if(git==g[k].end()){
			g[k].insert(pair<gsta,lld>(gs0,1LL));
		}else (*git).second=((*git).second+1LL)%modulo;
	}

	/* body */
	for(int i=1;i<m;i++){k^=1;
		g[k].clear();
		for(git=g[k^1].begin();git!=g[k^1].end();git++){
			gs0=(*git).first;lld num=(*git).second;
			for(int d=0;d<4;d++){
				if(a[x][i][(3+d)%4]!=gs0.rig)continue;
				gs1.top=gs0.top|(a[x][i][(0+d)%4]<<dbit[i]);
				gs1.bot=gs0.bot|(a[x][i][(2+d)%4]<<dbit[i]);
				gs1.rig=a[x][i][(1+d)%4];
				
				git2=g[k].find(gs1);
				if(git2==g[k].end()){
					g[k].insert(pair<gsta,lld>(gs1,num));
				}else (*git2).second=((*git2).second+num)%modulo;
			}
		}
	}

	/* tail */
}

void work(){
	scanf("%d%d",&n,&m);

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			scanf("%s",c[i][j]);
			for(int p=0;p<4;p++)
				a[i][j][p]=c2i(c[i][j][p]);
		}

	f[0].clear();f[1].clear();
	int now=0;

	/* head */

	//printf("For floor 0:\n");

	getg(0);for(git=g[k].begin();git!=g[k].end();git++){
		int sta=(*git).first.bot;
		lld num=(*git).second;

		//printf("	%d~%lld\n",sta,num);

		fit=f[now].find(sta);
		if(fit==f[now].end()){
			f[now].insert(pair<int,lld>(sta,num));
		}else (*fit).second=((*fit).second+num)%modulo;
	}

	/* body */
	for(int i=1;i<n;i++){
		now=pre;getg(i);f[now].clear();
		for(fit=f[pre].begin();fit!=f[pre].end();fit++){
			int sta=(*fit).first;
			lld num=(*fit).second;
			for(git=g[k].begin();git!=g[k].end();git++){
				if(sta!=(*git).first.top)continue;
				int newsta=(*git).first.bot;
				lld addnum=num*(*git).second%modulo;
				fit2=f[now].find(newsta);
				if(fit2==f[now].end()){
					f[now].insert(pair<int,lld>(newsta,addnum));
				}else (*fit2).second=((*fit2).second+addnum)%modulo;
			}
		}
	}

	/* tail */
	lld tmp=0LL;
	for(fit=f[now].begin();fit!=f[now].end();fit++){
		tmp=(tmp+(*fit).second)%modulo;
	}
	tmp=(tmp%modulo+modulo)%modulo;
	ans=(int)tmp;

	printf("Case %d: %d\n",T,ans);
}

int main(){
	init();
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++)work();
	return 0;
}


