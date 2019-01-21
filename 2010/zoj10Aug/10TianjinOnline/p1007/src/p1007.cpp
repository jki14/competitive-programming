#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define i q
#define n p

int i,j,n,k,t;
double b[1000][1000];

int main()
{
	int i,j;
	for (i=1;i<=30;i++)
	{
		b[i][i]=1;
		b[i][0]=0;
	}
	for (i=2;i<=20;i++)
		for (j=1;j<i;j++)
			b[i][j]=b[i-1][j-1]/i+b[i-1][j]*(i-1)/i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		printf("%0.4lf\n",b[n-1][k]*(n-1)/n);
	}
	return 0;
}
