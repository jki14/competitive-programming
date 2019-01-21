#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define lld long long

#define newp (i-m+1)

#define p1 s[u]
#define p2 s[u+1]
#define q1 s[v-1]
#define q2 s[v-2]

#define maxn 510000

const lld inf=1LL<<60;

int n,m;

int a[maxn],s[maxn];
lld f[maxn],sum[maxn];

int mid(const int &x,const int &y){
	return (x+y)/2;
}

void work(){
	int i,u,v;
	scanf("%d%d",&n,&m);f[0]=sum[0]=0LL;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+(lld)a[i];
		f[i]=inf;
	}
	u=v=0;
	for(i=m;i<=n;i++){
		if(f[newp-1]<inf){
			while(u+1<v && ((f[q2-1]+(lld)a[q2]*((lld)q2-1)-sum[q2-1])-(f[q1-1]+(lld)a[q1]*((lld)q1-1)-sum[q1-1]))*((lld)a[q1]-(lld)a[newp])
					>=((f[q1-1]+(lld)a[q1]*((lld)q1-1)-sum[q1-1])-(f[newp-1]+(lld)a[newp]*((lld)newp-1)-sum[newp-1]))*((lld)a[q2]-(lld)a[q1]))v--;
			s[v++]=newp;
		}
		while(u+1<v && f[p1-1]+sum[i]-sum[p1-1]-(lld)a[p1]*((lld)i-(lld)p1+1LL)
				>=f[p2-1]+sum[i]-sum[p2-1]-(lld)a[p2]*((lld)i-(lld)p2+1LL))u++;
		f[i]=f[p1-1]+sum[i]-sum[p1-1]-(lld)a[p1]*((lld)i-(lld)p1+1LL);

		/*cout<<"path list for f["<<i<<"] is :";
		for(int k=u;k<v;k++)cout<<" "<<s[k];
		cout<<endl;*/

	}
	printf("%lld\n",f[n]);
}

int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
