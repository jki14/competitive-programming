//============================================================================
// Name        : TarjanBridge
// Author      : J.Ki
// Version     : 1.00
// Copyright   : WangZhe (Chongqing University Computer College)
// Description : 无向图桥(割边)、例为BUPT197
//============================================================================

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

#define maxn 11000
#define maxm 1100000
#define maxlen 20

map<string,int> s;
map<string,int>::iterator it;

int n,m,p;
int eu[maxm],ev[maxm],next[maxm],rev[maxm],num;
int nbs[maxn],mk[maxn],low[maxn],d[maxn];
int bri[maxm],brinum,color,ti;

char cs1[maxlen],cs2[maxlen];
string s1,s2,as[maxn];

void AddEdge(const int &u,const int &v){
	num++;eu[num]=u;ev[num]=v;next[num]=nbs[u];nbs[u]=num;rev[num]=0;
	num++;eu[num]=v;ev[num]=u;next[num]=nbs[v];nbs[v]=num;rev[num]=1;
}

void TarjanBridge(const int &u,const int &p){
	int i,v,s=0;low[u]=d[u]=++ti;mk[u]=-color;
	for(i=nbs[u];i;i=next[i]){v=ev[i];
		if(v==p)continue;
		if(!mk[v]){TarjanBridge(v,u);s++;
			low[u]=min(low[u],low[v]);
			if(low[v]==d[v]){
				brinum++;
				bri[(rev[i]?i-1:i)]=1;
			}
		}else low[u]=min(low[u],d[v]);
	}
	mk[u]=color;
}

void MarkBridge(){
	memset(mk,0,sizeof(mk));
	color=ti=brinum=0;
	for(int i=1;i<=n;i++)if(!mk[i]){ ++color;TarjanBridge(i,0); }
}

void work(){
	int i,u,v;s.clear();p=0;
	memset(nbs,0,sizeof(nbs));num=0;
	for(i=1;i<=m;i++){
		scanf("%s%s",cs1,cs2);s1=cs1;s2=cs2;
		it=s.find(s1);if(it==s.end()){
			s.insert(pair<string,int>(s1,++p));
			as[p]=s1;
			u=p;
		}else u=(*it).second;
		it=s.find(s2);if(it==s.end()){
			s.insert(pair<string,int>(s2,++p));
			as[p]=s2;
			v=p;
		}else v=(*it).second;
		AddEdge(u,v);
	}
	memset(bri,0,sizeof(bri));
	MarkBridge();
	//cout<<"color="<<color<<endl;
	if(color>1){
		printf("0\n");
	}else{
		printf("%d\n",brinum);
		for(i=1;i<=num;i++){
			if(bri[i])
				printf("%s %s\n",as[eu[i]].c_str(),as[ev[i]].c_str());
		}
	}
}

int main(){
	int t;scanf("%d",&t);
	while(t--){scanf("%d%d",&n,&m);
		work();
	}
	return 0;
}
