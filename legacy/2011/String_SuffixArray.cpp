//============================================================================
// Name        : SuffixArray
// Author      : J.Ki
// Version     : 1.00
// Copyright   : WangZhe (Chongqing University Computer College)
// Description : 例为POJ2774,求两个字符串的最长相同连续子串
//============================================================================

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

#define maxlen 210000
#define minlen 256

const int pone=0xfffffff;

int na,nb,n,ans;
int sa[maxlen],hig[maxlen],rak[maxlen],tmp[maxlen],top[maxlen];
char a[maxlen],b[maxlen],s[maxlen];

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
	n=strlen(s);
	n++;makesa();lcp();
}

void work(){
	int i,k=0;
	na=strlen(a);nb=strlen(b);

	for(i=0;i<na;i++)s[k++]=a[i];s[k++]='$';
	for(i=0;i<nb;i++)s[k++]=b[i];s[k++]=0;

	//printf("%s\n",s);

	build();

	ans=0;
	for(i=1;i<n;i++){

		//printf("sa[i]=%d sa[i-1]=%d hig[i]=%d\n",sa[i],sa[i-1],hig[i]);

		if( ((sa[i]<na && sa[i-1]>na) || (sa[i]>na && sa[i-1]<na))  && hig[i]>ans )ans=hig[i];
	}

	printf("%d\n",ans);
}

int main(){
	while(scanf("%s%s",a,b)!=EOF)work();
	return 0;
}
