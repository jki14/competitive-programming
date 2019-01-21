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

#define N 110000
#define M 3000
#define S 3100

int T;

int n,ret;
int a[N];
int prm[S],is[S],num;

void getprm(const int &n){num=0;
	int i,j,d;
	int e=(int)(sqrt((double)n)+1.0);

	memset(is,0x7f,sizeof(is));
	prm[num++]=2;is[0]=is[1]=0;

	for(i=4;i<=n;i+=2)is[i]=0;
	for(i=3;i<e;i+=2)if(is[i]){
		prm[num++]=i;d=i<<1;
		for(j=i*i;j<=n;j+=d)is[j]=0;
	}

	for(;i<=n;i+=2)if(is[i])prm[num++]=i;
}

int getans(){
	for(int i=0;i<n;i++){
		if((ret^a[i])<=a[i])return i+1;
	}
	return -1;
}

void work(){T++;
	int i,j,val;

	memset(a,0,sizeof(a));

	for(i=0;i<n;i++){
		scanf("%d",&val);
		for(j=0;j<num && prm[j]*prm[j]<=val;j++){
			if(val==1)break;
			while(!(val % prm[j])){
				a[i]++;
				val/=prm[j];
			}
		}
		if(val>1)a[i]++;
	}

	printf("Test #%d: ",T);
	for(i=ret=0;i<n;i++)ret^=a[i];
	if(ret){
		printf("Alice %d\n",getans());
	}else printf("Bob\n");
}

int main(){T=0;
	getprm(M);
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}

