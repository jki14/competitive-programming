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

#define src 801
#define des 802

#define food(x) (x+0)
#define peo0(x) (x+200)
#define peo1(x) (x+400)
#define drin(x) (x+600)

#define N 802
#define L 300


struct CNode{
	int v, i;
	CNode(int v, int i){
		this->v = v, this->i = i;
	}
};

inline int min(int a, int b){	return a<b?a:b; }

const int inf = 0x3fffffff;
const int maxn = 1000;
vector<CNode> a[maxn];
vector<int> flow;
vector<int> cap;
int n, m;
int cur[maxn], sumd[maxn], d[maxn], pre[maxn];

void AddEdge(int u, int v, int c){
	a[u].push_back(CNode(v, cap.size()));
	a[v].push_back(CNode(-u, cap.size()));
	cap.push_back(c);
	flow.push_back(0);
}

int SAP(int s, int t, int n){
	memset(sumd, 0, sizeof(sumd));
	memset(cur, 0, sizeof(cur));
	memset(d, 0, sizeof(d));
	sumd[0] = n;
	pre[s] = s;
	int ans = 0;
	int now = s;
	int modify = inf;
	while(d[s] < n){
		bool flag = false;
		if(now == s)
			modify = inf;
		for(int &j=cur[now]; j<(int)a[now].size(); ++j){
			int i = a[now][j].i;
			int v = a[now][j].v;
			if(v > 0 && d[now] == d[v]+1 && flow[i] < cap[i]){
				flag = true;
				pre[v] = now;
				now = v;
				modify = min(modify, cap[i]-flow[i]);
				break;
			}
			if(v < 0 && d[now] == d[-v]+1 && flow[i] > 0){
				flag = true;
				pre[-v] = now;
				now = -v;
				modify =min(modify, flow[i]);
				break;
			}
		}
		if(now == t){
			ans += modify;
			while(now != s){
				now = pre[now];
				if(a[now][cur[now]].v > 0)
					flow[a[now][cur[now]].i] += modify;
				else
					flow[a[now][cur[now]].i] -= modify;
			}
		}
		if(flag)
			continue;
		cur[now] = 0;
		int mind = n;
		for(int tt=0; tt<(int)a[now].size(); ++tt){
			int i = a[now][tt].i;
			int v = a[now][tt].v;
			if(v > 0 && d[v] < mind && flow[i] < cap[i])
				mind = d[v];
			if(v < 0 && d[-v] < mind && flow[i] > 0)
				mind = d[-v];
		}
		sumd[d[now]]--;
		if(sumd[d[now]] == 0)
			d[s] = n;
		sumd[d[now] = mind+1]++;
		now = pre[now];
	}
	return ans;
}


char sat[L];

int main(){int n,f,d;
	while(scanf("%d%d%d",&n,&f,&d)!=EOF){
		
		cap.clear();flow.clear();	
		for(int i=0;i<maxn;i++)a[i].clear();

		for(int i=1;i<=n;i++)AddEdge(peo0(i),peo1(i),1);

		for(int i=1;i<=f;i++){
			int val;scanf("%d",&val);
			AddEdge(src,food(i),val);
		}	
		for(int i=1;i<=d;i++){
			int val;scanf("%d",&val);
			AddEdge(drin(i),des,val);
		}

		for(int i=1;i<=n;i++){
			scanf("%s",sat);
			for(int j=1;j<=f;j++)
				if(sat[j-1]=='Y')AddEdge(food(j),peo0(i),1);
		}
		
		for(int i=1;i<=n;i++){
			scanf("%s",sat);
			for(int j=1;j<=d;j++)
				if(sat[j-1]=='Y')AddEdge(peo1(i),drin(j),1);
		}

		printf("%d\n",SAP(src,des,N));
	}

	return 0;
}

