#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

#define maxT 3300000
#define RangeY 1100000

int TIMER;
int n,m,st[maxT],mk[maxT],pr[maxT];

int max(const int &x,const int &y){ return (x>y)?x:y; }

int full(int i,int s,int t,int ss,int tt){
	if(s>tt || t<ss)return 0;
	if(!pr[i]|| (ss<=s && t<=tt))return st[i]>=n;
	int mid=(s+t)>>1;
	if(full(i<<1,s,mid,ss,tt))return 1;
	if(full((i<<1)|1,mid+1,t,ss,tt))return 1;
	return 0;
}

int add(int i,int s,int t,int ss,int tt){
	if(s>tt || t<ss)return st[i];
	if(!mk[i]){ st[i]=st[i>>1];mk[i]=1;pr[i>>1]=1; }
	if(!pr[i] && ss<=s && t<=tt){ st[i]++; }
	else{int mid=(s+t)>>1;
		st[i]=max(add(i<<1,s,mid,ss,tt),add((i<<1)|1,mid+1,t,ss,tt));
	}
	return st[i];
}

void work(){
	printf("Case %d:\n",TIMER);
	memset(st,0,sizeof(st));memset(mk,0,sizeof(mk));memset(pr,0,sizeof(pr));
	int i,u,v;
	for(i=1;i<=m;i++){
		scanf("%d%d",&u,&v);if(u<v)u++;if(full(1,1,RangeY,u,v))continue;
		printf("%d ",i);add(1,1,RangeY,u,v);
	}
	printf("\n\n");
}

int main(){
	int t;scanf("%d",&t);
	for(TIMER=1;TIMER<=t;TIMER++){
		scanf("%d%d",&n,&m);work();
	}
	return 0;
}
