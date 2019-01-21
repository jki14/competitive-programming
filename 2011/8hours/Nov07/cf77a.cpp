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

#define N 50
#define M 7
#define K 3

const int inf = 0x7fffffff;

int u[N],v[N],n;
int f[K],val[K];
int g[M],ans1,ans2;

int track[N][N];

string nam1,nam2,like;
map<string, int> s;
map<string, int>::iterator it;
void build(){
	s.clear();
	s.insert(pair<string,int>("Anka",0));
	s.insert(pair<string,int>("Chapay",1));
	s.insert(pair<string,int>("Cleo",2));
	s.insert(pair<string,int>("Troll",3));
	s.insert(pair<string,int>("Dracul",4));
	s.insert(pair<string,int>("Snowy",5));
	s.insert(pair<string,int>("Hexadecimal",6));
}

void dfs(const int &k){
	if(k==M){
		int low,hig;low=inf;hig=-inf;
		for(int i=0;i<K;i++){
			if(f[i]==0)return;
			low=min(low,val[i]/f[i]);
			hig=max(hig,val[i]/f[i]);
		}
		int tmp1=hig-low,tmp2=0;
		for(int i=0;i<n;i++)
			if(g[u[i]]==g[v[i]])tmp2++;
		if(tmp1<ans1 || (tmp1==ans1 && tmp2>ans2)){
			ans1=tmp1;ans2=tmp2;
		}
		return;
	}
	for(g[k]=0;g[k]<K;g[k]++){
		f[g[k]]++;
		dfs(k+1);
		f[g[k]]--;
	}
}

void work(){
	memset(track,0,sizeof(track));
	for(int i=0;i<n;i++){
		cin>>nam1>>like>>nam2;
		it=s.find(nam1);if(it==s.end())while(1);
		u[i]=(*it).second;
		it=s.find(nam2);if(it==s.end())while(1);
		v[i]=(*it).second;
		if(track[u[i]][v[i]])while(1);
		track[u[i]][v[i]]=1;
	}
	for(int i=0;i<K;i++)scanf("%d",&val[i]);
	ans1=inf;ans2=-inf;
	memset(f,0,sizeof(f));
	dfs(0);
	printf("%d %d\n",ans1,ans2);
}

int main(){
	build();//cout<<inf<<endl;
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}

