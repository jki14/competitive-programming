#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

const double eps=1e-4;

int T;
int n,pd,pg;

int equal(const double &x,const double &y){
	return fabs(x-y)<eps;
}

int getk(const int &x,const int &y){
	int i;double d;
	d=((double)x)/100.0*((double)y);
	i=(int)d;
	if(equal(d,(double)i))
		return i;
	else
		return -1;
}

void work(){
	scanf("%d%d%d",&n,&pd,&pg);
	int ad,wd,ld;
	for(ad=1;ad<=n;ad++){
		wd=getk(ad,pd);
		if(wd==-1)continue;
		ld=ad-wd;
		if(ld!=0 && pg==100)continue;
		if(wd!=0 && pg==0)continue;
		printf("Case #%d: Possible\n",T);
		return;
	}
	printf("Case #%d: Broken\n",T);
}

int main(){
	freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++)work();
	fclose(stdin);fclose(stdout);
}

