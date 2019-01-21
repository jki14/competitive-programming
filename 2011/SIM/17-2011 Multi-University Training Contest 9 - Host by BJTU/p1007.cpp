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

#define N 11000
#define M 51000
#define K 2

int ev[M],next[M],nbs[N],ind[N],mk[N],num;
int lst[K][N],lstnum[K],cir[K][N],cirnum[K];

int n,m,T;

void AddEdge(const int &u,const int &v){

	//printf("addEdge(%d,%d)\n",u,v);

	ev[++num]=v;ind[v]++;
	next[num]=nbs[u];nbs[u]=num;
}

void getlst(const int &u,const int &len,const int &k){

	//printf("getlst(%d,%d,%d)\n",u,len,k);

	mk[u]=k;
	for(int i=nbs[u];i;i=next[i]){
		if(mk[ev[i]]==k)continue;
		getlst(ev[i],len+1,k);
		return;
	}
	lst[k][lstnum[k]++]=len;
}

void getcir(const int &u,const int &f,const int &len,const int &k){
	
	//printf("getcir(%d,%d,%d)\n",u,len,k);

	if(mk[u]==k){
		cir[k][cirnum[k]++]=len;
		return;
	}mk[u]=k;
	for(int i=nbs[u];i;i=next[i]){
		if(ev[i]==f)continue;
		getcir(ev[i],u,len+1,k);return;
	}
}

int equal(){
	//printf("cirnum[0]=%d cirnum[1]=%d lstnum[0]=%d lstnum[1]=%d\n",cirnum[0],cirnum[1],lstnum[0],lstnum[1]);
	if(cirnum[0]!=cirnum[1] || lstnum[0]!=lstnum[1])return 0;
	sort(cir[0],cir[0]+cirnum[0]);sort(cir[1],cir[1]+cirnum[1]);
	for(int i=0;i<cirnum[0];i++)
		if(cir[0][i]!=cir[1][i])return 0;
	sort(lst[0],lst[0]+lstnum[0]);sort(lst[1],lst[1]+lstnum[1]);
	for(int i=0;i<lstnum[1];i++)
		if(lst[0][i]!=lst[1][i])return 0;
	return 1;
}

void work(){
	memset(mk,0xff,sizeof(mk));
	for(int k=0;k<K;k++){
		memset(nbs,0,sizeof(nbs));memset(ind,0,sizeof(ind));num=0;
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++){
			int u,v;scanf("%d%d",&u,&v);
			AddEdge(u,v);AddEdge(v,u);
		}
		lstnum[k]=cirnum[k]=0;
		for(int i=1;i<=n;i++){
			if(mk[i]==k)continue;
			if(ind[i]<2)getlst(i,1,k);
		}
		for(int i=1;i<=n;i++){
			if(mk[i]==k)continue;
			getcir(i,0,0,k);
		}
	}
	if(equal())
		printf("Case #%d: YES\n",T);
	else printf("Case #%d: NO\n",T);
}

int main(){
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++)work();
	return 0;
}

