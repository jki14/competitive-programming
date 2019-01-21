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

int n,a[N],b[N],c[N],id[N];

int cmp(const int &i,const int &j){ return (b[i]!=b[j])?(b[i]>b[j]):(c[i]<c[j]); }

int main(){
	int T;scanf("%d",&T);
	for(int ti=1;ti<=T;ti++){
		printf("Case #%d:",ti);
		scanf("%d",&n);
		for(int i=0;i<n;i++)c[i]=id[i]=i;
		for(int i=0;i<n;i++)scanf("%d",&a[i]);
		for(int i=0;i<n;i++)scanf("%d",&b[i]);
		sort(id,id+n,cmp);
		for(int i=0;i<n;i++)printf(" %d",c[id[i]]);
		printf("\n");
	}
	return 0;
}
