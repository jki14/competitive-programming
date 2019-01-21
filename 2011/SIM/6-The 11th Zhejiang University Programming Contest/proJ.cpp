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

#define maxn 1100
#define maxm 11000

int n,res,rat;
int a[maxn],f[maxm];

void work(){
	int i,k;
	scanf("%d",&n);
	memset(f,0,sizeof(f));
	res=rat=0;
	for(i=0;i<n;i++){
		scanf("%d",&k);
		f[k]++;
		if(f[k]>rat || (f[k]==rat && k>res)){
			rat=f[k];
			res=k;
		}
	}
	printf("%d\n",res);
}

int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}

