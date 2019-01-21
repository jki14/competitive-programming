#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<climits>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<set>
#include<map>
using namespace std;

#define maxnum 50000
#define maxlen 30
#define LEN 8
#define l18 18
#define i12 12

const int inf=LONG_MAX;
const int MOD=11;
const int zero=(int)'0';

const int w[l18]= { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2,1  };

int  num,n;
char a[maxlen];
int  sum[maxnum],ret;
char str[maxnum][maxlen],res[maxlen];

int allow(const int &y,const int &m,const int &d){
	if(y>2011)return 0;
	if(y<2011)return 1;
	if(m>4)return 0;
	if(m<4)return 1;
	return d<=2;
}

int leap(const int &y){
	if(y%400==0)return 1;
	if(y%100==0)return 0;
	return (y%4 == 0);
}

int mday(const int &y,const int &m){
	if(m==2)return leap(y)?29:28;
	if(m<8)return (m&1)?31:30;
	return (m&1)?30:31;
}

void next(int &y,int &m,int &d){
	d++;
	if(d>mday(y,m)){ m++;d=1; }
	if(m>12){ y++;m=1; }
}

void init(){
	int i,y,m,d;num=0;
	for(y=1900,m=1,d=1;allow(y,m,d);next(y,m,d)){
		sprintf(str[num],"%d%02d%02d",y,m,d);
		for(sum[num]=i=0;i<LEN;i++)sum[num]=(sum[num]+((int)str[num][i]-zero)*w[i+6])%MOD;
		num++;
	}
}

void work(){
	int i,j,k,p,tot,cost;
	ret=inf;
	scanf("%s",a);
	n=strlen(a);

	for(i=0;i<=n;i++)res[i]=a[i];
	
	//printf("res=%s\n",res);

	if(n==15){
		for(i=0;i<num;i++){cost=0;
			for(j=2;j<LEN;j++)if(str[i][j]!=a[4+j])cost++;
			if(cost<ret){
				ret=cost;
				for(j=2;j<LEN;j++)res[4+j]=str[i][j];
			}
		}	
	}else{
		for(tot=i=0;i<n-1;i++){
			if(i==6)i+=8;
			tot=(tot+((int)a[i]-zero)*w[i])%MOD;
		}
		if(a[n-1]=='X')k=10;else k=(int)a[n-1]-zero;
		for(i=0;i<num;i++){cost=0;
			for(j=0;j<LEN;j++)if(str[i][j]!=a[6+j])cost++;
			if((p=((i12-((tot+sum[i])%MOD))%MOD))!=k)cost++;
			if(cost<ret){
				ret=cost;
				for(j=0;j<LEN;j++)res[6+j]=str[i][j];
				res[n-1]=(p==10)?'X':'0'+p;
			}
		}
	}

	//printf("ret=%d\n",ret);

	printf("%s\n",res);
}

int main(){
	int t;scanf("%d",&t);
	init();

	//printf("num=%d\n",num);
	//printf("%s\n",str[num-7]);

	while(t--)work();
	return 0;
}

