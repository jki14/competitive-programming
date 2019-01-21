#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<climits>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

#define maxn 110000
#define maxm 110000

#define k id[i]

typedef long long lld;

int n,m;
lld ans;
int a[maxm],id[maxm];
int f[maxm],l[maxn];

int cmp(const int &i,const int &j){ return a[i]>a[j]; }

void work(){
	int i,j;
	for(i=0;i<m;i++){
		scanf("%d",&a[i]);
		id[i]=i;
	}
	sort(id,id+m,cmp);
	for(j=0;m;){
		for(i=0;i<m;i++){
			f[j++]=k;
			a[k]--;
		}
		while(m>0 && a[id[m-1]]==0)m--;
	}
	memset(l,-1,sizeof(l));
	//printf("\n");
	ans=0LL;
	for(i=0;i<n;i++){
		//printf("%d ",f[i]);
		if(l[f[i]]==-1){
			l[f[i]]=i;
			continue;
		}
		ans=ans+((lld)(i-l[f[i]]));
		l[f[i]]=i;
	}
	//printf("\n");
	printf("%lld\n",ans);
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF && !(n==0 && m==0))
		work();
	return 0;
}
