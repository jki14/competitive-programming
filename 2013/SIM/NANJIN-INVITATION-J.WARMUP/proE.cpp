#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

#define MS 2

typedef long long lld;

const int s=2;
const lld modulo=1000000007LL;

int n,m,k;
lld a[MS][MS],b[MS][MS],ans;

inline void stm(int n,lld A[MS][MS]){
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)A[i][j]=(i==j)?1LL:0LL;
}

inline void mmm(int n,lld C[MS][MS],lld _A[MS][MS],lld _B[MS][MS]){
	lld A[MS][MS],B[MS][MS];
	for(int i=0;i<n;i++)for(int j=0;j<n;j++){ A[i][j]=_A[i][j];B[i][j]=_B[i][j];C[i][j]=0LL; }
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)for(int k=0;k<n;k++)C[i][j]=(C[i][j]+A[i][k]*B[k][j])%modulo;
}

inline void pmm(const int &n,const int &y,lld C[MS][MS],lld X[MS][MS]){
	lld R[MS][MS];for(int i=0;i<n;i++)for(int j=0;j<n;j++)R[i][j]=X[i][j];stm(n,C);
	if(y>0)for(int i=1;;i<<=1){
		if(y&i)mmm(n,C,C,R);
		mmm(n,R,R,R);
		if(i>(y>>1))break;
	}
}

int main(){
	while(scanf("%d%d%d",&n,&m,&k)!=EOF){
		memset(a,0,sizeof(a));a[0][0]=1;
		b[0][0]=m-k;b[0][1]=k;
		b[1][0]=m-k;b[1][1]=k>0?k-1:0LL;
		pmm(s,n,b,b);mmm(s,a,a,b);

		//printf("-----\n%lld|%lld\n%lld|%lld\n-----\n",b[0][0],b[0][1],b[1][0],b[1][1]);

		ans=((a[0][0]+a[0][1])%modulo+modulo)%modulo;
		printf("%lld\n",ans);
	}
	return 0;
}
