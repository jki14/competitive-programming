#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

const int lmtn=12345,lmtm=123,lmtk=123456;

int n,m,k;
int bird[lmtn],life[lmtk];
int maxkill[lmtn][lmtm];
int minlife[lmtn][lmtm];

int max(const int &x,const int &y){
	return (x>y)?x:y;
}

bool doit()
{
	int newkill,newlife,ans;
	ans=0;
	memset(life,0x7f,sizeof(life));
	memset(maxkill,0x8f,sizeof(maxkill));
	maxkill[0][0]=0;
	memset(minlife,0x7f,sizeof(minlife));
	for(int i=1;i<=n;i++)scanf("%d",&bird[i]);
	for(int i=1;i<=k;i++)scanf("%d",&life[i]);
	minlife[0][0]=life[1];
	int killonce,power;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			if(!(maxkill[i][j]<0))
			{
				newkill=maxkill[i][j];newlife=minlife[i][j];killonce=false;power=bird[i+1];power*=2;
				while(power>0 || newlife==0)
				{
					if(power>=newlife)
					{
						power-=newlife;
						newlife=life[newkill+2];
						newkill++;killonce=true;
						if(i+1<=n && j+1<=m && ans<newkill)ans=newkill;
					}else{
						if(killonce==false)newlife-=power;
						power=0;
					}
				}
				if(maxkill[i+1][j+1]<newkill || (maxkill[i+1][j+1]==newkill && minlife[i+1][j+1]>newlife)){
					maxkill[i+1][j+1]=newkill;minlife[i+1][j+1]=newlife;
				}

				newkill=maxkill[i][j];newlife=minlife[i][j];killonce=false;power=bird[i+1];
				while(power>0 || newlife==0)
				{
					if(power>=newlife)
					{
						power-=newlife;
						newlife=life[newkill+2];
						newkill++;killonce=true;
						if(i+1<=n && j<=m && ans<newkill)ans=newkill;
					}else{
						if(killonce==false)newlife-=power;
						power=0;
					}
				}
				if(maxkill[i+1][j]<newkill || (maxkill[i+1][j]==newkill && minlife[i+1][j]>newlife)){
					maxkill[i+1][j]=newkill;minlife[i+1][j]=newlife;
				}
			}
	if(ans>k)ans=k;printf("%d\n",ans);
	return true;
}

int main()
{
	while(scanf("%d%d%d",&n,&m,&k) && !(n==0 && m==0 && k==0))
		doit();
	return 0;
}
