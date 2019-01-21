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

#define NUM 11000

int n,m,T,ans;
int num1,num2;
int a[NUM],b[NUM];
int f[NUM],g[NUM];

int cmp(const int &x,const int &y){ return x>y; }

void work(){
	scanf("%d%d%d%d",&n,&m,&num1,&num2);
	if(n>m)swap(n,m);ans=0;
	for(int i=0;i<num1;i++)scanf("%d",&a[i]);
	for(int i=0;i<num2;i++)scanf("%d",&b[i]);
	sort(a,a+num1,cmp);sort(b,b+num2,cmp);
	f[0]=g[0]=0;
	for(int i=1;i<=num1;i++)f[i]=f[i-1]+a[i-1];
	for(int i=1;i<=num2;i++)g[i]=g[i-1]+b[i-1];
	int tail=min((n==2 && m%3==2)?n*m/3-1:n*m/3,num2);
	for(int y=0;y<=tail;y++){
		int x=min((n*m-y*3)>>1,num1);
		ans=max(ans,f[x]+g[y]);
	}
	printf("Case #%d: %d\n",T,ans);
}

int main(){
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++)work();
	return 0;
}

