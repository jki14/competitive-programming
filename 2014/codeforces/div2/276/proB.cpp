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
using namespace std;

inline int64_t gcd(const int64_t x, const int64_t y){ return (y!=0LL)?gcd(y, x%y):x; }
inline int64_t lcm(const int64_t x, const int64_t y){ return x*y/gcd(x, y); }

inline int64_t good(const int64_t sum, int64_t n, int64_t m, const int64_t x, const int64_t y){
	int64_t both_bad = sum/lcm(x, y);
	int64_t both_gud = sum - sum/x - sum/y + both_bad;
	n -= sum/y - both_bad;if(n<0LL)n=0LL;
	m -= sum/x - both_bad;if(m<0LL)m=0LL;
	return n+m<=both_gud;
}

inline int64_t core(const int64_t n, const int64_t m, const int64_t x, const int64_t y){
	int64_t lef = 1LL, rig = 0x3f3f3f3f3f3f3f3f;
	while(lef<=rig){
		int64_t mid = (lef+rig)>>1;
		if(good(mid, n, m, x, y)){
			if(!good(mid-1LL, n, m, x, y))return mid;
			rig = mid-1LL;
		}else lef = mid+1LL;
	}
	return -1LL;
}

int main(){
	int64_t n, m, x, y;
	while(cin>>n>>m>>x>>y){
		cout<<core(n, m, x, y)<<endl;
	}
	return 0;
}

