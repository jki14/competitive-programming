#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

const double eps=1e-6;

int k;
double vb,vw,vr,vc;

void work(){
	int i;
	double avg,amt;
	amt=vb+vw-vr;
	if(amt<0+eps){
		printf("0\n");
		return;
	}
	avg=amt/k;
	if(avg>vc-vr+eps)avg=vc-vr;
	if(avg>vw-vr-eps){
		printf("%d %0.2f",k,avg-vw+vr);
		for(i=1;i<k;i++)printf(" %0.2f",avg);
		printf("\n");
	}else{
		avg=vb/(k-1);
		printf("%d 0.00",k);
		for(i=1;i<k;i++)printf(" %0.2f",avg);
		printf("\n");
	}
}

int main(){
	while(scanf("%d",&k)!=EOF && k){
		scanf("%lf%lf%lf%lf",&vb,&vw,&vr,&vc);
		work();
	}
	return 0;
}
