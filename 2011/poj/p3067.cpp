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
#include<set>
#include<map>
using namespace std;

#define maxn 1100000

typedef long long lld;

int timer;

int n,m,k;
lld c[maxn],sum,res;
int s[maxn],t[maxn],id[maxn],lowbit[maxn];

int cmp(const int &i,const int &j){
	if(s[i]!=s[j])return s[i]<s[j];
	return t[i]<t[j];
}

void add(int x){ for(;x<=m;x+=lowbit[x])c[x]+=1LL; }

lld que(int x){ lld ret=0;for(;x>0;x-=lowbit[x])ret+=c[x];return ret; }

void work(){
	int i;for(i=0;i<=m;i++)lowbit[i]=i&(-i);
	memset(c,0,sizeof(c));res=0LL;
	for(i=0;i<k;i++){id[i]=i;
		scanf("%d%d",&s[i],&t[i]);
	}
	sort(id,id+k,cmp);
	for(sum=0LL;sum<(lld)k;sum++){i=id[sum];
		res+=sum-que(t[i]);
		add(t[i]);
	}
	printf("Test case %d: %lld\n",timer,res);
}

int main(){int t;scanf("%d",&t);
	for(timer=1;timer<=t;timer++){scanf("%d%d%d",&n,&m,&k);
		work();
	}
	return 0;
}
