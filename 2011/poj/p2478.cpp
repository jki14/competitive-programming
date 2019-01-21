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

#define maxn 1100000

const int N=1000000;
const double eps=1e-4;

int n;
double phi[maxn],s[maxn];

void SetPhi(int n){
	int i,j;
	phi[0]=phi[1]=0.0;
	for(i=2;i<=n;i++)phi[i]=(double)i;
	for(i=2;i<=n;i+=2)phi[i]/=2;
	for(i=3;i<=n;i+=2){double di=(double)i;
		if(fabs(phi[i]-di)<eps)
			for(j=i;j<=n;j+=i)
				phi[j]*=1.0-1.0/di;
	}
}

void init(){
	SetPhi(N);
	for(int i=2;i<=N;i++)s[i]=s[i-1]+phi[i];
}

void work(){
	printf("%.0f\n",s[n]);
}

int main(){
	init();
	while(scanf("%d",&n)!=EOF && n)
		work();
	return 0;
}

