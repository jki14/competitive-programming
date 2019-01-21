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

typedef long long lld;

#define N 110
#define M 11000000
#define S 1100000

const lld inf=9223372036854775807LL;
const int s=10000000;

int T;

int prm[S],is[M],m;
lld n,k,res;
lld c[N];
lld a,b,num,sum,tot;

void getprm(const int &n){m=0;
	int i,j,d;
	int e=(int)(sqrt((double)n)+1.0);
	memset(is,0x7f,sizeof(is));
	prm[m++]=2;is[0]=is[1]=0;
	for(i=4;i<=n;i+=2)is[i]=0;
	for(i=3;i<e;i+=2)if(is[i]){
		prm[m++]=i;d=i<<1;
		for(j=i*i;j<=n;j+=d)is[j]=0;
	}
	for(;i<=n;i+=2)if(is[i])prm[m++]=i;
	//printf("m=%d\n",m);
}

void work(){
	//scanf("%I64d%I64d",&n,&k);
	cin>>n>>k;

	/* Special Case */
	if(k==1LL){ cout<<"Case "<<T<<": inf"<<endl;return; }

	/* Core */
	res=inf;int next=1;
	for(int p=0;next;p++){lld a=prm[p];
		if(p>=m || a*a>k){
			next=0;if(k==1LL)continue;
			a=k;num=1LL;
		}else{
			if(k%a)continue;
			num=0LL;
			while(!(k%a)){ num++;k/=a; }
		}
		/* operation */
		int i=1;sum=tot=0LL;b=a;
		while(1){
			c[i]=n/b;
			if(n/b<a)break;
			i++;b*=a;
		}c[i+1]=0;
		for(;i;i--){ sum+=(c[i]-c[i+1])*i; }
		/* update */
		//printf("res=%lld a=%lld sum=%lld num=%lld\n",res,a,sum,num);
		res=min(res,sum/num);
	}
	/* printf out */
	//printf("%I64d\n",res);
	cout<<"Case "<<T<<": "<<res<<endl;
}

int main(){
	getprm(s);
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++)work();
	return 0;
}
