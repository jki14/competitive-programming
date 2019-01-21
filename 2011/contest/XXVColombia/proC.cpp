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

#define N 110
#define L 20
#define K 1100000

int n,m;
int bit[L];
int a[N],f[K];
int que[K],head,tail;

void init(){
	for(int i=0;i<L;i++)bit[i]=1<<i;
}

void work(){
	memset(a,0,sizeof(a));

	for(int i=0;i<n;i++){
		int k;scanf("%d",&k);
		for(int j=0;j<k;j++){
			int t;scanf("%d",&t);
			a[i]|=bit[t-1];
		}
	}

	memset(f,0x3f,sizeof(f));f[0]=0;
	head=tail=0;que[tail++]=0;
	for(;head<tail;head++){
		int sta=que[head];
		for(int i=0;i<n;i++){
			int state=sta|a[i];
			if(f[state]>f[sta]+1){
				f[state]=f[sta]+1;
				que[tail++]=state;
			}
		}
	}

	for(int i=0;i<m;i++){
		int state=0,k;
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			int t;scanf("%d",&t);
			state|=bit[t-1];
		}
		if(i)printf(" ");
		if(f[state]>n)
			printf("0");
		else
			printf("%d",f[state]);
	}
	printf("\n");
}

int main(){init();
	while(scanf("%d%d",&n,&m)!=EOF && (n || m))
		work();
	return 0;
}

