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

#define K 5

const int inf=0x3fffffff;
const int low=2000;

const double eps=1e-4;

const int a[K]={ 180000,300000,400000,300000,inf };
const double b[K]={ 0.0,0.10,0.15,0.20,0.25 };

int T,n,ans;
double res;

void work(){
	scanf("%d",&n);res=0.0;
	for(int i=0;i<K && n;i++){
		if(n>=a[i]){
			n-=a[i];
			res+=((double)a[i])*b[i];
		}else{
			res+=((double)n)*b[i];
			n=0;
		}
	}
	//printf("res=%.5f\n",res);
	/*if(fabs(res)<eps && ((int)res)==((int)(res-eps)))
		ans=((int)(res+1.0));
	else
		ans=(int)res;*/
	ans=ceil(res-eps);
	if(ans>0 && ans<low)ans=low;
	printf("Case %d: %d\n",T,ans);
}

int main(){
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++)
		work();
	return 0;
}

