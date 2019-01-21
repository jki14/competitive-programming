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

#define maxn 1000
#define maxm maxn

#define slen 1000

char cstr[slen];
string str;
map<string,int>stu,cla;
map<int,int> stuT[maxn],claT[maxm];
map<int,int>::iterator it;
map<int,int>::iterator jt;
vector<int> claReq[maxn];

int n,m,req,timer;
int claC[maxm],claS[maxm],mk[maxn][maxm];

int Tpick(int u,int v){
	for(it=claT[v].begin();it!=claT[v].end();it++){
		jt=stuT[u].find((*it).first);if(jt!=stuT[u].end())return 0;
	}
	for(it=claT[v].begin();it!=claT[v].end();it++)
		stuT[u].insert(pair<int,int>((*it).first,1));
	return 1;
}

void work(){
	int i,j,k,u,v,res=0;
	stu.clear();cla.clear();
	memset(mk,0,sizeof(mk));memset(claS,0,sizeof(claS));
	for(i=1;i<=n;i++){
		scanf("%s",cstr);str=cstr;stu.insert(pair<string,int>(str,i));stuT[i].clear();
	}
	for(i=1;i<=m;i++){
		scanf("%s",cstr);str=cstr;cla.insert(pair<string,int>(str,i));
		claT[i].clear();claReq[i].clear();
		scanf("%d",&claC[i]);scanf("%d",&k);while(k--){
			scanf("%d",&j);claT[i].insert(pair<int,int>(j,1));
		}
	}
	while(req--){
		scanf("%s",cstr);str=cstr;u=stu[str];
		scanf("%s",cstr);str=cstr;v=cla[str];
		if(!u || !v)continue;
		claReq[v].push_back(u);
	}
	for(v=1;v<=m;v++)for(i=0;i<(int)claReq[v].size();i++){u=claReq[v][i];
			if(mk[u][v])continue;
			if(claS[v]>=claC[v])continue;
			if(!Tpick(u,v))continue;
			claS[v]++;mk[u][v]=1;res++;
	}
	printf("Case %d: %d\n",timer,res);
}

int main(){
	for(timer=0;scanf("%d%d%d",&n,&m,&req)!=EOF;work())timer++;
	return 0;
}
