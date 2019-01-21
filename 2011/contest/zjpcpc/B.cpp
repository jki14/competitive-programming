#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

const double eps=1e-7;

double a,b,c,d,e,f;

int positive(const double &x){
	return x>0.0;
}

int equal(const double &x,const double &y){
	return fabs(x-y)<eps;
}

void doit(){
	scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f);
	if(equal(a,c)){ printf("circle\n");return; };
	if(equal(a,0) || equal(c,0)){ printf("parabola\n");return; }
	if(positive(a)==positive(c))
		printf("ellipse\n");
	else
		printf("hyperbola\n");
}

int main(){
	int t;scanf("%d",&t);
	while(t--)doit();
	return 0;
}
