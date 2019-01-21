#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define maxl 1000

const double eps=1e-8;

char s[maxl];
int a[maxl];

double n,r;
int tot;

void doit(){
	sscanf(s,"%lf",&n);
	r=sqrt(n);tot=0;
	//cout<<"::"<<r<<endl;
	int k;
	while(r>1-eps){
		sprintf(s,"%1.0f",r);\
		sscanf(s,"%d",&k);
		if((k&1)==1)
			a[tot++]=1;
		else
			a[tot++]=0;
		//cout<<":"<<a[tot-1]<<endl;
		//cout<<">"<<r<<endl;
		//cout<<"<"<<k<<endl;
		r/=2;
	}
	for(int i=1;i<=tot;i++)
		printf("%d",a[tot-i]);
	printf("\n");
}

int main(){
	while(gets(s) && s[0]!='#')
		doit();
	return 0;
}
