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

#define maxnum 1100
#define maxsta 1100
#define chr 4
#define maxlen 1100000
#define N 11
#define M 110

const int low=LONG_MIN;
const int inf=LONG_MAX;

int n,m,ans;
int route[maxnum][chr],fail[maxnum],flag[maxnum],num;
int que[maxnum];

int bit[N],val[N];

int mk[maxsta][maxnum];
queue<int> qsta,qpos,qlen;

int  c2i(const char &c){
	switch(c){
		case 'A': return 0;
		case 'G': return 1;
		case 'T': return 2;
		case 'C': return 3;
	}
	return -1;
}

void ibit(){
	for(int i=0;i<N;i++)bit[i]=1<<i;
}

void init(char *key,const int &d){
	int p,k;
	for(p=0;*key;key++){
		k=c2i(*key);
		if(!route[p][k])route[p][k]=++num;
		p=route[p][k];
	}
	flag[p]|=bit[d];
}

void build(){
	int k,p,q,l,r;l=r=0;que[r++]=0;
	memset(fail,0,sizeof(fail));
	for(;l<r;l++){
		p=que[l];
		for(k=0;k<chr;k++){
			if(route[p][k]){
				que[r++]=route[p][k];
				if(p){
					for(q=fail[p];q && !route[q][k];)q=fail[q];
					fail[route[p][k]]=route[q][k];
					flag[route[p][k]]|=flag[route[q][k]];
				}
			}
		}
	}
}

char s[maxlen];

void clearque(){
	while(!qsta.empty())qsta.pop();
	while(!qpos.empty())qpos.pop();
	while(!qlen.empty())qlen.pop();
}

int count(const int &sta){
	int ret=0;
	for(int i=0;i<n;i++)
		if(sta&bit[i])ret+=val[i];
	return ret;
}

void work(){
	memset(route,0,sizeof(route));num=0;
	memset(flag,0,sizeof(flag));
	
	for(int i=0;i<n;i++){
		scanf("%s%d",s,&val[i]);
		if((int)strlen(s)>m)continue;
		init(s,i);
	}build();

	clearque();ans=low;memset(mk,0,sizeof(mk));
	qsta.push(0);qpos.push(0);qlen.push(0);
	while(!qsta.empty()){
		int sta=qsta.front();qsta.pop();
		int pos=qpos.front();qpos.pop();
		int len=qlen.front();qlen.pop();
		if(len==m){
			ans=max(ans,count(sta));
			continue;
		}
		for(int k=0;k<chr;k++){
			int newsta,newpos,newlen;

			newpos=pos;
			while(newpos && !route[newpos][k])newpos=fail[newpos];
			newpos=route[newpos][k];

			newsta=sta|flag[newpos];
			newlen=len+1;
			
			//printf("newsta=%d newpos=%d newlen=%d\n",newsta,newpos,newlen);
			if(mk[newsta][newpos]<newlen){
				mk[newsta][newpos]=newlen;
				qsta.push(newsta);
				qpos.push(newpos);
				qlen.push(newlen);
			}
		}
	}

	if(ans<0)
		printf("No Rabbit after 2012!\n");
	else
		printf("%d\n",ans);
}

int main(){ibit();
	while(scanf("%d%d",&n,&m)!=EOF)
		work();
	return 0;
}

