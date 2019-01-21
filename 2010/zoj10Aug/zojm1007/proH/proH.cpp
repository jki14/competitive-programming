#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<climits>
#include<algorithm>
using namespace std;

const int t=2,p=11,k=3,maxc=5,maxl=15;

bool f[t][p][k];
int s[t];
char line[maxl],tmp;

void pres(const int &timer)
{
	printf("Match %d:\n",timer);
	if(s[0]>s[1])
		printf("Winner: home");
	else
		printf("Winner: away");
	printf("\nScore: %d:%d\n",s[0],s[1]);
}

bool end(const int &x,const int &i)
{
	if((s[0]-s[1])>(5-((x==0)?i:(i+1))))return true;
	if((s[1]-s[0])>(4-i))return true;
	return false;
}

void doit(const int &timer)
{
	int x,i,j;
	char kick[k][maxc];
	memset(f,0,sizeof(f));
	memset(s,0,sizeof(s));
	for(x=0;x<t;x++)
		for(i=0;i<p;i++)
		{
			
			for(j=0;j<k;j++)
			{
				scanf("%s",kick[0]);

				if(kick[0][0]=='y')
				{
					f[x][i][j]=true;
					//cout<<"Get:"<<x<<" "<<i<<" "<<k<<" "<<endl;
				}
			}
		}
	//the fir-five
	i=0;j=0;
	//cout<<"000:"<<f[0][0][0]<<endl;
	while(i<5)
	{
		for(x=0;x<t;x++)
		{
			if(f[x][i][j])
				//cout<<"Get:"<<x<<";"<<i<<";"<<j<<endl;
				s[x]++;
			if(end(x,i))
			{
				//cout<<x<<" "<<i<<" "<<j<<endl;
				//cout<<s[0]-s[1]<<" "<<(5-((x==0)?i:(i+1)))<<endl;
				pres(timer);
				return;
			}
		}
		i++;
	}
	if(s[0]!=s[1])
	{
		pres(timer);
		return;
	}
	//continue
	while(j<k)
	{
		while(i<p)
		{
			for(x=0;x<t;x++)
				if(f[x][i][j])
					s[x]++;
			if(s[0]!=s[1])
			{
				pres(timer);
				return;
			}
			i++;
		}
		j++;i=0;
	}
}

int main()
{
	int i,caset;
	gets(line);
	sscanf(line,"%d",&caset);
	for(i=1;i<=caset;i++)
		doit(i);
	return 0;
}
