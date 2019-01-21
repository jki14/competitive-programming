#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<climits>
#include<algorithm>
using namespace std;

int t,n,b;

bool doit(int timer)
{
	scanf("%d %d %d",&t,&n,&b);
	if((!t)&&(!n)&&(!b))return false;
	double tot,s;
	int p;
	tot=0;
	for(int i=0;i<t;i++)
	{
		scanf("%lf %d",&s,&p);
		tot+=s*(double)(100-p)/100;
	}
	printf("Case %d: %.2lf\n",timer,tot/(double)b);
	printf("\n");
	return true;
}

int main()
{
	int t=1;
	while(doit(t++));
	return 0;
}
