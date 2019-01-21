#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main(){
	printf("1\n");
	for(int i=0;i<1000000;i++)putchar('a');
	printf("\n");
	for(int i=0;i<1000000;i++)putchar('a');
	printf("\n");
	printf("5\n");
	printf("2 0\n");
	printf("1 2 24 b\n");
	printf("2 0\n");
	printf("1 2 999999 c\n");
	printf("2 27\n");
	return 0;
}
