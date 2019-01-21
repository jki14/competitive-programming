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

int n,p;
int a[N],id[N],r[N];

int cmp(const int &i,const int &j){
	if(a[i]!=a[j])return a[i]<a[j];
	return i>j;
}

void work(){
	int I,i;
	scanf("%d%d",&p,&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		id[i]=i;
	}
	sort(id,id+n,cmp);
	for(I=0;I<n;I++){i=id[I];

		//printf("a[?]=%d  ",a[i]);

		if(a[i] < p/(n-I)){
			r[i]=a[i];
		}else	r[i]=p/(n-I);

		//printf("r[?]=%d\n",r[i]);

		p-=r[i];
	}
	if(p)
		printf("IMPOSSIBLE");
	else	for(i=0;i<n;i++){
		if(i)printf(" ");
		printf("%d",r[i]);
	}
	printf("\n");
}

int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}

