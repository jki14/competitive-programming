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

lld n,k,pos,xxx;
int p;

void work(){
	lld rem=n-k,ned=k<<1;
	
	//printf("ned=%lld n=%lld\n",ned,n);

	if(ned<=n){
		
		if(k && (rem&1)!=(k&1)){
			n-=1LL;k-=1LL;	
			ned=k<<1;
		}
		
		pos=n-ned+1LL;
		xxx=n+1LL;
	}else{
		ned=rem<<1;
		xxx=ned+1LL;
		pos=1LL;
	}
	
	//printf("pos=%lld xxx=%lld\n",pos,xxx);

	for(int i=0;i<p;i++){
		lld x;cin>>x;
		//scanf("%I64d",&x);
		if(x>=xxx || (x>=pos && ((x-pos)&1)))
			printf("X");
		else
			printf(".");
	}
	//printf("\n");
}

int main(){
	//while(cin>>n>>k>>p)
	cin>>n>>k>>p;	
	work();
	return 0;
}

