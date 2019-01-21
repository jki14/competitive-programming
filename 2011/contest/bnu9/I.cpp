#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

#define m 100000000
#define maxn 1000000

int n,f[maxn];

void zero(int x){
	int k=10000000;
	while(k && ((int)(x/k))==0){
		printf("0");k/=10;
	}
}

void work(){
	int i;
	scanf("%d",&n);
	f[0]=1;f[1]=9;
	for(i=2;i<=n;i++){
		f[i]=f[i-1]*9-f[i-2];
		f[i]%=m;
	}
	f[n]%=m;
	zero(f[n]);printf("%d\n",f[n]);
}

int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
