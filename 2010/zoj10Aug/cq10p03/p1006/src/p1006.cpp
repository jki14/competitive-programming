#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

const int maxl=1100,maxm=1100000,zero=(int)'0';

char s[maxl];
int n,m;
long long ans,k;

int slength(char *s)
{
	int k=0;
	while(s[k])k++;
	return k;
}

int stonum(char *s)
{
	int i=0,k=0;
	while(s[i])
	{
		k*=10;
		k+=(int)s[i]-zero;
		i++;
	}
	return k;
}

void doit()
{
	long long i;
	scanf("%s %d",s,&m);
	if(slength(s)>7)
		n=m;
	else
		n=stonum(s);
	if(n>m)n=m;
	ans=1%m;
	k=ans;
	//cout<<n<<","<<m<<endl;
	for(i=1;i<=(long long)n;i++)
	{
		k*=i;
		while((k>(long long)m)||(k<0))k%=(long long)m;
		if(!k)break;
		ans+=k;
		while((ans>(long long)m)||(ans<0))ans%=(long long)m;
	}
	printf("%d\n",(int)ans);
}

int main()
{
	int t;scanf("%d",&t);
	while(t--)doit();
}
