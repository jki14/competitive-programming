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

#define LEN 21
#define C 10

typedef long long lld;

const double eps = 1e-8;

int num4,num7,que,len,T;
lld lef,rig;
lld low,hig;
lld f[LEN][LEN][LEN];

lld pow(const lld &x,int y){
	lld a=x,res=1LL;
	for(;y;y>>=1){
		if(y&1)res*=a;
		a=a*a;
	}
	return res;
}

lld com(const int &x,const int &y){
	if(x<y)return 0LL;lld res=1LL;
	for(int i=x,j=1;j<=y;i--,j++)res=res*((lld)i)/((lld)j);
	return res;
}

lld lownum(lld x){/* <=x */

	//printf("lownum %lld\n",x);

	int k=len;lld bas=pow(10LL,len-1),res=0LL;
	int cnt4=num4,cnt7=num7,num;
	/* first case */
	num=x/bas;x%=bas;
	for(int i=0;i<=num;i++){
		if((i==4 && cnt4==0) || (i==7 && cnt7==0))continue;
		res+=f[k-1][(i==4)?cnt4-1:cnt4][(i==7)?cnt7-1:cnt7];
		//printf("i=%d res=%lld\n",i,res);
	}
	//printf("k=%d cnt4=%d cnt7=%d num=%d res=%lld\n",k,cnt4,cnt7,num,res);
	if(num==4)
		cnt4--;
	else if(num==7)cnt7--;
	k--;bas/=10LL;
	/* second case */
	for(;k>0;k--,bas/=10LL){num=x/bas;x%=bas;
		for(int i=num+1;i<=9;i++){
			if((i==4 && cnt4==0) || (i==7 && cnt7==0))continue;
			res-=f[k-1][(i==4)?cnt4-1:cnt4][(i==7)?cnt7-1:cnt7];
			//printf("		f[%d][%d][%d]=%lld\n",k-1,(i==4)?cnt4-1:cnt4,(i==7)?cnt7-1:cnt7,f[k-1][(i==4)?cnt4-1:cnt4][(i==7)?cnt7-1:cnt7]);
			//printf("i=%d res=%lld\n",i,res);
		}
		if(num==4){
			if(!cnt4)break;
			cnt4--;
		}
		else if(num==7){
			if(!cnt7)break;
			cnt7--;
		}
		//printf("k=%d cnt4=%d cnt7=%d num=%d res=%lld\n",k,cnt4,cnt7,num,res);
	}
	return res;
}



void build(){
	memset(f,0,sizeof(f));
	for(int k=0;k<=len;k++){
		for(int i=0;i<=k;i++){
			for(int j=0;i+j<=k;j++){
				lld free=k-i-j;
				f[k][i][j]=pow(8LL,free)*com(free+i,i)*com(k,j);
			}
		}
	}
}

lld core(lld x){
	lld res=0LL;int cnt4=num4,cnt7=num7,num;
	for(int k=len;k;k--){
		for(num=0;(num==4 && !cnt4) || (num==7 && !cnt7) || f[k-1][(num==4)?cnt4-1:cnt4][(num==7)?cnt7-1:cnt7]<x;num++){
			if((num==4 && cnt4==0) || (num==7 && cnt7==0))continue;
			x-=f[k-1][(num==4)?cnt4-1:cnt4][(num==7)?cnt7-1:cnt7];
			//printf("f[%d][%d][%d]=%lld\n",k-1,(num==4)?cnt4-1:cnt4,(num==7)?cnt7-1:cnt7,f[k-1][(num==4)?cnt4-1:cnt4][(num==7)?cnt7-1:cnt7]);
			//printf("num=%d x=%lld\n",num,x);	
		}
		res=res*10LL+((lld)num);
		if(num==4)
			cnt4--;
		else if(num==7)cnt7--;
	}return res;
}

void work(){
	scanf("%I64d%I64d",&lef,&rig);scanf("%d%d",&num4,&num7);
	len=ceil(log((double)rig)/log(10.0)+eps);build();
	//printf("rig=%lld len=%d\n",rig,len);
	low=lownum(lef);hig=lownum(rig);
	//printf("low=%lld hig=%lld\n",low,hig);
	printf("Case #%d:\n",T);
	scanf("%d",&que);for(;que;que--){
		lld k;scanf("%I64d",&k);
		if(low+k>hig){
			printf("Nya!\n");
			continue;
		}
		printf("%I64d\n",core(low+k));
	}
}

int main(){
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++)work();
	return 0;
}

