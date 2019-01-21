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
#include<set>
#include<map>
using namespace std;

#define N 110000
#define M 110000

typedef long long lld;

int T;

lld a[N],b[N];
lld ans,now,sum;

int n,m;

void work(){
	scanf("%d",&n);a[0]=0LL;
	for(int i=1;i<n;i++){
		int k;scanf("%d",&k);
		a[i]=a[i-1]+(lld)k;
	}

	memset(b,0,sizeof(b));
	scanf("%d",&m);sum=now=0LL;
	for(int i=0;i<m;i++){
		int k;scanf("%d",&k);
		b[k]++;sum++;
	}

	for(int i=0;i<n;i++){
		now+=b[i];
		if((now<<1)>=sum){
			ans=0LL;//printf("i=%d\n",i);
			for(int j=0;j<n;j++)ans+=b[j]*(a[j]>a[i]?a[j]-a[i]:a[i]-a[j]);
			if(i){int k=i-1;
				lld path=0LL;
				for(int j=0;j<n;j++)path+=b[j]*(a[j]>a[k]?a[j]-a[k]:a[k]-a[j]);
				ans=min(ans,path);
			}
			/*if(i+1<n){int k=i+1;
				lld path=0LL;
				for(int j=0;j<n;j++)path+=b[j]*(a[j]>a[k]?a[j]-a[k]:a[k]-a[j]);
				ans=min(ans,path);
			}*/
			printf("Case #%d: ",T);
			cout<<ans<<endl;
			return ;
		}
	}
}

int main(){
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++)work();
	return 0;	
}

