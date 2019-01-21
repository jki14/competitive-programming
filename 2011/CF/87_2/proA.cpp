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

#define N 1100

int n,ret,now;
int a[N],b[N];

void work(){
	ret=now=0;
	for(int i=0;i<n;i++){
		scanf("%d%d",&a[i],&b[i]);
		now-=a[i];now+=b[i];
		ret=max(ret,now);
	}
	/*ret=LONG_MAX;now=0;
	for(int i=0;i<n;i++){
		now+=b[i]-a[i];
		ret=min(ret,now);
	}*/
	printf("%d\n",ret);
}

int main(){
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}

