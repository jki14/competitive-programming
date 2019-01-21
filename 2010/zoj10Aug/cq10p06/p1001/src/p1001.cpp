#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

#define maxt 1000000
#define maxk 3
#define maxc 100
#define n 16
#define x q[p]

int timer;

int s,t,tot;
int f[maxt],u[maxc],v[maxc];
int q[maxt];

void link(const int &a,const int &b){
	if(a>b)return;
	u[tot]=1<<(16-a);v[tot++]=1<<(16-b);
}

void init(){
	tot=0;s=0;
	int i;
	for(i=0;i<8;i++){
		s<<=1;s+=1;
	}
	link(1,2);link(1,3);link(1,5);link(1,9);
	link(2,4);link(2,6);link(2,10);
	link(3,4);link(3,7);link(3,11);
	link(4,8);link(4,12);
	link(5,6);link(5,7);link(5,13);
	link(6,8);link(6,14);
	link(7,8);link(7,15);
	link(8,16);
	link(9,10);link(9,11);link(9,13);
	link(10,12);link(10,14);
	link(11,12);link(11,15);
	link(12,16);
	link(13,14);link(13,15);
	link(14,16);
	link(15,16);
}

void call(){
	memset(f,0x7f,sizeof(f));q[0]=1;
	int i,p;
	f[s]=0;q[1]=s;p=1;
	for(;f[x]<maxk && p<=q[0];p++)
		for(i=0;i<tot;i++)
			if(((x&u[i])==0)!=((x&v[i])==0) && f[x^u[i]^v[i]]>f[x]+1){
				f[x^u[i]^v[i]]=f[x]+1;
				q[0]++;q[q[0]]=x^u[i]^v[i];
			}
}

void doit(){
	int i,num;t=0;
	for(i=0;i<n;i++){
		scanf("%d",&num);
		t<<=1;t+=num;
	}
	if(f[t]<=maxk)
		printf("Case #%d: %d\n",timer,f[t]);
	else
		printf("Case #%d: more\n",timer);
}

int main(){
	int m;scanf("%d",&m);
	init();call();
	timer=0;while(m--){
		timer++;
		doit();
	}
	return 0;
}
