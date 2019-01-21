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

#define N 11000

int a[N],n,t,l;
double ans;

int cmp(const int &x,const int &y){ return x>y; }

void work(){
	scanf("%d%d%d",&n,&t,&l);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	sort(a,a+n,cmp);
	int pos=0;ans=0.0;
	for(int i=0;i<n;i++){
		if(pos+a[i]*t>=l){
			ans += ((double)(l-pos))/((double)a[i]);
			printf("%.2f\n",ans);
			return;
		}
		pos += a[i]*t;ans += (double)t;
	}
	printf("-1\n");
}

int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}

