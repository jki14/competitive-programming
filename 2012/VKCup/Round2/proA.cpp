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

#define L 5100

const int modulo=1000000007;

int n,m,ans;
int f[L][L];
char s[L],t[L];

void work(){
	scanf("%s",t);n=strlen(s);m=strlen(t);ans=0;
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			f[i][j]=f[i][j-1];
			if(s[i-1]==t[j-1])f[i][j]=(f[i][j]+f[i-1][j-1]+1) % modulo;
		}
		ans=(ans+f[i][m]) % modulo;
	}
	printf("%d\n",ans % modulo);
}

int main(){
	while(scanf("%s",s)!=EOF)work();
	return 0;
}

