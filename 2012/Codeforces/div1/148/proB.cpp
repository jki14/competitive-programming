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

typedef long long lld;

#define N 110000

const int inf = LONG_MAX;

int ans,n,h,k;
int a[N],o[N],f[N];

int cmp(const int &i,const int &j){ return a[i]<a[j]; }

int call(const int &x){
	if(!x)return (a[o[n-1]]+a[o[n-2]])-(a[o[0]]+a[o[1]]);
	int top=max(a[o[n-1]]+a[o[n-2]],a[o[n-1]]+a[o[x-1]]+h);
	int bot=x>1?a[o[0]]+a[o[1]]:min(a[o[0]]+a[o[1]]+h,a[o[1]]+a[o[2]]);
	return top-bot;
}

int main(){
	while(scanf("%d%d",&n,&h)!=EOF){ans=inf;
		for(int i=0;i<n;i++){ o[i]=i;scanf("%d",&a[i]);f[i]=1; }
		sort(o,o+n,cmp);
		for(int i=0;i<n;i++){ int tmp=call(i);
			if(tmp<ans){
				ans=tmp;k=i;
			}	
		}
		for(int i=0;i<k;i++){
			f[o[i]]=2;
		}
		printf("%d\n",ans);
		for(int i=0;i<n;i++){
			if(i)printf(" ");
			printf("%d",f[i]);
		}
	}
	return 0;
}

