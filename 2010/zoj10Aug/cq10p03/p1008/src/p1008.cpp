#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

const int maxl=110;

char s[maxl],l[maxl],r[maxl];

int slength(char *s)
{
	int k=0;
	while(s[k])k++;
	return k;
}

int findp(char *s)
{
	int k=0;
	while(s[k])
	{
		if(s[k]==':')return k;
		k++;
	}
	return -1;
}

void doit()
{
	scanf("%s",s);
	int n=slength(s),i,p;
	if((s[0]=='\\')||(s[0]=='/'))
	{
		printf("It's a path in Unix-like systems!\n");
		for(i=0;i<=n;i++)
			if(s[i]=='\\')s[i]='/';
		printf("%s\n",s);
		return;
	}
	p=findp(s);p+=2;
	if((s[p])&&((s[p]=='\\')||(s[p]=='/')))
	{
		printf("It's a URL!\n");
		for(i=0;i<=n;i++)
			if(s[i]=='\\')s[i]='/';
				printf("%s\n",s);
		return;
	}
	else
	{
		printf("It's a path in Windows system!\n");
		for(i=0;i<=n;i++)
			if(s[i]=='/')s[i]='\\';
				printf("%s\n",s);
		return;
	}
}

int main()
{
	int t;scanf("%d",&t);
	while(t--)doit();
	return 0;
}
