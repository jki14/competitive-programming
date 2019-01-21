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

#define maxn 11000
#define maxm 1100000
#define K 15
#define C 2

struct Edge{
	int u,v;
	Edge(){}
	Edge(const int &x,const int &y){
		u=x;v=y;
		if(u>v)swap(u,v);
	}
	bool operator < (const Edge &a)const {
		if(a.u!=u)return a.u<u;
		return a.v<v;
	}
};

const int sprm[K]={ 9973,7873,8699,7717,7589,7193,8581,9883,9767,7027,9629,8963,8821,9473,8429 };

const int moudel=100007;

Edge e;
set<Edge> s;
set<Edge>::iterator it;

int T;

int n,m,bn,bm,num;
int ev[C][maxm],next[C][maxm],nbs[C][maxn],val[C][maxn],hash[C][maxn];
//int mk[maxm];

void getgraph(const int &m,const int &c){num=0;s.clear();
	int i,u,v;
	for(i=0;i<m;i++){
		scanf("%d%d",&u,&v);u--;v--;
		
		e=Edge(u,v);it=s.find(e);if(it!=s.end())continue;
		s.insert(e);
		
		num++;ev[c][num]=v;
		next[c][num]=nbs[c][u];
		nbs[c][u]=num;

		num++;ev[c][num]=u;
		next[c][num]=nbs[c][v];
		nbs[c][v]=num;
	}
}

void work(){
	int i,u,v,k,c;

	memset(nbs,0,sizeof(nbs));
	scanf("%d%d",&n,&m);getgraph(m,0);
	scanf("%d%d",&bn,&bm);getgraph(bm,1);

	if(bn!=n){
		printf("Case #%d: NO\n",T);
		return;
	}

	memset(val,1,sizeof(val));
	for(k=0;k<K;k++){
		for(c=0;c<C;c++){
			//memset(mk,0x7f,sizeof(mk));
			for(u=0;u<n;u++){hash[c][u]=(val[c][u]*sprm[k])%moudel;//mk[u]=u;
				for(i=nbs[c][u];i;i=next[c][i]){v=ev[c][i];
					//if(mk[v]==u)continue;mk[v]=u;
					hash[c][u]=(hash[c][u]+val[c][v]*sprm[k])%moudel;
				}
			}
			memcpy(val[c],hash[c],sizeof(hash[c]));
			sort(hash[c],hash[c]+n);
		}
		for(i=0;i<n;i++)if(hash[0][i]!=hash[1][i]){
			printf("Case #%d: NO\n",T);
			return;
		}
	}
	printf("Case #%d: YES\n",T);
}

int main(){
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++)work();
	return 0;
}

