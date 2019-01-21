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

#define N 1100
#define M 11000
#define K 2

#define pre now^1

const int m=10000;

int f[M],n;
int a[N],now=0;

void work(){
	/* Init */
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);f[0]=1;
	/* Core */
	for(int i=1;i<=n;i++){
		if(f[i-1]<a[i]-1){
			printf("%d\n",f[i-1]);
			return;
		}
		f[i]=f[i-1]+a[i];
	}
	printf("%d\n",f[n]);
}

int main(){
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}

