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

const double inf = 123456.0;
const double low =-123456.0;

int n,k,num;
int mk[N],a[N],id[N];
int que[N];
double val[N];
double top,bot;

int cmp1(const int &i,const int &j){
	if(mk[i]!=mk[j])return mk[i]<mk[j];
	return a[i]<a[j];
}

int cmp2(const int &i,const int &j){
	if(mk[i]!=mk[j])return mk[i]<mk[j];
	return a[i]>a[j];
}

void work(){
	num=n/k;
	
	for(int i=0;i<n;i++){
		id[i]=i;mk[i]=0;
		scanf("%d",&a[i]);
	}
	top=low;bot=inf;

	int q;scanf("%d",&q);
	while(q--){
		double value=0.0;
		for(int i=0;i<num;i++){
			scanf("%d",&que[i]);que[i]--;
			value+=(double)a[que[i]];
		}
		value/=(double)num;
		for(int i=0;i<num;i++){
			mk[que[i]]=1;
			val[que[i]]=value;
		}
		top=max(top,value);
		bot=min(bot,value);
	}

	//printf("TEMP bot=%.10f top=%.10f\n",bot,top);

	sort(id,id+n,cmp1);
	if(!mk[id[num-1]]){
		double value=0.0;
		for(int i=0;i<num;i++)value+=a[id[i]];
		value/=(double)num;
		bot=min(bot,value);
	}
	
	sort(id,id+n,cmp2);
	if(!mk[id[num-1]]){
		double value=0.0;
		for(int i=0;i<num;i++)value+=a[id[i]];
		value/=(double)num;
		top=max(top,value);
	}

	printf("%.10f %.10f\n",bot,top);
}

int main(){
	while(scanf("%d%d",&n,&k)!=EOF)
		work();
	return 0;
}

