#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define p que[h]

#define v id[i]

#define maxn 1100

int n,root;
int fail[maxn],succ[maxn],leaf[maxn],d[maxn];
int worm[maxn],f[maxn],que[maxn],mk[maxn],id[maxn];

int SuperCmp(int i,int j){
	if(mk[i]!=mk[j])return mk[i]<mk[j];
	return (fail[i]+2)*leaf[j]<(fail[j]+2)*leaf[i];
}

int mark(int i){
	if(!mk[i])mk[i]=mark(f[i])-1;
	return mk[i];
}

void work(){
	int i,h,t,k;char cstr[4];
	memset(d,0,sizeof(d));
	memset(fail,0,sizeof(fail));
	memset(succ,0,sizeof(succ));
	memset(leaf,0,sizeof(leaf));
	memset(mk,0,sizeof(mk));
	for(i=1;i<=n;i++){
		scanf("%d%s",&k,cstr);id[i]=i;
		worm[i]=(cstr[0]=='Y')?1:0;
		if(k==-1){ f[i]=0;root=i;continue; }
		f[i]=k;d[k]++;
	}
	mk[root]=n;h=t=0;for(i=1;i<=n;i++){
		mark(i);
		if(!d[i]){ que[t++]=i;leaf[i]=1; }
	}
	for(;h<t;h++){
		if(!worm[f[p]])fail[f[p]]+=2+fail[p];
		leaf[f[p]]+=leaf[p];d[f[p]]--;
		if(!d[f[p]]){
			que[t++]=f[p];
		}
		if(f[p]==0)break;
	}
	sort(id+1,id+1+n,SuperCmp);
	memset(d,0,sizeof(d));
	for(i=1;i<=n && v!=root;i++){
		succ[f[v]]+=(d[f[v]]+1)*leaf[v]+succ[v];
		d[f[v]]+=fail[v]+2;
	}
	printf("%.4f\n",(double)succ[root]/(double)leaf[root]);
}

int main(){
	while(scanf("%d",&n)!=EOF && n)work();
	return 0;
}
