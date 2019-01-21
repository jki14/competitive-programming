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
#include<list>
#include<bitset>
#include<set>
#include<map>
#include<functional>
#include<numeric>
#include<utility>
#include<iomanip>
using namespace std;

#define N 1100

int n,m,ans,now,top;
int d[N],s[N];

int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=1;i<=n;i++)scanf("%d",&d[i]);
		for(int i=1;i<=n;i++)scanf("%d",&s[i]);
		ans=0;now=top=s[1];
		for(int i=1;i<=n;i++){
			while(now<d[i]){ now+=top;ans+=m; }
			now+=s[i+1]-d[i];ans+=d[i];top=max(top,s[i+1]);
		}
		printf("%d\n",ans);
	}
	return 0;
}

