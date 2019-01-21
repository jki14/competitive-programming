#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define u i
#define v i+j

#define maxn 1000
#define maxl 500

int m,n;
char s[maxn][maxl],str[maxl];
int f[maxl][maxl];

void updata(const int &k,const int &x){
	int res=0,i=1,j=x+1;
	while(s[k][i] && j<n){
		while(j<n && s[k][i]!=str[j]){
			j++;res++;
		}
		if(s[k][i]==str[j]){ i++;j++; }
	}
	if(!s[k][i] && f[x][j-1]>res)f[x][j-1]=res;
}

void work(){
	int i,j,k;
	memset(f,0x7f,sizeof(f));
	scanf("%s",str);
	for(i=0;i<m;i++)scanf("%s",s[i]);
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			if(s[i][0]==str[j])updata(i,j);
	for(j=0;j<n;j++)
		for(i=0;v<n;i++){
			if(f[u][v]>j+1)f[u][v]=j+1;
			for(k=i;k<v;k++){
				if(f[u][v]>f[u][k]+f[k+1][v])f[u][v]=f[u][k]+f[k+1][v];
			}
		}
	printf("%d\n",f[0][n-1]);
}

int main(){
	while(scanf("%d%d",&m,&n)!=EOF)work();
	return 0;
}
