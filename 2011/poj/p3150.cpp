#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

#define maxn 510
#define maxk 11000000
#define logK 30

typedef long long lld;

lld M[logK][maxn],tmpM[maxn];
lld a[maxn],res[maxn],m;
int n,d,k;

lld getcm(const int &i,const int &x,const int &y){
	int k=y-x;
	while(k<0)k+=n;
	while(k>=n)k%=n;
	return M[i][k];
}

void work(){
	int i,j,x;
	lld tmp;
	memset(M,0,sizeof(M));
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	//init Matrix
	M[0][0]=1LL;
	for(i=0;i<n;i++)if(i<=d || n-i<=d)M[1][i]=1LL;
	//get m
	for(j=2;(1<<(j-1))<=k;j++){
		for(i=0;i<n;i++){
			tmp=0LL;
			for(x=0;x<n;x++)
				tmp+=getcm(j-1,0,x)*getcm(j-1,x,i);
			M[j][i]=tmp%m;
		}
	}
	//update M[0]
	for(j=1;(1<<(j-1))<=k;j++){
		if(((1<<(j-1))&k)==0)continue;
		for(i=0;i<n;i++){
			tmpM[i]=0LL;
			for(x=0;x<n;x++){
				tmpM[i]+=getcm(0,0,x)*getcm(j,x,i);
				//printf("tmp+=M[%d][%d][%d](%lld)*M[%d][%d][%d](%lld)\n",0,0,x,getcm(0,0,x),j,x,i,getcm(j,x,i));
			}
			//printf("M[0][%d]=%lld\n",i,tmp);
		}
		for(i=0;i<n;i++)M[0][i]=tmpM[i]%m;
	}
	//for(i=0;i<n;i++)M[0][i]=tmpM[i];
	//debug put M[0]
	/*printf("M[0]={ ");
	for(i=0;i<n;i++)printf("%lld ",M[0][i]);
	printf("}\n");*/
	//get res
	memset(res,0,sizeof(res));
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			res[i]+=a[j]*getcm(0,i,j);
			res[i]%=m;
		}
	//return res
	for(i=0;i<n;i++)
		printf("%lld ",res[i]);
	printf("\n");
}

int main(){
	while(scanf("%d%lld%d%d",&n,&m,&d,&k)!=EOF)work();
	return 0;
}
