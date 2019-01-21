#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
using namespace std;

typedef long long lld;

#define N 510000
#define M 5100

int n, m, k;
lld p;
lld a[N], d[N], c[N];
int s[M];

int able(const lld tar){
	for(int i=0; i<=m; i++)s[i]=0;
	lld total=0LL;
	for(int i=0; i<n; i++){
		lld det=max(a[i]+d[i]*m-tar, 0LL);
		c[i]=det/p+((det%p)?1:0);
		total+=c[i];
		/*for(int j=0; j<c[i]; j++){
			lld nes=max(det-(c[i]-j-1)*p-a[i], 0LL);
			//b[i][j]=(nes-a[i])/d[i];
			lld lim=nes/d[i]+((nes%d[i])?1LL:0LL);
			if(lim>=m)return 0;
			s[lim]++;
		}*/
	}
	if(total>m*k)return 0;
	for(int i=0; i<n; i++){
		lld det=max(a[i]+d[i]*m-tar, 0LL);
		for(int j=0; j<c[i]; j++){
			lld nes=max(det-(c[i]-j-1)*p-a[i], 0LL);
			//b[i][j]=(nes-a[i])/d[i];
			lld lim=nes/d[i]+((nes%d[i])?1LL:0LL);
			if(lim>=m)return 0;
			s[lim]++;
		}
	}
	for(int i=m-1; i>=0; i--){
		s[i]+=s[i+1];
		if(s[i]>(m-i)*k)return 0;
	}
	return 1;
}

lld core(const lld low, const lld hig){
	lld lef=low, rig=hig;
	while(lef<=rig){
		//printf("lef=%d rig=%d\n", lef, rig);
		lld mid=(lef+rig)>>1;
		if(able(mid)){
			if(!able(mid-1))return mid;
			rig=mid-1;
		}else lef=mid+1;
	}
	//printf("error: lef=%d, rig=%d\n", lef, rig);
	return -1;
}

int main(){
	while(scanf("%d%d%d%I64d", &n, &m, &k, &p)!=EOF){
		lld alow=0xc0c0c0c0c0c0c0c0;
		lld ahig=0xc0c0c0c0c0c0c0c0;
		for(int i=0; i<n; i++){
			scanf("%I64d%I64d", &a[i], &d[i]);
			alow=max(alow, d[i]);
			ahig=max(ahig, a[i]+d[i]*m);
		}
		printf("%I64d\n", core(alow, ahig));
	}
	return 0;
}

