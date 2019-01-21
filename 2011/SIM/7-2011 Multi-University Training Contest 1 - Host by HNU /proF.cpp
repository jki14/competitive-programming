#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<climits>
#include<algorithm>
#include<map>
using namespace std;

#define maxn 11000

int n;
int a[maxn];
int s[maxn];

void work(){
	int i,j,x;
	memset(s,0,sizeof(s));
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[a[i]]=i;
	}
	for(i=2;i<n;i++){
		if(i-1<n-i){
			for(j=1;j<i;j++){
				x=a[i]*2-a[j];
				if(x<=0 || x>n)continue;
				if(s[x]>i){
					printf("Y\n");
					return;
				}
			}
		}else{
			for(j=i+1;j<=n;j++){
				x=a[i]*2-a[j];
				if(x<=0 || x>n)continue;
				if(s[x]<i){
					printf("Y\n");
					return;
				}
			}
		}
	}
	printf("N\n");
}

int main(){
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		work();
	}
	return 0;
}
