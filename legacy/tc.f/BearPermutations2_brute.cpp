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

int calc(int *a, const int n){
	if(n<=0)return 0;
	int mid=0;
	for(int i=1; i<n; i++){
		if(a[i]<a[mid])mid=i;
	}
	if(mid>0 && mid<n-1){
		int lef=0, rig=mid+1;
		for(int i=1; i<mid; i++){
			if(a[i]<a[lef])lef=i;
		}
		for(int i=rig+1; i<n; i++){
			if(a[i]<a[rig])rig=i;
		}
		return calc(a, mid)+calc(a+mid+1, n-mid-1)+rig-lef;
	}else return calc(a, mid)+calc(a+mid+1, n-mid-1);
}

int main(){
	int *a=(int*)malloc(sizeof(int)*128);
	while(true){
		int n, ans=0; scanf("%d", &n);
		for(int i=0; i<n ;i++)a[i]=i;
		do{
			ans+=calc(a, n);
			for(int i=0;i<n;i++)
				printf("%d", a[i]);
			printf(" = %d\n", calc(a, n));
		}while(next_permutation(a, a+n));
		printf("%d\n", ans);
	}
	free(a);
	return 0;
}
