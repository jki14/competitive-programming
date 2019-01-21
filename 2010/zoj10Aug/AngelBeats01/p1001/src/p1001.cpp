#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;

#define maxn 1000
#define maxm 1000

#define p re[i][k]
#define q i

int timer;

map<string,int> ss;
map<string,int> cs;
map<int,int> ts;
map<string,int>::iterator it;
map<int,int>::iterator jt;

vector<int> re[maxm];

string s,_s;
char str[maxn];

int n,m,r,res,tt;
int vis[maxn][maxm],f[maxm],c[maxm];

int st[maxn],ct[maxm];

void work(){
	int i,k,u,v;res=0;tt=0;
	ss.clear();cs.clear();ts.clear();
	memset(vis,0,sizeof(vis));
	memset(ct,0,sizeof(ct));
	memset(st,0,sizeof(st));
	memset(f,0,sizeof(f));
	for(i=1;i<=n;i++){
		scanf("%s",str);s=str;ss.insert(pair<string,int>(s,i));
	}
	for(i=1;i<=m;i++){
		scanf("%s%d%d",str,&c[i],&k);s=str;
		while(k--){
			scanf("%d",&u);
			jt=ts.find(u);
			if(jt==ts.end())ts.insert(pair<int,int>(u,tt++));
			ct[i]^=(1<<ts[u]);
		}
		cs.insert(pair<string,int>(s,i));re[i].clear();
	}
	for(i=0;i<r;i++){
		scanf("%s",str);s=str;u=ss[s];
		scanf("%s",str);s=str;v=cs[s];
		re[v].push_back(u);
	}
	for(i=1;i<=m;i++){
		for(k=0;k<(int)re[i].size();k++)
			if((st[p]&ct[q])==0 && f[q]<c[q] && !vis[p][q]){
				res++;
				st[p]^=ct[q];f[q]++;vis[p][q]=1;
			}
	}
	printf("Case %d: %d\n",timer++,res);
}

int main(){
	timer=1;
	while(scanf("%d%d%d",&n,&m,&r)!=EOF)
		work();
	return 0;
}
