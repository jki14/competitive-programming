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

#define X 4100
#define K 1100

typedef long long lld;

struct state{
	int x,y;
	bool operator < ( const state &a ) const {
		if(x!=a.x)return x<a.x;
		return y<a.y;
	}
};

map<int ,int> sx,sy;
map<int ,int>::iterator it;

set<state> wall;
set<state>::iterator pt;
queue<state> que;
state sta;

int T;

int n,m,k;
int xs[K],ys[K],xt[K],yt[K];
int tx[X],ty[X];
int x,y;

lld ans;

void work(){T++;
	sx.clear();sy.clear();wall.clear();ans=((lld)n)*((lld)m);
	sx.insert(pair<int,int>(0,0));sx.insert(pair<int,int>(n-1,0));
	sy.insert(pair<int,int>(0,0));sy.insert(pair<int,int>(m-1,0));

	for(int i=0;i<k;i++){
		scanf("%d%d%d%d",&xs[i],&ys[i],&xt[i],&yt[i]);
		sx.insert(pair<int,int>(xs[i],0));if(xs[i]-1>0)sx.insert(pair<int,int>(xs[i]-1,0));
		sx.insert(pair<int,int>(xt[i],0));if(xt[i]+1<n)sx.insert(pair<int,int>(xt[i]+1,0));
		sy.insert(pair<int,int>(ys[i],0));if(ys[i]-1>0)sy.insert(pair<int,int>(ys[i]-1,0));
		sy.insert(pair<int,int>(yt[i],0));if(yt[i]+1<m)sy.insert(pair<int,int>(yt[i]+1,0));
	}

	x=y=0;
	for(it=sx.begin();it!=sx.end();it++){
		(*it).second=++x;
		tx[x]=(*it).first;
	}tx[x+1]=tx[x]+1;
	for(it=sy.begin();it!=sy.end();it++){
		(*it).second=++y;
		ty[y]=(*it).first;
	}ty[y+1]=ty[y]+1;

	//build wall
	for(int i=0;i<k;i++){
		xs[i]=sx[xs[i]];ys[i]=sy[ys[i]];xt[i]=sx[xt[i]];yt[i]=sy[yt[i]];
		sta.y=ys[i];
		for(sta.x=xs[i];sta.x<=xt[i];sta.x++){
			ans = ans - ((lld)tx[sta.x+1]-tx[sta.x])*((lld)ty[sta.y+1]-ty[sta.y]);
			wall.insert(sta);
		}
	}
	
	//debug
	/*for(sta.y=y;sta.y>=1;sta.y--){
		for(sta.x=1;sta.x<=x;sta.x++){
			pt=wall.find(sta);
			if(pt==wall.end())
				printf("O");
			else
				printf("X");
		}
		printf("\n");
	}*/

	//init que
	while(!que.empty())que.pop();
	sta.x=sx[n-1];sta.y=sy[m-1];
	pt=wall.find(sta);
	if(pt==wall.end()){
		que.push(sta);wall.insert(sta);
		for(;!que.empty();que.pop()){
			sta=que.front();
			ans = ans - ((lld)tx[sta.x+1]-tx[sta.x])*((lld)ty[sta.y+1]-ty[sta.y]);
			
			sta.x--;
			if(sta.x>0){
				pt=wall.find(sta);
				if(pt==wall.end()){
					que.push(sta);
					wall.insert(sta);
				}
			}
			sta.x++;

			sta.y--;
			if(sta.y>0){
				pt=wall.find(sta);
				if(pt==wall.end()){
					que.push(sta);
					wall.insert(sta);
				}
			}
			sta.y++;
		}
	}
	
	//print-out
	printf("Case %d: %lld\n",T,ans);
}

int main(){T=0;
	while(scanf("%d%d%d",&m,&n,&k)!=EOF && (n || m || k))
		work();
	return 0;
}

