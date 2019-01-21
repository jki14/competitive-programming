#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

typedef long long lld;

const double eps=1e-4;

int T;
int pd,pg;

lld n;

lld getk(int x,int y){
	int lmt=min(x,y);
	for(int i=2;i<=lmt;i++){
		while(x%i==0 && y%i==0){ x/=i;y/=i; }
	}
	return (lld)y;
}

void work(){
	scanf("%lld%d%d",&n,&pd,&pg);
	//int ad,wd,ld;
	/*for(ad=1;ad<=n;ad++){
		wd=getk(ad,pd);
		if(wd==-1)continue;
		ld=ad-wd;
		if(ld!=0 && pg==100)continue;
		if(wd!=0 && pg==0)continue;
		printf("Case #%d: Possible\n",T);
		return;
	}*/
	if((pd!=100 && pg==100)
		||(pd!=0 && pg==0)
		||(getk(pd,100)>n)){
		printf("Case #%d: Broken\n",T);
		return;
	}
	printf("Case #%d: Possible\n",T);
}

int main(){
	freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++)work();
	fclose(stdin);fclose(stdout);
}

