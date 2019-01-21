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

#define N 110

const double inf = 111111111.0;
const double eps = 1e-6;

int n,ans;
double spox,spoy,vb,vs;
double posx[N],best;

double dist(const int &k){
	return sqrt(spoy*spoy+(spox-posx[k])*(spox-posx[k]));
}

void work(){
	for(int i=1;i<=n;i++)scanf("%lf",&posx[i]);
	scanf("%lf%lf",&spox,&spoy);best=inf;
	for(int i=2;i<=n;i++){
		double dst=dist(i);
		double tim=posx[i]/vb+dst/vs;
		//printf("DST[%d]=%.5f TIM[%d]=%.5f\n",i,dst,i,tim);
		if(tim<best || (fabs(tim-best)<eps)){
			best=tim;
			ans=i;
		}
	}
	printf("%d\n",ans);
}


int main(){
	while(scanf("%d%lf%lf",&n,&vb,&vs)!=EOF)
		work();
	return 0;
}

