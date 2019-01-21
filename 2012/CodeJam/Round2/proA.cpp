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

#define N 11000

int n,d;
int p[N],len[N];
int r[N],pos;

inline int min(const int &x,const int &y){ return (x<y)?x:y; }

int main(){
	int T;scanf("%d",&T);
	for(int tim=1;tim<=T;tim++){printf("Case #%d: ",tim);
		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%d%d",&p[i],&len[i]);scanf("%d",&p[n]);
		memset(r,0,sizeof(r));pos=1;int init=min(p[0],len[0])+p[0];
		while(pos<=n && p[pos]<=init)r[pos++]=p[0];
		for(int i=1;i<n;i++){
			if(!r[i])continue;
			int lmt=min(p[i]-r[i],len[i])+p[i];

			//printf("for %d,%d r=%d lmt=%d\n",p[i],len[i],r[i],lmt);

			while(pos<=n && p[pos]<=lmt)r[pos++]=p[i];
		}
		if(r[n])
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
