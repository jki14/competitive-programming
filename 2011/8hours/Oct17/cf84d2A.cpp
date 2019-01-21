#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<climits>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<set>
#include<map>
using namespace std;

typedef long long lld;

lld a;

void work(){
	int num=0;
	for(;a;a/=10){
		if((a%10)==4 || (a%10)==7)num++;
	}
	if(!num){ printf("NO\n");return; }
	for(;num;num/=10){
		if((num%10!=4) && (num%10)!=7){
			printf("NO\n");return;
		}
	}
	printf("YES\n");
}

int main(){
	while(cin>>a)
		work();
	return 0;	
}

