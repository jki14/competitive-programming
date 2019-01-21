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
using namespace std;

#define maxn 20010
#define clr(x) memset(x,0,sizeof(x));

int n,m,s;
vector<int> map[maxn];
vector<int> tree[maxn];
bool p[maxn];
int num[maxn];

int main(){
	while(scanf("%d%d%d",&n,&m,&s)!=EOF){
		int i,j;
		clr(p);clr(num);
		for(i=1;i<=n;i++){
			int x,y,z;
			scanf("%d%d",&x,&y);
			map[x].clear();
			p[x]=true;
			for(j=0;j<y;j++){
				scanf("%d",&z);
				map[x].push_back(z);
			}
		}

		for(i=1;i<=m;i++){
			scanf("%d",&num[i]);

		}
	}
	return 0;
}
