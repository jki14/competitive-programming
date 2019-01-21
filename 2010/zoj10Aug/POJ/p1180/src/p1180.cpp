#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define lld long long

#define q1 s[v-1]
#define q2 s[v-2]
#define p1 s[u]
#define p2 s[u+1]

#define maxn 11000

const lld inf = 1LL<<60;

int n,k;
lld f[maxn],sumt[maxn],sumf[maxn];
int s[maxn];

void work(){
	int i,u,v;
	memset(sumt,0,sizeof(sumt));
	memset(sumf,0,sizeof(sumf));
	scanf("%d",&k);
	for(i=1;i<=n;i++){
		scanf("%d%d",&u,&v);
		sumt[i]=sumt[i-1]+(lld)u;
		sumf[i]=sumf[i-1]+(lld)v;
	}
	f[n+1]=0;u=v=0;
	for(i=n;i>=1;i--){
		while(u+1<v && (f[q2+1]-f[q1+1])*(sumt[q1]-sumt[i])
				<=(f[q1+1]-f[i+1])*(sumt[q2]-sumt[q1]))v--;
		s[v++]=i;
		while(u+1<v && f[p1+1]+((lld)k+sumt[p1]-sumt[i-1])*(sumf[n]-sumf[i-1])
				>=f[p2+1]+((lld)k+sumt[p2]-sumt[i-1])*(sumf[n]-sumf[i-1]))u++;
		f[i]=f[p1+1]+((lld)k+sumt[p1]-sumt[i-1])*(sumf[n]-sumf[i-1]);
	}
	//cout<<"p1="<<p1<<endl;
	printf("%I64d\n",f[1]);
}

int main(){
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}
