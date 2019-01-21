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

typedef long long lld;

const int m=40;

int T;

lld a[m+1];
lld n;

void work(){
	//scanf("%lld",&n);
	cin>>n;
	printf("Case #%d: ",T);
	for(int i=0;i<=m;i++){
		if(n+1LL==a[i]){
			for(lld a=2LL;a*a<=n;a++){
				if(!(n%a)){
					printf("No\n");
					return;
				}
			}			
			printf("Yes\n");
			return;
		}
	}
	printf("No\n");
}

int main(){
	int t;scanf("%d",&t);
	for(int i=0;i<=m;i++){ a[i]=1LL<<i; }
	for(T=1;T<=t;T++)work();
	return 0;
}

