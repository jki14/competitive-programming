#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

#define maxk 100000

const double eps=1e-4;
const int inf=1000000000;

int sqr[maxk];
int n,res;

void init(){
	for(int i=0;i*i<=inf;i++)
		sqr[i]=i*i;
}

void work(){
	int x,y;
	res=0;
	if(n){
		for(x=0;((double)x)<sqrt(n-sqr[x])+eps;x++){
			y=(int)sqrt(n-sqr[x]);
			if(sqr[x]+sqr[y]!=n)continue;
			if(x && x!=y){
				res+=8;
				continue;
			}
			if(x==0){
				res+=4;
			}else{
				res+=4;
			}
		}
	}
	printf("%d\n",res);
}

int main(){
	init();
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}
