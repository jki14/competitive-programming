#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define maxn 1000

int n,m,res;
int a[maxn],b[maxn];

void work(){
	int i,k;res=0;
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	for(i=0;i<n;i++)scanf("%d",&b[i]);
	std::sort(a,a+n);
	std::sort(b,b+n);
	for(i=0;i<n;i++){
		k=a[i]+b[n-i-1];
		if(k>m)res+=k-m;
	}
	printf("%d\n",res);
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF)
		work();
}
