#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

#define N 23
#define M 1000

#define maxlen 50

#define T t[x]

const int cnt[4]={ 1,4,4,2 };

const int inf=LONG_MIN;

const int lmt=1<<23;

const int src=2000;

map<string,int> s;
map<char,int> ts;
int w[N],t[N],m,res;
int x[M],y[M],z[M];
int clt[4],tt[4],sec[N];

char s0[maxlen],s1[maxlen];
string str0,str1;

int max(int x,int y){ return (x>y)?x:y; }

int check(int k){
	int i,r;
	for(i=0;i<4;i++)if(clt[i]!=cnt[i])return inf;
	for(i=r=0;i<N;i++)
		if(k&sec[i])r+=w[i];
	for(i=0;i<m;i++)
		if((k&x[i]) &&(k&y[i]))r+=z[i];
	return r;
}

int init(){
	memset(tt,0,sizeof(tt));s.clear();
	if(scanf("%s%d%s",s0,&w[0],s1)!=EOF){
		str0=s0;s.insert(pair<string,int>(str0,0));
		t[0]=ts[s1[0]];tt[t[0]]++;
		return 1;
	}
	return 0;
}

void dfs(int x,int k){
	if(x==N){
		res=max(res,check(k));
		return;
	}
	if(!x)
		memset(clt,0,sizeof(clt));
	if(tt[T]+clt[T]<cnt[T])return;
	if(tt[T]+clt[T]>cnt[T]){
		tt[T]--;dfs(x+1,k);tt[T]++;
	}
	tt[T]--;clt[T]++;
	if(clt[T]<=cnt[T])dfs(x+1,k|sec[x]);
	tt[T]++;clt[T]--;
}

void work(){
	int i;res=inf;
	for(i=1;i<N;i++){
		scanf("%s%d%s",s0,&w[i],s1);
		str0=s0;s.insert(pair<string,int>(str0,i));
		t[i]=ts[s1[0]];tt[t[i]]++;
	}
	scanf("%d",&m);for(i=0;i<m;i++){
		scanf("%s%s%d",s0,s1,&z[i]);
		str0=s0;str1=s1;
		x[i]=sec[s[str0]];y[i]=sec[s[str1]];
	}
	/*for(i=src;i<lmt;i++){
		now=check(i);
		if(now==inf)continue;
		for(j=0;j<m;j++)
			if((i&x[j]) && (i&y[j]))now+=z[j];
		if(now>res)res=now;
	}*/
	dfs(0,0);
	if(res>inf)
		printf("%d\n",res);
	else
		printf("impossible\n");
}

int main(){
	sec[0]=1;for(int i=1;i<N;i++)sec[i]=sec[i-1]<<1;ts.clear();
	ts.insert(pair<char,int>('g',0));
	ts.insert(pair<char,int>('d',1));
	ts.insert(pair<char,int>('m',2));
	ts.insert(pair<char,int>('s',3));
	while(init())work();
	return 0;
}
