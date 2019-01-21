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

#define N 20
#define M 2
#define K 110000

int n,m,T,tar;
char a[M][N];
int bit[N];
int opt[N][K],same[N];
int f[K],que[K],head,tail;

char chr(const int &x){
	if(x>=n)return a[1][x-n];
	return a[0][x];
}

void init(){
	int i,j,k,x,y,z;

	tar=(1<<m)-1;

	for(i=0;i<m;i++){opt[i][0]=0;
		for(j=0;j<m;j++){x=i%n;y=j%n;
			if(x>y)swap(x,y);
			k=0;
			for(z=x;z<=y;z++){
				if(i< n || j< n)k|=bit[  z];
				if(i>=n || j>=n)k|=bit[n+z];
			}
			opt[i][++opt[i][0]]=k;

			//printf("opt[%d][%d]=%d\n",i,opt[i][0],opt[i][opt[i][0]]);
		}
	}

	for(i=0;i<m;i++){same[i]=0;
		for(j=0;j<m;j++)if(chr(i)==chr(j))same[i]|=bit[j];
		//printf("same[%d]=%d\n",i,same[i]);
	}
}

void work(){
	int i,j,k;
	int pri,sta;
	scanf("%d",&n);m=n<<1;
	scanf("%s",a[0]);scanf("%s",a[1]);
	init();
	
	head=tail=0;
	memset(f,0x3f,sizeof(f));
	f[que[tail++]=0]=0;
	while(head<tail){
		k=que[head++];
		//printf("que[%d]=%d\n",head-1,k);
		for(i=0;i<m;i++)
			for(j=1;j<=opt[i][0];j++){
				pri=opt[i][j];
				sta=(k & (tar ^ pri))|(pri & same[i]);
				//printf("sta=%d k=%d pri=%d same[i]=%d f[sta]=%d\n",sta,k,pri,same[i],f[sta]);
				if(f[sta]>f[k]+1){
					f[sta]=f[k]+1;
					if(sta==tar){
						printf("Case #%d: %d\n",T,f[tar]);
						return;
					}
					//printf("	que[%d]=%d\n",tail,sta);
					que[tail++]=sta;
				}
			}
	}
}

int main(){
	for(int i=0;i<N;i++)bit[i]=1<<i;
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++)work();
	return 0;
}

