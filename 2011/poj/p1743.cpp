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

#define maxlen 21000
#define minlen 256
#define dlt 90
#define minpath 5

const int pone=0xffffffff;

const int inf=0x3fffffff;
const int low=-inf;

int n,ans;
int sa[maxlen],hig[maxlen],rak[maxlen],tmp[maxlen],top[maxlen];
int s[maxlen];

void makesa(){
	int i,j,len,m;
	m=max(minlen,n);
	memset(top,0,m*sizeof(int));
	for(i=0;i<n;i++)top[rak[i]=s[i]&pone]++;
	for(i=1;i<m;i++)top[i]+=top[i-1];
	for(i=0;i<n;i++)sa[--top[rak[i]]]=i;
	for(len=1;len<n;len<<=1){
		for(i=0;i<n;i++){
			j=sa[i]-len;if(j<0)j+=n;
			tmp[top[rak[j]]++]=j;
		}
		sa[tmp[top[0]=0]]=j=0;
		for(i=1;i<n;i++){
			if(rak[tmp[i]]!=rak[tmp[i-1]] || rak[tmp[i]+len]!=rak[tmp[i-1]+len])top[++j]=i;
			sa[tmp[i]]=j;
		}
		memcpy(rak, sa,n*sizeof(int));
		memcpy(sa ,tmp,n*sizeof(int));
		if(j>=n-1)break;
	}
}

void lcp(){
	int i,j,k;
	memset(hig,0,sizeof(hig));
	for(j=rak[hig[i=k=0]=0];i<n-1;i++,k++){
		while(k>=0 && s[i]!=s[sa[j-1]+k]){
			hig[j]=k--;
			j=rak[sa[j]+1];
		}
	}
}

void build(){
	makesa();lcp();
}

int succ(const int &x){

	//printf("SUCC %d:\n",x);

	int i,L,R;
	L=inf;R=low;
	for(i=1;i<n;i++){
		if(hig[i]<x){
			L=sa[i];R=sa[i];
		}else{
			L=min(L,sa[i]);
			R=max(R,sa[i]);
		}
		if(R-L>=x)return 1;
	}
	return 0;
}

int getres(){
	int l=4,r=(n>>1)+1;
	int mid;
	while(l<=r){
		mid=(l+r)>>1;

		//printf("Try Mid=%d\n",mid);

		if(succ(mid)){
			if(!succ(mid+1))return mid+1;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	return 0;
}

void work(){
	int i,k,u,v;
	
	scanf("%d",&v);
	for(k=0,i=1;i<n;i++){
		u=v;scanf("%d",&v);
		s[k++]=v-u+dlt;
	}s[k]=0;
	n=k+1;
	build();

	/*for(i=1;i<n;i++){

		printf("sa[i]=%d sa[i-1]=%d hig[i]=%d\n",sa[i],sa[i-1],hig[i]);

		k=min(hig[i],abs(sa[i]-sa[i-1])-1)+1;
		if(k<minpath)continue;
		ans=max(ans,k);
	}*/
	ans=getres();

	printf("%d\n",ans);
}

int main(){
	while(scanf("%d",&n)!=EOF && n)work();
	return 0;
}

