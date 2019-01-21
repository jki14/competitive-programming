#include<iostream>
#include<sstream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
	srand(time(0));
	int i,j;
	for(i=0;i<1000;i++){
		for(j=0;j<1000;j++)
			printf("%d",rand()%2);
		printf("\n");
	}
	return 0;
}

