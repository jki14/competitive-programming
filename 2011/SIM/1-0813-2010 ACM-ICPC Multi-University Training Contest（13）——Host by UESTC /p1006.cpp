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

int T;

int n,m,k;
double sum;

void work(){
	int i;
	double d;sum=0.0;
	for(i=0;i<n;i++){
		scanf("%lf",&d);
		sum+=d;
	}
	sum*=((double)m)/((double)n);
	printf("Case %d: %.5f\n",T,sum);
}

int main(){
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++){
		scanf("%d%d%d",&n,&m,&k);
		work();
	}
	return 0;
}

