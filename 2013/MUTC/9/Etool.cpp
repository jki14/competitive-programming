#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define L 1100

char a[L];

int main(){
	for(int i=0;i<8;i++){
		printf("{");
		for(int j=0;j<16;j++){
			scanf("%s",a);
			if(j)printf(",");
			printf("\"%s\"",a);
		}
		printf("},\n");
	}
	return 0;
}
