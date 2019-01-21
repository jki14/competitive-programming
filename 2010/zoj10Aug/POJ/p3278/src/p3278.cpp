#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define p s[h]

#define maxn 110000
#define lmt maxn*2

int n,m;
int f[lmt];
int s[lmt*2];

int up(const int &x,const int &y){
	if(x<0 || x>lmt)return 0;
	if(f[x]<=y)return 0;
	f[x]=y;return 1;
}

int work(){
	memset(f,0x7f,sizeof(f));
	int h=0,t=1;s[h]=n;f[n]=0;
	while(h<t){
		if(up(p-1,f[p]+1))s[t++]=p-1;
		if(up(p+1,f[p]+1))s[t++]=p+1;
		if(up(p*2,f[p]+1))s[t++]=p*2;
		if(f[m]<lmt)return f[m];
		h++;
	}
	return -1;
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF)
		printf("%d\n",work());
	return 0;
}
