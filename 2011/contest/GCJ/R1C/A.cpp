#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

#define maxn 60
#define maxm 60

int T;
int n,m;
char a[maxn][maxm];
int v[maxn][maxm];

int work(){
	int i,j;
	scanf("%d%d",&n,&m);
	memset(v,0,sizeof(v));
	for(i=0;i<n;i++)scanf("%s",a[i]);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(v[i][j] || a[i][j]=='.')continue;
			if(j+1>=m || a[i][j+1]=='.')return 0;
			if(i+1>=n || a[i+1][j]=='.')return 0;
			if(a[i+1][j+1]=='.')return 0;
			v[i][j]='/';
			v[i][j+1]='\\';
			v[i+1][j]='\\';
			v[i+1][j+1]='/';
		}
	}
	return 1;
}

int main(){
	freopen("A.in","r",stdin);freopen("A.out","w",stdout);
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++){
		printf("Case #%d:\n",T);
		if(work())
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					if(!v[i][j])
						printf(".");
					else
						printf("%c",v[i][j]);
				}
				printf("\n");
			}
		else
			printf("Impossible\n");
	}
	fclose(stdin);fclose(stdout);
}

