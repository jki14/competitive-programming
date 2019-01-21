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
#include<set>
#include<map>
using namespace std;

#define N 10

double eps=1e-8;

int n,k,pos;
int vot[N],giv[N];
double ans,tans,ret;

double lev[N],loy[N],a;

double kill(){
	double sum=a;
	for(int i=0;i<n;i++)
		if(!vot[i])sum+=lev[i];
	return a/sum;
}

void vote(const int &x){
	if(x==n){
		if(pos>n-pos)
			tans+=ret;
		else
			tans+=ret*kill();
		
		return;
	}
	//pos
	if(loy[x]>eps){vot[x]=1;
		ret*=min(1.0,loy[x]);pos++;
		vote(x+1);
		ret/=min(1.0,loy[x]);pos--;
	}
	//neg
	if(1.0-loy[x]>eps){vot[x]=0;
		ret*=min(1.0,1.0-loy[x]);
		vote(x+1);
		ret/=min(1.0,1.0-loy[x]);
	}
}

void give(const int &x,const int &low){
	if(x==k){
		tans=0.0;vote(0);
		ans=max(ans,tans);
		return;
	}
	for(int i=low;i<n;i++){
		loy[i]+=0.1;
		give(x+1,i);
		loy[i]-=0.1;
	}
}

void work(){ans=0.0;ret=1.0;
	for(int i=0;i<n;i++){
		scanf("%lf%lf",&lev[i],&loy[i]);
		loy[i]/=100.0;
	}
	give(0,0);
	printf("%.10f\n",ans+eps);
}

int main(){
	while(scanf("%d%d%lf",&n,&k,&a)!=EOF)
	/*scanf("%d%d%lf",&n,&k,&a);*/work();
	return 0;
}
