#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define nlen 110
#define mlen 10
#define maxrem 11000

const int zero=(int)'0';

int s[nlen],n,m,len;
int f[nlen][mlen][maxrem];
char a[nlen];

int dfs(int x,int c,int rem,int cc){
	if(c==cc)return rem==0;
	if(f[x][cc-c][rem])return 0;
	f[x][cc-c][rem]=1;
	char k,rk;int r;
	for(k='0';k<a[x];k++){
		if(!x && k=='0')continue;
		r=(k-a[x])%m;while(r<0)r+=m;
		r*=s[x];r%=m;
		r+=rem;r%=m;
		rk=a[x];a[x]=k;
		if(dfs(x+1,c+1,r,cc))return 1;
		a[x]=rk;
	}
	if(c+n-x>cc)
		if(dfs(x+1,c,rem,cc))return 1;
	for(k=a[x]+1;k<='9';k++){
		r=(k-a[x])%m;while(r<0)r+=m;
		r*=s[x];r%=m;
		r+=rem;r%=m;
		rk=a[x];a[x]=k;
		if(dfs(x+1,c+1,r,cc))return 1;
		a[x]=rk;
	}
	return 0;
}

void work(){
	scanf("%d",&m);memset(f,0,sizeof(f));
	int i,k=1,rem=0%m;
	n=strlen(a);len=log(m)/log(10)+2;
	for(i=0;i<n;i++){
		rem*=10;rem+=((int)a[i]-zero)%m;rem%=m;
		s[n-i-1]=k%m;k*=10;k%=m;
	}
	for(i=0;i<=len;i++)
		if(dfs(0,0,rem,i))break;
	printf("%s\n",a);
}

int main(){
	while(scanf("%s",a)!=EOF)work();
	return 0;
}
