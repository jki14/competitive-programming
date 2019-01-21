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

int ans;
int n,a,b;

void work(){
	ans=0;
	for(int i=1;i<=n;i++)
		if(i-1>=a && n-i<=b)ans++;
	printf("%d\n",ans);
}

int main(){
	while(scanf("%d%d%d",&n,&a,&b)!=EOF)
		work();
	return 0;
}

