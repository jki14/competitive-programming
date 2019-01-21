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

double n,p,ans;

const double eps= 1e-5;

void work(){
	scanf("%lf%lf",&n,&p);
	ans=0.0;
	for(double k=1.0;k+eps<n;k+=1.0){
		double res=(n*(n-1.0))/2.0/k/(n-k)/p;
		ans+=res;
	}
	printf("%.3f\n",ans);
}

int main(){
	int t;scanf("%d",&t);
	while(t--)
		work();
	return 0;
}

