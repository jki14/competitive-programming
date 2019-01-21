#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

#define maxn 110
#define maxw 2100

#define pre now^1

#define k q[s]

const int maxt=maxn*maxw;

int TIMER;

int f[maxt],g[maxt],q[maxt];
int n,s,t,now,p,res,mk[maxt];

void work(){
	int i,val,cnt=0;now=0;
	memset(f,0x8f,sizeof(f));
	memset(mk,0,sizeof(mk));
	f[0]=0;t=0;mk[0]=1;q[t++]=0;
	for(i=0;i<n;i++){scanf("%d",&val);
		memcpy(g,f,sizeof(g));
		for(s=0;s<t;s++){
			if(f[val+k]<g[k]+val){
				f[val+k]=g[k]+val;
				if(!mk[val+k]){ mk[val+k]=1;q[t++]=val+k; }
			}
			if(k-val>=0)p=k-val;else p=val-k;
			if(f[p]<g[k]+val){
				f[p]=g[k]+val;
				if(!mk[p]){ mk[p]=1;q[t++]=p; }
				if(!p)cnt=1;
			}
		}
	}
	if(!cnt)res=-1;else res=f[0]/2;
	printf("Case %d: %d\n",TIMER,res);
}

int main(){
	int t;scanf("%d",&t);for(TIMER=1;TIMER<=t;TIMER++){
		scanf("%d",&n);work();
	}
	return 0;
}
