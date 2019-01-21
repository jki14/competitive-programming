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

#define S 600000
#define N 500
#define M 110000
#define L 11
#define R 5
#define C 27

char str[S][R],s[L],a[R];
int  sta[S],hig[S],bak[M];
int  ev[M],next[M],qnt[N];
int  nbs[N],pnt[M],n,m,num;
int  src,state,len;

void init(const int &k){
	if(k){

		//printf("state=%d\n",state);

		for(int i=0;i<k;i++)str[state][i]=a[i];
		str[state][k]=0;
	}
	if(k==R-1)return;
	for(a[k]='a';a[k]<='z';a[k]++){
		int path=a[k]-'a'+1;
		state=state*C+path;
		init(k+1);
		state=state/C;
	}
}

void AddEdge(const int &u,const int &v){
	++num;ev[num]=v;
	next[num]=nbs[u];
	nbs[u]=num;
}

void link(const int &k,const int &l){
	if(k){
		if(hig[state]<src){
			hig[state]=src;
			if(!sta[state]){
				sta[state]=++m;
				bak[m]=state;
			}
			AddEdge(src,sta[state]);
		}
	}
	if(k==R-1)return;
	for(int i=l;i<len;i++){
		int path=s[i]-'a'+1;
		state=state*C+path;
		link(k+1,i+1);
		state=state/C;
	}
}

int find(const int &u){
	if(hig[u]==src)return 0;hig[u]=src;
	for(int i=nbs[u];i;i=next[i]){
		int v=ev[i];
		if(!pnt[v] || find(pnt[v])){
			pnt[v]=u;qnt[u]=v;
			return 1;
		}
	}
	return 0;
}

void work(){
	memset(nbs,0,sizeof(nbs));num=0;
	
	memset(sta,0,sizeof(sta));m=0;
	memset(hig,0,sizeof(hig));

	for(int i=1;i<=n;i++){
		scanf("%s",s);len=strlen(s);
		src=i;link(0,0);
	}

	memset(hig,0,sizeof(hig));
	for(int u=1;u<=n;u++){
		src=u;
		if(!find(u)){
			printf("-1\n");
			return;
		}
	}

	for(int i=1;i<=n;i++){
		//printf("(id=%6d)",bak[qnt[i]]);
		printf("%s\n",str[bak[qnt[i]]]);
	}
}

int main(){
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	state=0;init(0);
	while(scanf("%d",&n)!=EOF)
		work();
	fclose(stdin);fclose(stdout);
	return 0;
}

