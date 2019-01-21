#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
#include <map>
using namespace std;

#define maxn 11
#define maxm 1100
#define maxl 110

map<char,double> s;

int n,m,len;
double p,f[maxm][maxm];
char str[maxl];

void work(){
	int i,j;
	double d;
	p=1;
	memset(f,0,sizeof(f));
	s.clear();for(i=0;i<n;i++){
		scanf("%s%lf",str,&d);
		s[str[0]]=d;
	}
	scanf("%s",str);len=strlen(str);
	for(i=0;i<len;i++)
		p*=s[str[i]];
	for(i=0;i<len;i++)f[i][0]=1;
	for(i=len;i<=m;i++){
		f[i][0]=1;
		for(j=1;j<=i;j++){
			f[i][j]=f[i-len][j-1]*p;
			f[i][j]+=f[i-1][j];
			cout<<"f["<<i<<"]["<<j<<"]="<<f[i][j]<<endl;
			f[i][0]-=f[i][j];
		}
		cout<<"f["<<i<<"]["<<0<<"]="<<f[i][0]<<endl;
	}
	cout<<1-f[m][0]<<endl;
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF && !(n==0 && m==0))work();
	return 0;
}
