#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define _k k^1

const int maxk=2;

int timer;
int n,d;
double ans;

bool doit()
{
	scanf("%d %d",&n,&d);
	if((!n)&&(!d))return false;
	int p[maxk],l[maxk],v[maxk],k=0;
	ans=0;p[k]=0;l[k]=0;v[k]=0;
	while(n--)
	{
		k=_k;
		scanf("%d %d %d",&p[k],&l[k],&v[k]);
		ans+=p[k]-(p[_k]+l[_k]);
		ans+=2*(double)l[k]/(double)v[k];
	}
	ans+=d-(p[k]+l[k]);
	printf("Case %d: %.3lf\n\n",timer,ans);
	return true;
}

int main()
{
	timer=1;
	while(doit())timer++;
	return 0;
}
