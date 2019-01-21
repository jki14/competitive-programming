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
#include<set>
#include<map>
using namespace std;

typedef long long lld;

lld pow(const lld &a,const lld &k){
	lld ret=1LL;
	for(lld i=0LL;i<k;i++)ret*=a;
	return ret;
}

int main(){
	for(lld n=1;n<=10;n++){
		for(lld m=1;m<=10;m++){
			lld num=0LL;
			for(lld i=1;i<=n;i++)num+=pow(i,m);
			int ans=0;
			for(;num>0LL;num/=10LL){
				if((num%10LL)==0LL)
					ans++;
				else
					break;
			}
			printf(" %5d",ans);
		}
		printf("\n");
	}
	return 0;
}
