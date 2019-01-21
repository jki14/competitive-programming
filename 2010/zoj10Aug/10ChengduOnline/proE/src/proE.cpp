#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define maxn 3100
#define maxm 210000
#define maxp 5

const int inf = 1000000000;

int n,m;

int num,len,next[maxn],ev[maxm],ew[maxm];
int d[maxp][maxn],mk[maxn],nbs[maxn],ps[maxn],heap[maxn];

void update(int r){
	int q=ps[r],p=q>>1;
	while(p && value[heap[p]]>value[r]){
		ps[heap[p]]=q;heap[q]=heap[p];
		q=p;p=q>>1;
	}
	heap[q]=r;ps[r]=q;
}

int getmin(){
	int ret=heap[1],p=1,q=2,r=heap[len--];
	while(q<=len){
		if(q<len && value[heap[q+1]]<value[heap[q]])q++;
		if(value[heap[q]]<value[r]){
			ps[heap[q]]=p;heap[p]=heap[q];
			p=q;q=p<<1;
		}else break;
	}
	heap[p]=r;ps[r]=p;
	return ret;
}

void dijkstra(const int &src,const int &dst){
	int j,u,v;
	memset(value,0x7F,sizeof(value));
	memset(mk,0,sizeof(mk));
	memset(ps,0,sizeof(ps));
	value[src]=0;heap[len=1]=src;ps[src]=1;
	while(!mk[dst]){
		if(len==0)return;
		u=getmin();mk[u]=1;
		for(j=nbs[u];j;j=next[j]){
			v=ev[j];if(!mk[v] && max(value[u],ew[j])<value[v]){
				if(!ps[v]){ heap[++len]=v;ps[v]=len; }
				value[v]=max(value[u],ew[j]); update(v);
			}
		}
	}
}


int main(){
	while(scanf("%d%d",&n,&m)!=EOF)doit();
	return 0;
}
