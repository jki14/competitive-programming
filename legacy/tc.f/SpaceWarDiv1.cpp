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
	#define _mkpr(x,y) make_pair(x,y)

	//BIT
	
	#define _ni(x) (1<<(x))
	#define _niL(x) (1LL<<(x))
	#define _has(s,x) ((s&(_ni(x)))!=0)
	#define _hasL(s,x) ((s&(_niL(x)))!=0LL)

	template<class T> inline T _lowbit(const T &x){ return (x^(x-1))&x; }
	template<class T> inline int _bitsize(const T &x){ return (x==0)?0:(1+bitsize(x&(x-1))); }



//TAIL_OF_TEMPLATE_BY_JKI14

#define N 1100

int n,m;
int a[N],b[N],id[N];
lld c[N],_c[N],sum;

multimap<int, lld> s,_s;
multimap<int, lld>::iterator it;

int cmp(const int &x,const int &y){ return c[x]<c[y]; }

int able(const lld &x){
	s=_s;for(int i=0;i<m;i++)c[i]=_c[i];
	for(int _i=0;_i<m;_i++){int i=id[_i];
		it=s.lower_bound(b[i]);
		while(it!=s.end()){
			if((*it).second+c[i]<=x)break;
			c[i]-=x-(*it).second;
			s.erase(it);
			it=s.lower_bound(b[i]);
		}
		if(it==s.end())return 0;
		(*it).second+=c[i];
	}
	return 1;
}

lld core(){
	lld lef=1LL,rig=sum;
	while(lef<=rig){
		lld mid=(lef+rig)>>1;
		if(able(mid)){
			if(!able(mid-1LL))return mid;
			rig=mid-1LL;
		}else lef=mid+1LL;
	}
	return -1;
}

class SpaceWarDiv1 {
	public:
	long long minimalFatigue(vector <int> _a, vector <int> _b, vector<long long> __c) {
		n=_size(_a);m=_size(_b);sum=0LL;_s.clear();
		for(int i=0;i<n;i++){ a[i]=_a[i];_s.insert(_mkpr(a[i],0)); }
		for(int i=0;i<m;i++){ b[i]=_b[i];_c[i]=__c[i];sum+=_c[i];id[i]=i; }
		sort(id,id+m,cmp);
		if(!able(sum))
			return -1;
		else return core();
	}
};
