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

#define N 13
#define S 4100

int a[N],b[N],bit[N],n;
double f[S];

void build(){
	for(int i=0;i<N;i++)bit[i]=1<<i;
}

void work(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&b[i]);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	f[0]=0.0;
	for(int sta=1;sta<bit[n];sta++){
		f[sta]=0.0;int k=0;double inc;
		for(int i=0;i<n;i++)if(bit[i]&sta)k++;
		for(int i=0;i<n;i++){
			if(!(bit[i]&sta))continue;
			if(a[k-1]>b[i])
				inc=3.0;
			else inc=0.0;
			f[sta]+=(f[sta^bit[i]]+inc)/k;
		}
	}
	printf("%.6f\n",f[bit[n]-1]);
}

int main(){
	build();
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}

