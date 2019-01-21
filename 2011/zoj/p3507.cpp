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

#define maxn 110

typedef long long lld;

int T;

int n,m,k;
char a[maxn][maxn];
lld N[maxn],M[maxn];

char getc(lld x,lld y){
	for(int i=k-1;i>0;i--){
		if(a[x/N[i]][y/M[i]]==' ')return ' ';
		x%=N[i];y%=M[i];
	}
	//x=x%N[1];if(x<0)x+=N[1];
	//y=y%M[1];if(y<0)y+=M[1];
	return a[x%N[1]][y%M[1]];
}

void work(){T++;
	int i,j;
	lld x,y,bk;
	char chr;
	memset(a,0,sizeof(a));
	scanf("%c",&a[0][0]);
	for(i=0;i<n;i++)
		for(j=0;j<=m;j++)
			scanf("%c",&a[i][j]);
	scanf("%d",&k);
	N[0]=M[0]=1LL;
	N[1]=(lld)n;M[1]=(lld)m;
	for(i=2;i<=k;i++){
		N[i]=N[i-1]*N[1];
		M[i]=M[i-1]*M[1];
	}
	if(T>1)printf("\n");
	printf("Fractal #%d:\n",T);bk=0LL;
	for(x=y=0;x<N[k];y++){if(y==M[k]){ x++;y=-1LL;printf("\n");bk=0LL;continue; }
		chr=getc(x,y);
		if(chr==' '){ bk++;continue; }
		for(;bk>0LL;bk--)printf(" ");
		printf("%c",chr);
	}
	//printf("\n");
}

int main(){
	T=0;while(scanf("%d%d",&n,&m)!=EOF)work();
	return 0;
}

