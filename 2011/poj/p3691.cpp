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
#define maxchr 4
#define maxlen 1100
#define K 4

const int inf=0x3fffffff;

int T;

int n,ans,num;
int route[maxnum][maxchr],fail[maxnum],flag[maxnum];
int que[maxnum],virus[maxnum];

int trans(const char &c){
	switch(c){
		case 'A':return 0;
		case 'G':return 1;
		case 'C':return 2;
		case 'T':return 3;
	}
	return -1;
}

void init(char *key){
	int p,k;
	for(p=0;*key;key++){
		k=trans(*key);
		if(!route[p][k])route[p][k]=++num;
		p=route[p][k];
	}
	flag[p]=virus[p]=1;
}

void build(){
	int k,p,q,l,r;l=r=0;que[r++]=0;
	memset(fail,0,sizeof(fail));
	for(;l<r;l++){
		p=que[l];
		for(k=0;k<K;k++){
			if(route[p][k]){
				que[r++]=route[p][k];
				if(p){
					for(q=fail[p];q && !route[q][k];)q=fail[q];
					fail[route[p][k]]=route[q][k];
					if(virus[route[q][k]])virus[route[p][k]]=1;
				}
			}
		}
	}
}

int arr[maxlen],f[maxlen][maxnum];
char str[maxlen];

void work(){T++;
	int i,j,k,p;
	memset(route,0,sizeof(route));num=0;
	memset(flag,0,sizeof(flag));
	memset(virus,0,sizeof(virus));
	for(i=0;i<n;i++){
		scanf("%s",str);
		init(str);
	}
	build();
	
	scanf("%s",str);n=strlen(str);
	for(i=0;i<n;i++)arr[i]=trans(str[i]);

	memset(f,0x3f,sizeof(f));
	f[0][0]=0;
	for(i=0;i<n;i++)
		for(j=0;j<=num;j++)
			for(k=0;k<K;k++){p=j;
				while(p && !route[p][k])p=fail[p];
				p=route[p][k];
				if(virus[p])continue;
				
				f[i+1][p]=min(f[i+1][p],f[i][j]+(k!=arr[i]));
			}

	ans=inf;
	for(i=0;i<=num;i++)ans=min(ans,f[n][i]);
	if(ans>n)ans=-1;
	printf("Case %d: %d\n",T,ans);
}

int main(){T=0;
	while(scanf("%d",&n)!=EOF && n)
		work();
	return 0;
}

