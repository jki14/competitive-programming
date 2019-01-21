#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define inf 1000000000
#define max(a,b) ((a>b)?a:b)

const int maxn=210,maxm=maxn*maxn;

int timer;
int n,m;
int num,len,next[maxm],ev[maxm],ew[maxm];
int value[maxn],mk[maxn],nbs[maxn],ps[maxn],heap[maxn];
int dx[maxn],dy[maxn];

int sqr(const int &x){ return x*x; }

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

void doit(){
	int i,j;
	for(i=1;i<=n;i++)
		scanf("%d%d",&dx[i],&dy[i]);
	num=0;memset(nbs,0,sizeof(nbs));
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i!=j){
				next[++num]=nbs[i];nbs[i]=num;
				ev[num]=j;ew[num]=sqr(dx[i]-dx[j])+sqr(dy[i]-dy[j]);
			}
	dijkstra(1,2);
	printf("Scenario #%d\n",timer++);
	printf("Frog Distance = %.3f\n\n",(double)sqrt((double)value[2]));
}

int main(){
	timer=1;
	while(scanf("%d",&n)!=EOF && n!=0)doit();
	return 0;
}
