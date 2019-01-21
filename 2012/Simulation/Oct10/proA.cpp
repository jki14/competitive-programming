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
#include<list>
#include<bitset>
#include<set>
#include<map>
#include<functional>
#include<numeric>
#include<utility>
#include<iomanip>
using namespace std;

const int n = 52;
const int K = 2;
int a[K][n];
int m,l,r,k=0;

int main(){
	int T;scanf("%d",&T);
	for(int tim=1;tim<=T;tim++){printf("Case #%d:",tim);
		for(int i=0;i<n;i++){ scanf("%d",&a[0][i]);a[1][i]=a[0][i]; }
		scanf("%d%d%d",&m,&l,&r);m%=r;l--;
		for(int i=0;i<m;i++){k^=1;int p=0;
			for(int j=l;j<r;j++)a[k][p++]=a[k^1][j];
			for(int j=0;p<r;j++)a[k][p++]=a[k^1][j];
		}
		for(int i=0;i<n;i++)printf(" %d",a[k][i]);
		printf("\n");
	}
	return 0;
}
