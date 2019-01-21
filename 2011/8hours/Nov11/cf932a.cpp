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

#define N 110

const double v = 50.0;

int n;
double x[N],y[N];
double k,ans;

double dist(const int &i,const int &j){
	return sqrt( (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) );
}

void work(){
	scanf("%lf",&k);ans=0.0;
	for(int i=0;i<n;i++){
		scanf("%lf%lf",&x[i],&y[i]);
		if(i)ans+=dist(i-1,i);
	}
	ans = ans / v * k;
	printf("%.10f\n",ans);
}

int main(){
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}
