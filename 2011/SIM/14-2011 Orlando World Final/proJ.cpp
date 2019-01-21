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

#define N 1100000
#define M 2100
#define K 2

#define nex now^1

struct Spy{
	int a,s;
	char t;
	bool operator < ( const Spy &p ) const{
		if(s!=p.s)return s>p.s;
		return t=='H';
	}
};

const int n = 1000000;
const int m = 2000;

const int inf=0x3fffffff;

typedef Spy py;

int c,num;
int f[N],g[N],v[N];
int que[K][N];
py a[M];

int sh(const int &x){
	int res=0;
	for(int i=1;i<=x;i++){
		res+=i*i;
		if(res>n)return inf;
	}
	return res;
}

int lh(const int &x){
	int res=0;
	for(int i=x;i>0;i>>=1){
		res+=i*i;
		if(res>n)return inf;
	}
	return res;
}

void build(){
	num=0;
	for(int i=2;i<=m;i++){
		for(int j=0;j<2;j++){
			if(j){
				a[num].a=i;
				a[num].t='H';
				a[num].s=sh(i);
				if(a[num].s<=n)num++;
			}else{
				a[num].a=i;
				a[num].t='L';
				a[num].s=lh(i);
				if(a[num].s<=n)num++;
			}
		}
	}
	sort(a,a+num);
}

void core(){
	memset(f,0x3f,sizeof(f));
	memset(g,0x3f,sizeof(g));
	memset(v,0x8f,sizeof(v));
	int now=0;que[now][0]=0;
	f[0]=0;que[now][++que[now][0]]=0;
	for(int i=0;i<num;i++){
		que[nex][0]=0;
		for(int j=que[now][0];j;j--){//printf("j=%d\n",j);
			int sta=que[now][j];//printf("sta=%d\n",sta);
			if(f[sta]>6)continue;
			//printf("que[%d][0]=%d\n",nex,que[nex][0]);
			if(v[sta]<i){ v[sta]=i;que[nex][++que[nex][0]]=sta; }
			if(sta+a[i].s>n)continue;
			//printf("a[%d].s=%d, a[].a=%d\n",i,a[i].s,a[i].a);
			//printf("sta+a[i].s=%d\n",sta+a[i].s);
			if(f[sta+a[i].s]>f[sta]+1){
				//printf("succ 0\n");
				f[sta+a[i].s]=f[sta]+1;
				g[sta+a[i].s]=min(i,g[sta]);
				//printf("succ 1\n");
				if(v[sta+a[i].s]<i){
					v[sta+a[i].s]=i;
					que[nex][++que[nex][0]]=sta+a[i].s;
				}
				//printf("succ 2\n");
			}else if(f[sta+a[i].s]==f[sta]+1) g[sta+a[i].s]=min(g[sta+a[i].s],min(i,g[sta]));
		}
		now=nex;
	}
}

int main(){
	build();printf("num=%d\n",num);
	core();
	return 0;
}

