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

int n;
double f[N];

int main(){
	f[1]=1.0;for(int i=2;i<N;i++)f[i]=f[i-1]+1.0/(2.0*((double)i));
	while(scanf("%d",&n)!=EOF)printf("%.2f\n",f[n]);
	return 0;
}
