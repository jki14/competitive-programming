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

const double eps=1e-8;

double a[N],b[N];
int ans[N],vis[N];

int main(){
	int T;scanf("%d",&T);
	for(int ti=1;ti<=T;ti++){
		printf("Case #%d:",ti);
		int n;scanf("%d",&n);
		for(int i=0;i<n;i++){ scanf("%lf",&a[i]);}
		for(int i=0;i<n;i++){ scanf("%lf",&b[i]);b[i]=(b[i]/100.0)+1.0; }
		double val=0.0;memset(vis,0x3f,sizeof(vis));
		for(int i=0;i<n;i++){
			int j=0;while(vis[j]<i)j++;
			double newval=(val+a[j])*b[j];ans[i]=j;
			for(j++;j<n;j++){if(vis[j]<i)continue;
				if((val+a[j])*b[j]<newval-eps){
					newval=(val+a[j])*b[j];
					ans[i]=j;
				}
			}
			vis[ans[i]]=i;val=newval;
		}
		for(int i=0;i<n;i++)printf(" %d",ans[i]);
		printf("\n");
	}
	return 0;
}
