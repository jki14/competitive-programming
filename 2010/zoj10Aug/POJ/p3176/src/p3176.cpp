#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define maxn 500

#define max(x,y) ((x>y)?x:y)

int n;
int a[maxn][maxn],f[maxn][maxn];

void work(){
	int i,j;
	memset(f,0,sizeof(f));
	for(i=0;i<n;i++)
		for(j=0;j<=i;j++){
			scanf("%d",&a[i][j]);
		}
	for(i=n-1;i>=0;i--)
		for(j=0;j<=i;j++){
			f[i][j]=max(f[i+1][j],f[i+1][j+1])+a[i][j];
		}
	/*for(i=0;i<n;i++){
		for(j=0;j<=i;j++)
			cout<<f[i][j]<<" ";
		cout<<endl;
	}*/
	printf("%d\n",f[0][0]);
}

int main(){
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}
