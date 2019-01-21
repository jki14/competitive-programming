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

#define maxn 1100

int T;

int c,n,m,sum;
double ans;

void work(){
	int i;
	double O,X;
	scanf("%d%d",&c,&n);m=n*c+1;sum=n+m;
	ans=(double)n;O=(double)n;X=(double)m;
	for(i=1;i<m;i++){

		printf("X=%.8f O=%.8f ",X,O);

		ans*=(X/(O+X));X-=1.0;
		if((i%c)==0){
			ans*=(O/(O+X));
			O-=1.0;
		}

		printf("ans=%.8f\n",ans);

	}
	//ans*=(double)n;
	printf("Case #%d: %.8f\n",T,ans);
}

int main(){
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++)work();
	return 0;
}

