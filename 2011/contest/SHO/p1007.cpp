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

/*
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

#define N 24
#define M 8

const int vex[M]={ 0,1,2,7,16,21,22,23 };
const int pat[M]={ 3,3,6,6,17,17,20,20 };

int src[N],tar[N];

void work(){
	int i,j;
	for(i=0;i<N;i++)scanf("%d",&src[i]);
	for(i=0;i<N;i++)scanf("%d",&tar[i]);
	for(j=0;j<M;j++){i=vex[j];

		printf("src[i]=%d tar[i]=%d\n",src[i],tar[i]);
		printf("src[pat[j]]=%d tar[pat[j]]=%d\n",src[pat[j]],tar[pat[j]]);

		if((src[i] && tar[i] && src[i]!=tar[i])
		  ||	(src[i]==0 && tar[i] && src[pat[j]]!=tar[i])
		  ||	(src[i] && tar[i]==0 && src[i]!=tar[pat[j]])){
			printf("Y\n");
			return;
		}
	}
	printf("N\n");
}

int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}

*/


#define N 210000
#define S 2100000

#define L (i<<1)+1
#define R (i<<1)+2

typedef long long lld;

const double eps=1e-6;

//const lld inf=3037000499;

int T;

int n,m;
lld arr[N],sum[S];
int noc[S];

void update(const int &i){
	sum[i]=sum[L]+sum[R];
	noc[i]=noc[L]&noc[R];
}

void builds(const int &i,const int &l,const int &r){
	if(l==r){
		sum[i]=arr[l];
		if(sum[i]==1LL || sum[i]==0LL)noc[i]=1;
	}else{int mid=(l+r)>>1;
		builds(L,l,  mid);
		builds(R,mid+1,r);
		update(i);
	}
	//printf("sum[%d](%d->%d)==%lld noc=%d\n",i,l,r,sum[i],noc[i]);
}

/*lld SQRT(const lld x){
	lld l=0,r=inf;
	while(l<=r){
		lld mid=(l+r)>>1;
		if(mid*mid <= x){
			if(mid==inf)return mid;
			if(((mid+1LL)*(mid+1LL))>x)return mid;
			l=mid+1;
		}else r=mid-1;
	}
	return -1;
}*/

void insqrt(const int &i,const int &l,const int &r,const int &u,const int &v){
	if(u>r || v<l || noc[i])return;
	if(l==r){
		sum[i]=(lld)(sqrt((double)sum[i])+eps);
		//sum[i]=sqrt(sum[i]);
		//printf("sum[i]=%lld",sum[i]);
		//sum[i]=SQRT(sum[i]);
		//sum[i]=sqrt(sum[i]);
		//printf(" SQRT(sum[i])=%lld\n",sum[i]);
		if(sum[i]==1LL || sum[i]==0LL)noc[i]=1;
	}else{int mid=(l+r)>>1;
		insqrt(L,l,  mid,u,v);
		insqrt(R,mid+1,r,u,v);
		update(i);
	}
	//printf("sum[%d](%d->%d)==%lld noc=%d\n",i,l,r,sum[i],noc[i]);

}

lld  querry(const int &i,const int &l,const int &r,const int &u,const int &v){
	if(u>r || v<l)return 0LL;
	if(u<=l && r<=v)return sum[i];
	int mid=(l+r)>>1;
	return querry(L,l,  mid,u,v)+querry(R,mid+1,r,u,v);
}

void work(){T++;
	int i,t,u,v;

	memset(sum,0,sizeof(sum));
	memset(noc,0,sizeof(noc));

	for(i=1;i<=n;i++)scanf("%I64d",&arr[i]);
	//for(i=1;i<=n;i++)cin>>arr[i];
	builds(0,1,n);

	printf("Case #%d:\n",T);
	//scanf("%d",&m);
	cin>>m;
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&t,&u,&v);
		if(u>v)swap(u,v);
		if(t){
			//printf("%lld\n",querry(0,1,n,u,v));
			cout<<querry(0,1,n,u,v)<<endl;
		}else insqrt(0,1,n,u,v);
	}
	printf("\n");
}

int main(){T=0;
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}

