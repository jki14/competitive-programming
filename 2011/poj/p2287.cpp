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

int n,res;
int a[maxn],b[maxn];
int f[maxn][maxn];

int cost(const int &x,const int &y){
	if(a[x]==b[y])return 0;
	return (a[x]>b[y])?200:-200;
}

void work(){
	int i,j;res=LONG_MIN;
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	for(i=0;i<n;i++)scanf("%d",&b[i]);
	sort(a,a+n);sort(b,b+n);
	memset(f,0x8f,sizeof(f));f[0][0]=0;
	for(i=0;i<n;i++)
		for(j=0;j<=i;j++){
			f[i+1][j]=max(f[i+1][j],f[i][j]+cost(i,n-i+j-1));
			f[i+1][j+1]=max(f[i+1][j+1],f[i][j]+cost(i,j));
		}
	for(i=0;i<=n;i++)res=max(res,f[n][i]);
	printf("%d\n",res);
}

int main(){
	while(scanf("%d",&n)!=EOF && n)
		work();
	return 0;
}

