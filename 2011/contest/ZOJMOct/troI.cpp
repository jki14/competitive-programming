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

int cnt(int x){
	int ret=0;
	for(;x;x>>=1)
		if(x&1)ret++;
	return ret;
}

int ctn(int x){
	for(;x;x>>=1){
		if((x&1) && (x&2))return 1;
	}
	return 0;
}

int main(){
	for(int n=1;n<=15;n++){int e=1<<n;
		for(int m=0;m<=n;m++){
			int ans=0;
			for(int i=0;i<e;i++){
				if(cnt(i)!=m)continue;
				if(ctn(i))   continue;
				ans++;
			}
			printf(" %5d",ans);
		}
		printf("\n");
	}
	return 0;
}


