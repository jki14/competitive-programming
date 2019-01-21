#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<climits>
#include<algorithm>
using namespace std;

int x,y,k;

int main(){
	while(scanf("%d%d%d",&x,&y,&k)!=EOF){
		if(x*y*k>=100000)
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}
