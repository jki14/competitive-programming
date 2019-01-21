//============================================================================
// Name        : PartitonTree
// Author      : J.Ki
// Version     : 1.00
// Copyright   : WangZhe (Chongqing University Computer College)
// Description : 划分树，例为poj2104(求指定区间第k的数)
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
#include<set>
#include<map>
using namespace std;

#define maxn 110000
#define maxd 20

int n,m;
int a[maxn],s[maxn];
int c[maxd][maxn],f[maxd][maxn];

void build(const int &d,const int &l,const int &r){
	if(l==r)return;
	int i,mid=(l+r)>>1,p=l,q=mid+1,equal=0;
	for(i=mid;i>=l && s[i]==s[mid];i--)equal++;
	for(i=l;i<=r;i++){
		if(i>l)f[d][i]=f[d][i-1];else f[d][i]=0;
		if(c[d][i]<s[mid] || (c[d][i]==s[mid] && equal && equal--)){
			c[d+1][p++]=c[d][i];
			f[d][i]++;
		}else{
			c[d+1][q++]=c[d][i];
		}
	}
	build(d+1,l,  mid);
	build(d+1,mid+1,r);
}

int que(int u,int v,int k){
	int l=1,r=n,d=0;
	int fl,fr,mid;
	while(u!=v){
		if(u>l)fl=f[d][u-1];else fl=0;
		fr=f[d][v];
		mid=(l+r)>>1;
		if(k<=fr-fl){
			u=l+fl;v=l+fr-1;
			d++;r=mid;
		}else{
			u=mid+1+u-l-fl;
			v=mid+1+v-l-fr;
			k-=fr-fl;
			d++;l=mid+1;
		}
	}
	return c[d][u];
}

void work(){
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		c[0][i]=s[i]=a[i];
	}
	sort(s+1,s+n+1);
	build(0,1,n);
	while(m--){
		int u,v,k;
		scanf("%d%d%d",&u,&v,&k);
		printf("%d\n",que(u,v,k));
	}
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF)
		work();
	return 0;
}
