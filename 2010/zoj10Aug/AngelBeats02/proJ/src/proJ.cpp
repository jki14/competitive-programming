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

#define pre now^1

#define maxlen 20
#define maxm 1100

double f[2][maxm][maxlen];
double p[maxlen],g[maxm];
int n,m,len;
char str[maxlen],tmp[maxlen];

map<char,double> s;

void work(){
	int i,j,k,now=1;
	double val;
	s.clear();for(i=0;i<n;i++){
		scanf("%s%lf",tmp,&val);
		s[tmp[0]]=val;
	}
	scanf("%s",str);len=strlen(str);
	for(i=0;i<len;i++)p[i+1]=s[str[i]];
	memset(f,0,sizeof(f));memset(g,0,sizeof(g));
	f[pre][0][0]=1;g[0]=1;
	for(i=1;i<=m;i++,now=pre){
		int lmt=i/len;
		for(j=0;j<=lmt;j++){
			f[now][j][0]=g[j];
			for(k=1;k<=len;k++){
				f[now][j][k]=f[pre][j][k-1]*p[k];
				cout<<"f["<<i<<"]["<<j<<"]["<<k<<"]="<<f[now][j][k]<<endl;
				f[now][j][0]-=f[now][j][k];
			}
			cout<<"f["<<i<<"]["<<j<<"]["<<0<<"]="<<f[now][j][0]<<endl;
			g[j+1]+=f[now][j][len];
			g[0]-=f[now][j][len];
		}
	}
	printf("%.2f\%\n",(1-g[0])*100);
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF && !(n==0 && m==0))work();
	return 0;
}
