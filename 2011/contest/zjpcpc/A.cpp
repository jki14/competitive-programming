#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

int n;

int main(){
	int T,k;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(((n/10)%10)==1)
			printf("%dth\n",n);
		else{
			k=n%10;
			switch(k){
				case 1:
					printf("%dst\n",n);
					break;
				case 2:
					printf("%dnd\n",n);
					break;
				case 3:
					printf("%drd\n",n);
					break;
				default:
					printf("%dth\n",n);
			}
		}
	}
	return 0;
}
