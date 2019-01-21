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

#define maxn 1100

typedef long long lld;

int n;
int a[maxn],b[maxn],c[maxn],d[maxn];
lld f[maxn],ans;
int id[maxn];

//char ret[maxn];

int cmp(const int &i,const int &j){
	if(a[i]!=a[j])return a[i]<a[j];
	if(b[i]!=b[j])return b[i]<b[j];
	return d[i]>d[j];
}

int suit(const int &i,const int &j){
	if(a[i]<a[j] || b[i]<b[j])return 0;
	if(d[i]==1 &&  a[i]==a[j] && b[i]==b[j]) return 0;
	if(d[i]==2 && (a[i]==a[j] || b[i]==b[j]))return 0;
	return 1;
}

void work(){
	int I,J,i,j;ans=0LL;
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
		if(a[i]>b[i])swap(a[i],b[i]);
		id[i]=i;
	}
	sort(id,id+n,cmp);
	for(I=0;I<n;I++){i=id[I];
		f[i]=(lld)c[i];
		for(J=0;J<I;J++){j=id[J];
			if(suit(i,j))f[i]=max(f[i],f[j]+((lld)c[i]));
		}
		ans=max(ans,f[i]);
	}
	//printf("%I64d\n",ans);
	cout<<ans<<endl;
}

int main(){
	while(scanf("%d",&n)!=EOF && n)work();
	return 0;
}

