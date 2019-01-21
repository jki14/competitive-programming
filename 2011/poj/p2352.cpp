#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cmath>
#include<climits>
#include<algorithm>
using namespace std;

#define maxn 1100000

#define X 33000

int n,lev[maxn];
int c[maxn],lowbit[maxn];

void add(int x){ for(;x<X;x+=lowbit[x])c[x]++; }

int que(int x){
	int ret=0;
	for(;x>0;x-=lowbit[x])
		ret+=c[x];
	return ret;
}

void work(){
	int i,x,y;
	memset(lev,0,sizeof(lev));
	memset(c,0,sizeof(c));
	for(i=0;i<n;i++){
		scanf("%d%d",&x,&y);x++;
		lev[que(x)]++;
		add(x);
	}
	for(i=0;i<n;i++)
		printf("%d\n",lev[i]);
}

int main(){
	for(int i=1;i<=X;i++)lowbit[i]=i&(-i);
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}

