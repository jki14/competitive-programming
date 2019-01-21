#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define maxn 110

int a[maxn];
int n,m,res;

void work(){
	int i,k;for(i=0;i<n;i++)scanf("%d",&a[i]);
	sort(a,a+n);for(k=res=0;k+m<=n;){
		while(k+m<=n && a[k]==0)k++;if(k+m>n)break;
		res+=a[k];for(i=k+m-1;i>=k;i--)a[i]-=a[k];
	}
	printf("%d\n",res);
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF)work();
	return 0;
}
