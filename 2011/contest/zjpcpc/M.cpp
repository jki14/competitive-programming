#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm> 
using namespace std;

#define maxn 510

int n;
double a[maxn],res;

void work(){
	scanf("%d",&n);
	int i;for(i=0;i<n;i++)scanf("%lf",&a[i]);
	sort(a,a+n);
	if((n&1)==1)
		res=a[n/2];
	else
		res=(a[n/2]+a[n/2-1])/2;
	printf("%.3lf\n",res);
}

int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
