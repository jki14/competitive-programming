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

typedef long long lld;

#define S 31000
#define K 1000

int f[S],a[S],s,x,y;
int list[S];

int gcd(int x,int y){ while(y){ int k=x%y;x=y;y=k; }	return x; }

void output(){
	int k=0;for(int i=y;i!=x;i=f[i])list[++k]=i;
	printf("%d",x);
	for(;k;k--){
		printf(" %d",list[k]);
	}
	printf("\n");
}

int main(){
	scanf("%d%d",&x,&y);
	memset(f,0,sizeof(f));
	f[x]=x;s=0;a[s++]=x;
	for(int i=0;i<s;i++){
		for(int k=1;k<a[i] && k<K;k++){
			if(((k*k)%(a[i]-k))==0){
				int oth=((k*k)/(a[i]-k))+k;
				if(oth<=0 || oth>=S)continue;
				if(f[oth])continue;
				f[oth]=a[i];a[s++]=oth;
				if(oth==y){ output();return 0; }
			}
		}
	}
	printf("0\n");
	return 0;
}
