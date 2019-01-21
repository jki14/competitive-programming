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
#include<list>
#include<bitset>
#include<set>
#include<map>
#include<functional>
#include<numeric>
#include<utility>
#include<iomanip>
using namespace std;

const double eps=1e-9;

int main(){
	int n,m,k;double ans,w;
	while(scanf("%d%lf%d",&n,&w,&k)!=EOF){n+=2;
		m=n-n/k;ans=w*((double)m)/2.0;
		ans=ans+0.005-eps;
		printf("%.2f\n",ans);
	}
	return 0;
}
