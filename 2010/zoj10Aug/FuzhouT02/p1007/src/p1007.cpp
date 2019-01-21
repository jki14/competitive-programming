#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

int TIMER,T;
int n,k,res;

void work(){
	int i,val,stop=1;for(i=k=res=0;i<n;i++){
		scanf("%d",&val);
		if(stop){
			if(val>0){
				stop=0;k++;res+=val;
			}
		}else{
			if(val<0)
				stop=1;
			else
				res+=val;
		}
	}
	printf("Case %d:\n%d %d\n",TIMER,k,res);
	if(TIMER<T)printf("\n");
}

int main(){
	scanf("%d",&T);for(TIMER=1;TIMER<=T;TIMER++){
		scanf("%d",&n);work();
	}
	return 0;
}
