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

#define N 1100
#define di ((double)i)

const double eps = 1e-8;

int n;
double p[N],t[N];
double ans1,ans2;
double tot,nec;

int main(){
	int T;scanf("%d",&T);
	while(T--){scanf("%d",&n);
		p[0]=t[0]=ans1=ans2=nec=tot=0.0;
		for(int i=1;i<=n;i++){ scanf("%lf",&p[i]);ans2+=p[i]; }ans2/=(double)n;
		for(int i=1;i<=n;i++){ scanf("%lf",&t[i]);ans1=max(ans1,t[i]-t[i-1]); }
		for(int i=1;i<n;i++){
			tot+=p[i];nec=max(nec,t[i]-t[i-1]);
			if(nec>t[i+1]-t[i]-eps)continue;
			double tmp=tot/di;
			if(tmp<ans2+eps && tmp>ans2-eps && nec<ans1){
				ans1=nec;ans2=tmp;
			}else if(tmp>ans2+eps){
				ans1=nec;ans2=tmp;
			}
		}
		printf("%.6f %.6f\n",ans1,ans2);
	}
	return 0;
}
