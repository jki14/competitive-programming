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

int T,n;
double a1,sum;

void work(){
	scanf("%d",&n);sum=0.0;
	for(int i=0;i<n;i++){
		double d;scanf("%lf",&d);
		if(!i)a1=d;sum+=d;
	}
	double ans=a1/sum;
	printf("Case %d: %.6f\n",T,ans);
}

int main(){
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++)work();
	return 0;
}

