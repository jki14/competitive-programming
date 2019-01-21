#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

const int weekdays=7;
const int yearmons=12;

int zero,res1,res2;
int sx,sy,tx,ty;

int after(const int &ax,const int &ay,const int &bx,const int &by){
	if(ax<bx)return 0;
	if(ax==bx)return ay>=by;
	return 1;
}

int Yleap(const int &x){
	if(x<=1582)return (x%4)==0;
	if(x==1700)return 1;
	if(x%4!=0)return 0;
	if(x%400==0)return 1;
	if(x%100==0)return 0;
	return 1;
}

int Mdays(const int &x,const int &y){
	if(x==1752 && y==9)return 19;
	if(y==2)return (Yleap(x))?29:28;
	if(y<8)return (y&1)?31:30;
	return (y&1)?30:31;
}

void work(){
	int x,y,k,kk;x=y=1;k=zero;res1=res2=0;
	//cout<<"zero="<<zero<<endl;
	while(1){
		kk=k+Mdays(x,y)-1;kk%=weekdays;
		//if(after(x,y,sx,sy))cout<<"End Of M : "<<kk<<"  ;Start Of M : "<<k<<endl;
		if(kk==5 || kk==6 || kk==0){
			if(after(x,y,sx,sy))res1++;
		}
		if(k==6 || k==0 || k==1){
			if(after(x,y,sx,sy))res2++;
		}
		k+=Mdays(x,y);k%=weekdays;
		if(x==tx && y==ty)break;
		y++;if(y>yearmons){ x++;y=1; }
	}
	printf("%d %d\n",res1,res2);
}

void init(){
	int x=2006,y=9;zero=5;
	while(1){
		y--;if(!y){ x--;y=yearmons; }
		zero-=Mdays(x,y);
		//printf("Mdays(%d,%d)=%d\n",x,y,Mdays(x,y));
		zero%=weekdays;
		while(zero<0)zero+=weekdays;
		if(x==1 && y==1)break;
	}
}

int main(){
	init();
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
		work();
	}
	return 0;
}
