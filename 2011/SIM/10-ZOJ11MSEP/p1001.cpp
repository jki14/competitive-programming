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
#define S 3000

int T;

int n,ret;
int prm[N],is[N],num;
int a[N];

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

void work(){T++;
	ret=0;
	for(int i=0;i<n;i++){a[i]=0;
		int val;scanf("%d",&val);
		for(int j=0;j<num && prm[j]*prm[j]<=val;j++){
			if(val==1)break;
			while(!(val%prm[j])){
				a[i]++;
				val/=prm[j];
			}
		}
		if(val>1)a[i]++;
		ret^=a[i];
	}
	printf("Test #%d: ",T);
	if(ret){
		printf("Alice ");
		for(int i=0;i<n;i++)if((ret^a[i])<=a[i]){ printf("%d\n",i+1);break; }
	}else printf("Bob\n");
}

int main(){T=0;getprm(S);
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}

