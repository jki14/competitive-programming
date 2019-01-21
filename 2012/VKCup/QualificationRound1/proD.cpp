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

#define N 51000

int a[N],ans,path,n;

int max(const int &x,const int &y){ return (x>y)?x:y; }

int main(){
	while(scanf("%d",&n)!=EOF){ans=0;
		for(int i=0;i<n;i++){ scanf("%d",&a[i]);a[i+n]=a[i];ans+=a[i]; }
		for(int k=2;k*3<=n;k++){
			if(n%k!=0)continue;
			for(int s=0;s<n;s++){path=0;
				for(int i=s;i!=s+n;i+=k){
					path+=a[i];
				}
				ans=max(ans,path);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
