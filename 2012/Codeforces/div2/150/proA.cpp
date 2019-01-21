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

//HEAD_OF_TEMPLATE_BY_JKI14

	//TYPEDEF
	
	typedef long long lld;
	typedef double dou;
	typedef pair<int,int> pii;

	//COMPARE
	
	inline int min(const int &x, const int &y){ return x<y?x:y; }
	inline lld min(const lld &x, const lld &y){ return x<y?x:y; }
	inline dou min(const dou &x, const dou &y){ return x<y?x:y; }

	inline int max(const int &x, const int &y){ return x>y?x:y; }
	inline lld max(const lld &x, const lld &y){ return x>y?x:y; }
	inline dou max(const dou &x, const dou &y){ return x>y?x:y; }

	template<class T> inline void _updmin(T &x,const T &y){ if(x>y)x=y; }
	template<class T> inline void _updmax(T &x,const T &y){ if(x<y)x=y; }

	//STL
	
	#define _size(x) ((int)(x.size()))
	#define _mkpa(x,y) make_pair(x,y)

	//BIT
	
	#define _ni(x) (1<<(x))
	#define _niL(x) (1LL<<(x))
	#define _has(s,x) ((s&(_ni(x)))!=0)
	#define _hasL(s,x) ((s&(_niL(x)))!=0LL)
	
	template<class T> inline T _lowbit(const int &x){ return (x^(x-1))&x; }
	template<class T> inline int _bitsize(const T &x){ return (x==0)?0:(1+bitsize(x&(x-1))); }

	//CONST VALUE
	
	const dou _pi=acos(-1.0);
	const dou _eps=1e-5;

	//CALCULATE
	
	template<class T> inline T _sqr(const T &x){ return x*x; }



//TAIL_OF_TEMPLATE_BY_JKI14

#define N 110000
#define M 2100000
#define K 21

int n,a[N],f[N][K];

set<int> s;

int main(){
	while(scanf("%d",&n)!=EOF){s.clear();
		for (int i=0;i<n;i++)scanf("%d",&a[i]);a[n]=0;
		for (int k=0;k<K;k++)for(int j=n,i=n-1;i>=0;i--){ if(_has(a[i],k))j=i;f[i][k]=j; }
		for (int i=0;i<n;i++)sort(f[i],f[i]+K);
		for (int i=0;i<n;++i) {s.insert(a[i]);
			for(int k=0;k<K;k++) { a[i]|=a[f[i][k]];s.insert(a[i]); }
		}	
		printf("%d\n", s.size());
	}
	return 0;
}

