#include<iostream>
#include<sstream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<ctime>
#include<climits>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
using namespace std;

#define maxn 30
#define maxm 30
#define maxl 10

#define P tmp
#define PX tmp.first
#define PY tmp.second

#define headX a[L-1].first
#define headY a[L-1].second

#define X a[i].first
#define Y a[i].second

#define xx X+dx[k]
#define yy Y+dy[k]

typedef pair<int,int> PII;

const int dx[4]={ -1,0,1,0 };
const int dy[4]={ 0,1,0,-1 };

map<string,int> mk;
map<string,int>::iterator it;
char stmp[10];
string t;

int T;

int n,m,L,K,res;
int vis[maxn][maxn],rock[maxn][maxm];
vector<PII> a,b;
vector< vector<PII> > q;
vector<int> r;

PII tmp;

void work(){
	int i,k,x,y;
	memset(rock,0,sizeof(rock));
	mk.clear();
	a.clear();q.clear();r.clear();res=0;
	for(i=0;i<L;i++){
		scanf("%d%d",&x,&y);
		PX=x;PY=y;
		a.push_back(P);
	}
	for(i=0;i<=n+1;i++)rock[i][0]=rock[i][m+1]=1;
	for(i=0;i<=m+1;i++)rock[0][i]=rock[n+1][i]=1;
	scanf("%d",&K);
	while(K--){ scanf("%d%d",&x,&y);rock[x][y]=1; }
	reverse(a.begin(),a.end());
	q.push_back(a);r.push_back(0);
	t.clear();
	for(i=0;i<L;i++){
		sprintf(stmp,"(%d,%d)",X,Y);
		t=t+stmp;
	}i--;
	mk.insert(pair<string,int>(t,0));
	while(q.size()){a=q[0];q.erase(q.begin());res=r[0];r.erase(r.begin());
		if(headX==1 && headY==1){
			printf("Case %d: %d\n",T,res);
			return;
		}
		memcpy(vis,rock,sizeof(rock));
		for(i=0;i<L;i++)vis[X][Y]=1;i--;
		for(k=0;k<4;k++){
			if(vis[xx][yy])continue;
			b=a;PX=xx;PY=yy;
			b.erase(b.begin());b.push_back(P);
			t.clear();
			for(i=0;i<L;i++){
				sprintf(stmp,"(%d,%d)",b[i].first,b[i].second);
				t=t+stmp;
			}i--;
			it=mk.find(t);
			if(it!=mk.end())continue;
			q.push_back(b);r.push_back(res+1);
			mk.insert(pair<string,int>(t,res+1));
		}
	}
	printf("Case %d: -1\n",T);
}

int main(){
	for(T=1;scanf("%d%d%d",&n,&m,&L)!=EOF && !(n==0 && m==0 && L==0);T++)work();
	return 0;
}

