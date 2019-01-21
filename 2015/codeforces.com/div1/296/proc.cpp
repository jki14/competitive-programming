#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
using namespace std;

#define N 210000
#define M 510000

int n, m, a[N], ans, anx[M], any[M];
int nbs[N], nxt[M], dst[M], idx[M], enm;
int rou[N], cov[N], fat[N], vst[N], sta[N], top;

set<int> s[3];

static void mark(const int u, const int v){
	a[u]^=1; a[v]^=2;
	anx[ans]=u; any[ans]=v;
	ans++;
}

static void addedge(const int u, const int v, const int k){
	nxt[++enm]=nbs[u];nbs[u]=enm;dst[enm]=v;idx[enm]=k;
	nxt[++enm]=nbs[v];nbs[v]=enm;dst[enm]=u;idx[enm]=k;
}

static int set_pop(set<int> &s){
	set<int>::iterator it=s.begin();
	int ret=*it;
	s.erase(it);
	return ret;
}

static void build(const int u){
	vst[u]=1;sta[++top]=u;
	for(int i=nbs[u]; i; i=nxt[i]){int v=dst[i];
		if(vst[v])continue;
		rou[v]=idx[i];
		fat[v]=u;
		build(v);
	}
}

static void do_cov(){
	for(int i=top; sta[i]; i--){int u=sta[i];
		if(!cov[u])continue;
		swap(anx[rou[u]], any[rou[u]]);
		cov[fat[u]]^=1;
	}
}

int main(){
	while(scanf("%d%d", &n, &m)!=EOF){
		memset(nbs, 0, sizeof(nbs));enm=0;
		memset(a, 0, sizeof(a));ans=0;
		for(int i=0; i<3; i++)s[i].clear();
		for(int i=0; i<m; i++){
			int u,v;
			scanf("%d%d", &u, &v);
			u--; v--;
			mark(u, v);
			addedge(u, v, ans-1);
		}
		for(int u=0; u<n; u++){
			if(a[u])s[a[u]-1].insert(u);
		}
		memset(vst, 0, sizeof(vst));
		top=0;build(0);
		memset(cov, 0, sizeof(cov));
		while(s[2].size()>1){
			int x=set_pop(s[2]);
			int y=set_pop(s[2]);
			cov[x]^=1;
			cov[y]^=1;
		}
		for(int p=0; p<2; p++){int q=p^1;
			if(!s[2].empty() && s[p].size()>s[q].size()){
				int x=set_pop(s[2]);
				int y=set_pop(s[p]);
				cov[x]^=1;
				cov[y]^=1;s[q].insert(y);
			}
			while(s[p].size()>s[q].size()+2){
				int x=set_pop(s[p]);
				int y=set_pop(s[p]);
				cov[x]^=1;s[q].insert(x);
				cov[y]^=1;s[q].insert(y);
			}
		}
		for(set<int>::iterator it=s[2].begin(); it!=s[2].end(); it++)mark(*it, *it);
		while(!s[0].empty() && !s[1].empty()){
			int x=set_pop(s[0]);
			int y=set_pop(s[1]);
			mark(x, y);
		}
		while(!s[0].empty())mark(set_pop(s[0]), 0);
		while(!s[1].empty())mark(0, set_pop(s[1]));
		do_cov();
		printf("%d\n", ans);
		for(int i=0; i<ans; i++)printf("%d %d\n", anx[i]+1, any[i]+1);
	}
	return 0;
}
