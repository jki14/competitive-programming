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

#define S 1100000

int isprm(const int &x){
	if(x==1)return 0;
	if(x==2)return 1;
	for(int i=2;i*i<=x;i++)
		if(x%i==0)return 0;
	return 1;
}

int main(){
	int T;scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		if(n==0){ printf("0\n");continue; }
		printf("%d\n",isprm(n)?2:1);
	}
	return 0;
}
