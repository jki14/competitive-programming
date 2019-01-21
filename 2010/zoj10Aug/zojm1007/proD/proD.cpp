#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<climits>
#include<algorithm>
using namespace std;

void doit()
{
	double a,b,c;
	scanf("%lf %lf %lf",&a,&b,&c);
	if(1/a+1/b+1/c<1)
		printf("Aha\n");
	else
		printf("No way\n");
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)doit();
	return 0;
}
