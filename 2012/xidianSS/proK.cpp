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
#include<queue>
#include<deque>
#include<set>
#include<map>
using namespace std;

#define N 1000010

const int modulo = 100000007;

int f[N],n;

int main(){
	f[0]=0%modulo;for(int i=1;i<N;i++)f[i]=((((f[i-1]+f[i-1])%modulo)+f[i-1])%modulo+2);
	while(scanf("%d",&n)!=EOF && n!=-1)printf("%d\n",f[n]);
	return 0;
}
