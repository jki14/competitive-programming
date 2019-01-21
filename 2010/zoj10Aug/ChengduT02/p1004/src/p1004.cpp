#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define maxn 210000

const int modd = 10007;

int n,f[maxn],g[maxn],sum;
char str[maxn];

void makef(char *t,int lt){
	for(int i=0,j=-1;i<=lt;i++,j++){
		f[i]=j;
		while(j!=-1 && t[i]!=t[j])j=f[j];
	}
}

void work(){
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	scanf("%s",str);
	makef(str,n);sum=n;
	for(int i=1;i<=n;i++)
		if(f[i]){
			g[i]=g[f[i]]+1;g[i]%=modd;
			sum+=g[i];sum%=modd;
		}
	printf("%d\n",sum%modd);
}

int main(){
	int t;scanf("%d",&t);
	while(t--){ scanf("%d",&n);work(); }
}
