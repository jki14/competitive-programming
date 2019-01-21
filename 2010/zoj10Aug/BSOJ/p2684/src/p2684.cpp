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

#define maxn 21000
#define dis(x,y) (d[y]-d[x])

#define tail n+1

#define p s[u]
#define p2 s[u+1]
#define q s[v-1]
#define q2 s[v-2]

const lld inf=1LL<<60;

int n,ans;
int s[maxn];
lld f[maxn],w[maxn],d[maxn],c[maxn];

void work(){
	int i,u,v;
	lld ans=inf;
	memset(w,0,sizeof(w));memset(d,0,sizeof(d));memset(c,0,sizeof(c));
	for(i=1;i<=n;i++){
		scanf("%d%d",&u,&v);
		w[i]=w[i-1]+(lld)u;
		d[i+1]=d[i]+(lld)v;
		c[i+1]=c[i]+w[i]*(lld)v;
	}
	u=v=0;
	for(i=2;i<=n;i++){
		//f[i]=c[tail]-w[i]*dis(i,n+1)-w[j]*dis(j,n+1)
		while(u<v && (w[q2]*d[q2]-w[q]*d[q])*(w[q]-w[i-1])>=(w[q]*d[q]-w[i-1]*d[i-1])*(w[q2]-w[q]))v--;
		s[v++]=i-1;
		//while(u+1<v && w[p]*d[p]-w[p2]*d[p2]>=w[p]*d[i]-w[p2]*d[i])u++;
		while(u+1<v && w[p2]*d[i]-w[p2]*d[p2]>=w[p]*d[i]-w[p]*d[p])u++;
		f[i]=c[tail]-w[i]*dis(i,tail)-w[p]*dis(p,i);
		//cout<<"path "<<i<<":="<<p<<endl;
		if(ans>f[i])ans=f[i];
	}
	printf("%d\n",(int)ans);
}

int main(){
	//while(scanf("%d",&n)!=EOF)
	scanf("%d",&n);
	work();
	return 0;
}
