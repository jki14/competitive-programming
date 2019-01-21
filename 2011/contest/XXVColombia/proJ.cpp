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

#define N 110

const int low=LONG_MIN;

int n,ans;
int a[N],b[N],v[N];

void work(){
	
	for(int i=ans=0;i<n;i++){
		scanf("%d%d",&a[i],&b[i]);
		ans+=a[i];
	}a[n]=low;

	memset(v,0,sizeof(v));
	while(1){
		int top=n,sum=0;
		for(int i=0;i<n;i++){

			//printf("i=%d v=%d sum=%d a[top]=%d a[i]=%d\n",i,v[i],sum,a[top],a[i]);

			if(v[i]==0 && sum && a[top]<a[i])top=i;
			sum+=b[i];
		}

		//printf("top=%d\n",top);

		if(top==n)break;
		for(int i=top-1;i>=0;i--)if(b[i]){ b[i]--;break; }
		ans-=a[top]>>1;v[top]=1;
	}

	printf("%d\n",ans);
}

int main(){
	while(scanf("%d",&n)!=EOF && n)
		work();
	return 0;
}

