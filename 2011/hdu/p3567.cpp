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
#include<set>
#include<map>
using namespace std;

#define len 10
#define maxk 410000
#define L 9

#define OPT 4

int dx[OPT]={ 3,-1,1,-3 };
char dc[OPT]={ 'd','l','r','u' };

char num[len]={ '0','1','2','3','4','5','6','7','8','9' };

int X,T;

int g[maxk][OPT];

int res[len][maxk],pnt[len][maxk];
char opt[len][maxk],optlist[maxk];

char state[len],dict[maxk][len],xdic[maxk];
int ista,xsta,k;

int mk[maxk],que[maxk];
int l,r;

char src[len],tar[len],ren[len];

map<int,int> m;
map<int,int>::iterator it;

void update(){
	state[xsta]=num[0];
	sscanf(state,"%d",&ista);
	state[xsta]='X';
}

void getsta(const int &k){
	for(int i=0;i<L;i++)state[i]=dict[k][i];
	xsta=xdic[k];
}

void putsta(const int &k){
	for(int i=0;i<L;i++)dict[k][i]=state[i];
	xdic[k]=xsta;
}

int able(const int &i){
	switch(i){
		case 0:
			return xsta<6;
		case 1:
			return xsta%3!=0;
		case 2:
			return xsta%3!=2;
		case 3:
			return xsta>2;
	}
	return 0;
}

void build(){
	int i,j;X=0;
	for(i=0;i<L;i++){
		if(i==X)
			state[i]=X;
		else if(i>X)
			state[i]=num[i];
		else state[i]=num[i+1];
	}state[L]=0;xsta=X;

	memset(g,0,sizeof(g));

	m.clear();m.insert(pair<int,int>(ista,k=1));
	//res[X][k]=pnt[X][k]=0;opt[X][k]=0;
	putsta(k);
	
	for(i=0;i<=k;i++){getsta(i);
		for(j=0;j<OPT;j++){
			if(!able(j))continue;

			swap(state[xsta],state[xsta+dx[j]]);xsta+=dx[j];update();
			it=m.find(ista);
			
			if(it==m.end()){
				m.insert(pair<int,int>(ista,++k));
				//res[X][k]=res[X][i]+1;pnt[X][k]=i;opt[X][k]=dc[j];
				putsta(k);

				g[i][j]=k;
			}else g[i][j]=(*it).second;

			swap(state[xsta],state[xsta-dx[j]]);xsta-=dx[j];
		}
	}
}

void init(){
	int i,j,u;
	
	for(i=0;i<L;i++){
		if(i==X)
			state[i]=X;
		else if(i>X)
			state[i]=num[i];
		else state[i]=num[i+1];
	}state[L]=0;xsta=X;

	update();it=m.find(ista);k=(*it).second;

	memset(mk,0,sizeof(mk));l=r=0;
	res[X][k]=pnt[X][k]=0;opt[X][k]=0;
	que[r++]=k;mk[k]=1;
	for(;l<r;l++){
		u=que[l];
		for(j=0;j<OPT;j++){if(!g[u][j] || mk[g[u][j]])continue;
			res[X][g[u][j]]=res[X][u]+1;
			pnt[X][g[u][j]]=u;
			opt[X][g[u][j]]=dc[j];
			
			mk[g[u][j]]=1;
			que[r++]=g[u][j];
		}
	}
}

void work(){
	int i,j=1;
	for(i=0;i<L;i++){
		if(src[i]=='X'){
			X=i;
			continue;
		}
		ren[src[i]-'0']=num[j];
		src[i]=num[j++];
	}
	for(i=0;i<L;i++){
		if(tar[i]=='X'){
			state[i]='X';xsta=i;
			continue;
		}
		state[i]=ren[tar[i]-'0'];
	}
	update();it=m.find(ista);k=(*it).second;
	printf("Case %d: %d\n",T,res[X][k]);
	for(i=k,r=0;pnt[X][i];i=pnt[X][i])
		optlist[++r]=opt[X][i];
	for(;r;r--)printf("%c",optlist[r]);
	printf("\n");
}

int main(){
	int t;scanf("%d",&t);
	build();
	for(X=0;X<L;X++)init();
	for(T=1;T<=t;T++){
		scanf("%s%s",src,tar);
		work();
	}
	return 0;
}

