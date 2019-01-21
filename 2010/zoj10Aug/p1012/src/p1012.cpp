#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

const int maxn=1100;

int n,a[maxn],b[maxn],r[maxn];

void doit(){
	int i,pre=0;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(i=n;i>0;i--){
		pre+=a[i];
		if(pre>b[i]){
			pre-=b[i];
			r[i]=b[i];
		}
		else{
			r[i]=pre;
			pre=0;
		}
	}
	if(pre)
		printf("Myon\n");
	else{
		for(i=1;i<n;i++)
			printf("%d ",r[i]);
		printf("%d\n",r[n]);
	}
}

int main(){
	while(scanf("%d",&n)!=EOF)doit();
	return 0;
}
