#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
using namespace std;

#define maxn 3000
#define maxm 41000
#define maxw 1100
#define limw 1000

int n,m,res;
int weap[maxw];
vector<int> head[maxw];
multimap<int,int> tail;
multimap<int,int>::iterator it;

void work(){
	int i,j,s,t;
	for(i=0;i<=limw;i++)head[i].clear();
	tail.clear();res=0;
	memset(weap,0,sizeof(weap));
	for(i=0;i<n;i++){
		scanf("%d%d",&s,&t);
		head[s].push_back(t);
	}
	for(i=0;i<m;i++){
		scanf("%d",&t);
		if(t>limw)continue;
		weap[t]++;
	}
	for(i=0;i<=limw;i++){
		for(it=tail.begin();it!=tail.end() && (*it).first<i;it=tail.begin())tail.erase(it);
		for(j=0;j<(int)head[i].size();j++)tail.insert(pair<int,int>(head[i][j],1));
		for(j=0;j<weap[i];j++){
			it=tail.begin();
			if(it!=tail.end()){
				res++;
				tail.erase(it);
			}
		}
	}
	printf("%d\n",res);
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF)work();
	return 0;
}

