#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

#define maxn 100
#define maxl 200
#define u q[0]
int timer;
int n,m,e[maxn];
double g[maxn][maxn],d[maxn];
map<string,int> s;
char ssx[maxl],ssy[maxl];
bool v[maxn],vis[maxn];
string sx,sy;
vector<int> q;

bool spfa(const int s){
	int i;
	q.clear();
	memset(e,0,sizeof(e));
	memset(vis,0,sizeof(vis));
	memset(d,0,sizeof(d));
	d[s]=1;q.push_back(s);
	//cout<<"Add Path:"<<s<<endl;
	while(!q.empty()){
		vis[u]=false;//cout<<"the Path is "<<u<<" & dist="<<d[u]<<endl;
		for(i=1;i<=n;i++)if(g[u][i]>0){
			if(d[i]<d[u]*g[u][i]){
				d[i]=d[u]*g[u][i];
				//cout<<"Updata d["<<i<<"]="<<d[i]<<endl;
				if(!vis[i]){
					//cout<<"Add Path:"<<i<<endl;
					e[i]++;
					if(e[i]>n)return true;
					q.push_back(i);
					vis[i]=true;
				}
			}
		}
		q.erase(q.begin());
	}
	/*cout<<"the array d:";
	for(i=1;i<=n;i++)
		cout<<d[i]<<" ";
	cout<<endl;*/
	return false;
}

void doit(){
	int i;double dis;
	s.clear();
	memset(v,0,sizeof(v));
	for(i=1;i<=n;i++){
		scanf("%s",ssx);
		sx=ssx;
		s[sx]=i;
	}
	scanf("%d",&m);
	memset(g,0,sizeof(g));
	for(i=0;i<m;i++){
		scanf("%s%lf%s",ssx,&dis,ssy);
		sx=ssx;sy=ssy;
		if(g[s[sx]][s[sy]]<dis)
			g[s[sx]][s[sy]]=dis;
	}
	for(i=1;i<=n;i++)if(spfa(i)){
		printf("Case %d: Yes\n",timer++);
		return;
	}
	printf("Case %d: No\n",timer++);
}

int main(){
	timer=1;
	while(scanf("%d",&n) && n!=0)doit();
	return 0;
}
