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

#define L 110

typedef long long lld;

lld x,a,b,len;
lld lef,rig,res;
char key[L];

lld getkey(){
	lld ret=1LL;
	for(int i=0;key[i];i++)ret*=10LL;
	return ret;
}

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%s",key);len=getkey();
		sscanf(key,"%lld",&x);scanf("%lld%lld",&a,&b);
		lef=((lld)( a / len )) * len + x;if(lef<a)lef+=len;
		rig=((lld)( b / len )) * len + x;if(rig>b)rig-=len;
		if(lef<=rig)
			res=1LL+((rig-lef)/len);
		else res=0LL;
		//printf("%lld -> %lld\n",lef,rig);
		printf("%lld\n",res);
	}
	return 0;
}
