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

#define maxn 11000

typedef long long lld;

int n,ans,l,r;
lld a[maxn],opt,k;
int que[maxn];

void work(){
	int i,path;ans=LONG_MAX;
	for(i=1;i<=n;i++){ scanf("%d",&path);a[i]=(lld)path; }
	l=r=0;opt=0LL;
	for(i=1;l<r || i<=n;){
		while(l<r && a[que[l]]-opt==0LL)l++;

		//printf("change l to be %d\n",l);

		while(i<=n && (l==r || a[que[r-1]]-opt<=a[i])){
			
			//printf("add a[%d]=%d\n",i,a[i]);
			
			a[i]+=opt;
			que[r++]=i++;
		}
		k=a[que[l]]-opt;
		if(i<=n && k>a[que[r-1]]-a[i])k=a[que[r-1]]-a[i];
		//k=min(a[que[l]]-opt,a[que[r-1]]-a[i]);
		opt+=k;
		if(ans>que[r-1]-que[l]+1)ans=que[r-1]-que[l]+1;
	}
	printf("%d\n",ans);
}

int main(){
	int t;scanf("%d",&t);
	while(t--){scanf("%d",&n);
		work();
	}
	return 0;
}

