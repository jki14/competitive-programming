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

int main(){
	int t;scanf("%d",&t);
	double m,k,ret;
	for(int T=1;T<=t;T++){
		scanf("%lf%lf",&m,&k);
		ret=1.0/(m*k+k+1);
		printf("Case #%d: %.8f\n",T,ret);
	}
	return 0;
}


