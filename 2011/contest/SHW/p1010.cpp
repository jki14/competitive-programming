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

#define maxlen 41000
#define minlen 256

const int pone=0xfffffff;

int n,m,ansx,ansy;
int sa[maxlen],hig[maxlen],rak[maxlen],tmp[maxlen],top[maxlen];
int que[maxlen],head,tail;
int tai[maxlen],lef,rig;
char s[maxlen];

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
		memcpy(rak,sa,n*sizeof(int));
		memcpy(sa,tmp,n*sizeof(int));
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
	scanf("%s",s);n=strlen(s);
	/* for m==1 */
	if(m==1){
		printf("%d %d\n",n,0);
		return;
	}
	
	build();

	/* debug */
	/*for(int i=0;i<n;i++)
		printf("sa[%d]=%d,hig[%d]=%d\n",i,sa[i],i,hig[i]);*/

	ansx=0;head=tail=lef=rig=0;
	for(int i=0;i<m;i++){
		while(head<tail && i-que[head]>=m-1)head++;
		while(head<tail && hig[que[tail-1]]>hig[i])tail--;
		que[tail++]=i;

		while(lef<rig && i-tai[lef]>=m)lef++;
		while(lef<rig &&  sa[tai[rig-1]]< sa[i])rig--;
		tai[rig++]=i;
	}
	if(head<tail && hig[que[head]]){
		if(hig[que[head]]>ansx){
			ansx=hig[que[head]];
			ansy=sa[tai[lef]];
		}else if(hig[que[head]]==ansx && ansy<sa[tai[lef]])ansy=sa[tai[lef]];
	}
	for(int i=m;i<n;i++){
		while(head<tail && i-que[head]>=m-1)head++;
		while(head<tail && hig[que[tail-1]]>hig[i])tail--;
		que[tail++]=i;

		while(lef<rig && i-tai[lef]>=m)lef++;
		while(lef<rig &&  sa[tai[rig-1]]< sa[i])rig--;
		tai[rig++]=i;
		
		//printf("hig[que[head]]=%d\n",hig[que[head]]);
		if(hig[que[head]]){
			if(hig[que[head]]>ansx){
				ansx=hig[que[head]];
				ansy=sa[tai[lef]];
			}else if(hig[que[head]]==ansx && ansy<sa[tai[lef]])ansy=sa[tai[lef]];
		}
	}
	if(!ansx)
		printf("none\n");
	else
		printf("%d %d\n",ansx,ansy);
}

int main(){
	while(scanf("%d",&m)!=EOF && m)
		work();
	return 0;
}

