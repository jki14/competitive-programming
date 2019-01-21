#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define maxy 11000
#define maxm 13

#define yy 10000
#define mm 12

const int md[13]={0,31,0,31,30,31,30,31,31,30,31,30,31};

int sum1[maxy][maxm],sum2[maxy][maxm];
int sd[maxy][maxm],ed[maxy][maxm];

int preMed(const int &x,const int &y){ return (y>1)?ed[x][y-1]:ed[x-1][12]; }

int preMsum1(const int &x,const int &y){ return (y>1)?sum1[x][y-1]:sum1[x-1][12]; }

int preMsum2(const int &x,const int &y){ return (y>1)?sum2[x][y-1]:sum2[x-1][12]; }

int weekday(const int &x){ int d=(x+5)%7;return (d==0)?7:d; }

int leap(const int &x){
	if(x==1700)return 1;
	if(x<1582)
		return (x%4==0)?1:0;
	if(x%400==0)return 1;
	if(x%100==0)return 0;
	return (x%4==0)?1:0;
}

int Mday(const int &x,const int &y){
	if(x==1752 && y==9)return 19;
	if(y!=2)return md[y];
	return (leap(x))?29:28;
}

int main(){
	memset(sum1,0,sizeof(sum1));
	memset(sum2,0,sizeof(sum2));
	ed[0][12]=0;
	for(int i=1;i<yy;i++)
		for(int j=1;j<=mm;j++){
			sd[i][j]=preMed(i,j)+1;
			ed[i][j]=sd[i][j]+Mday(i,j)-1;
		}
	for(int i=1;i<yy;i++)
		for(int j=1;j<=mm;j++){
			sum1[i][j]=preMsum1(i,j);if(weekday(ed[i][j])>=5)sum1[i][j]+=1;
			sum2[i][j]=preMsum2(i,j);if(weekday(sd[i][j])>5 || weekday(sd[i][j])==1)sum2[i][j]+=1;
		}
	int t;scanf("%d",&t);
	while(t--){
		int sx,sy,ex,ey;scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
		//for(int i=sy-1;i<=ey;i++)cout<<sum1[sx][i]<<" ";
		printf("%d %d\n",sum1[ex][ey]-preMsum1(sx,sy),sum2[ex][ey]-preMsum2(sx,sy));
	}
}
