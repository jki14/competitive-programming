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

#define N 110
#define M 40
#define T 109

const int m = 31;
const int modulo = 1000007;

int a[N][N],bit[M],n,ret;

int gaus(){
	int i,j,p,k;
	for(i=j=0;i<n && j<m;){
		p=i;
		for(k=p+1;k<n;k++)
			if(a[p][j]<a[k][j])p=k;
		if(a[p][j]){
			swap(a[i][T],a[p][T]);
			for(k=j;k<m;k++)swap(a[i][k],a[p][k]);

			for(p=i+1;p<n;p++){
				if(!a[p][j])continue;
				a[p][T]^=a[i][T];
				for(k=j;k<n;k++)
					a[p][k]^=a[i][k];
			}
			i++;
		}
		j++;
	}

	int ret=1;
	for(k=i;k<n;k++)ret=ret*2%modulo;
	return ret%modulo;
}

void work(){
	scanf("%d",&n);memset(a,0,sizeof(a));
	for(int i=0;i<n;i++){
		int val;scanf("%d",&val);
		for(int j=0;j<m && bit[j]<=val;j++)a[i][j]=(val&bit[j])?1:0;
	}
	printf("%d\n",gaus());
}

int main(){
	for(int i=0;i<m;i++)bit[i]=1<<i;
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}

