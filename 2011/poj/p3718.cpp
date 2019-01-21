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
#define K 3

const int M=10007;

int n,m,q;
int f[maxn][maxn];
int inv[maxn],com[maxn][K+1];
char a[maxn],b[maxn];

int inverse(const int &a,const int &b){
	int k;
	int x1,x2,x3;
	int y1,y2,y3;
	int t1,t2,t3;
	if(!a || !b)return 1;
	x1=1;x2=0;x3=a;
	y1=0;y2=1;y3=b;
	if(x3<y3)swap(x3,y3);
	for(t3=x3%y3;t3!=0;t3=x3%y3){
		k=x3/y3;
		t1=x1-k*y1;
		t2=x2-k*y2;
		x1=y1;x2=y2;x3=y3;
		y1=t1;y2=t2;y3=t3;
	}
	if(y3!=1)return 1;
	//printf("y2=%d\n",y2);
	return (y2%b+b)%b;
}

void init(){
	int i,j;
	for(i=0;i<maxn;i++){
		inv[i]=inverse(i,M);
		//printf("inv[%d]=%d\n",i,inv[i]);
	}
	memset(com,0,sizeof(com));
	com[0][0]=1;
	for(i=1;i<maxn;i++)
		for(j=0;j<=K;j++){
			com[i][j]=com[i-1][j];
			if(j)com[i][j]+=com[i-1][j-1];
			com[i][j]%=M;
			//printf("com[%d][%d]=%d\n",i,j,com[i][j]);
		}
}

void work(){
	int i,j;
	scanf("%s",a);scanf("%s",b);
	for(i=q=0;i<n;i++)if(a[i]!=b[i])q++;
	//printf("Count N=%d M=%d Q=%d\n",n,m,q);
	memset(f,0,sizeof(f));
	f[0][0]=1;
	for(i=1;i<=m;i++){
		for(j=0;j<=n;j++){
			f[i][j]=f[i-1][j+3]*com[n-j][3];f[i][j]%=M;
			if(j>2){
				f[i][j]+=f[i-1][j-3]*com[j][3];f[i][j]%=M;
			}
			f[i][j]+=f[i-1][j+1]*((com[n-j][2]*com[j][1])%M);f[i][j]%=M;
			if(j){
				f[i][j]+=f[i-1][j-1]*((com[n-j][1]*com[j][2])%M);f[i][j]%=M;
			}
			if(i>1){
				int dec=(f[i-2][j]*(com[n][3]-i+2))%M;
				f[i][j]=(f[i][j]-dec+M)%M;
			}
			f[i][j]*=inv[i];f[i][j]%=M;
			//printf("f[%d][%d]=%d\n",i,j,f[i][j]);
		}
	}
	printf("%d\n",f[m][q]);
}

int main(){
	init();
	while(scanf("%d%d",&n,&m)!=EOF && !(n==0 && m==0))
		work();
	return 0;
}

