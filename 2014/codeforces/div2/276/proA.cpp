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
#include<list>
#include<bitset>
#include<set>
#include<map>
#include<functional>
#include<numeric>
#include<utility>
#include<iomanip>
#include<stdint.h>
using namespace std;

inline int64_t gcd(const int64_t x, const int64_t y){ return (y!=0LL)?gcd(y, x%y):x; }

int core(const int k, const int64_t x, const int64_t y, int64_t *a){
	if(k==3){
		if(gcd(a[0], a[1])==1LL && gcd(a[1], a[2])==1LL && gcd(a[0], a[2])>1LL)
			return 1;
		return 0;
	}
	for(a[k]=x; a[k]+2LL-k<=y; a[k]++)
		if(core(k+1, a[k]+1LL, y, a))return 1;
	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	int64_t x, y;
	while(cin>>x>>y){
		int64_t a[3];
		if(!core(0, x, y, a))
			cout<<"-1"<<endl;
		else cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
	}
	return 0;
}

