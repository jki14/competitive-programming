#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
#include <set>
using namespace std;

#define maxn 1100

int timer;
int n,ans;
int a[maxn],d[maxn];

int cmp(const int &x,const int &y){
	return (x>y)?1:0;
}

void work(){
	int i,j;scanf("%d",&n);ans=0;
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	for(i=0;i<n;i++)scanf("%d",&d[i]);
	sort(a,a+n,cmp);sort(d,d+n,cmp);
	for(i=0,j=0;i<n&&j<n;){
		while(a[i]<d[j] && j<n)j++;
		if(a[i]>=a[j]){
			ans++;i++;j++;
		}
	}
	printf("Case %d: %d\n",timer,i);
}

int main(){
	int t;scanf("%d",&t);
	for(timer=1;timer<=t;timer++)
		work();
	return 0;
}
