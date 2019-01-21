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

int n,m;
int f[maxn][maxn];
char a[maxn],b[maxn];

void work(){
	int i,j;
	memset(f,0,sizeof(f));
	n=strlen(a);m=strlen(b);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++){
			f[i][j]=max(f[i-1][j],f[i][j-1]);
			if(a[i-1]==b[j-1])f[i][j]=max(f[i][j],f[i-1][j-1]+1);
		}
	printf("%d\n",f[n][m]);
}

int main(){
	while(scanf("%s%s",a,b)!=EOF)work();
	return 0;
}

