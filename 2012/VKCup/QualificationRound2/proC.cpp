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

#define L 210000
#define S 110
#define C 30

char ans[L],str[S];
int n,m,k,l;
int c[C][L],lowbit[L];

void modify(const int &k,int x,const int &d){ for(;x<=n;x+=lowbit[x])c[k][x]+=d; }
int sum(const int &k,int x){int res=0;
	for(;x;x-=lowbit[x])res+=c[k][x];
	return res;
}

int find(const int &k,const int &p){
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(sum(k,mid)<p)
			l=mid+1;
		else{
			if(sum(k,mid)==p && sum(k,mid-1)<p)return mid;
			r=mid-1;
		}
	}
	return -1;
}

void work(){
	scanf("%s",str);l=strlen(str);n=l*k;
	memset(c,0,sizeof(c));
	for(int i=0;i<n;i++){char cha=str[i%l];
		ans[i]=cha;modify((int)(cha-'a'),i+1,1);
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++){int p;
		scanf("%d %s",&p,str);
		k=find((int)(str[0]-'a'),p);
		//printf("k=%d\n",k);
		ans[k-1]=0;modify((int)(str[0]-'a'),k, -1);
	}
	for(int i=0;i<n;i++){
		if(!ans[i])continue;
		printf("%c",ans[i]);
	}printf("\n");
}

int main(){
	for(int i=0;i<L;i++)lowbit[i]=i&(-i);
	while(scanf("%d",&k)!=EOF)
		work();
	return 0;
}

