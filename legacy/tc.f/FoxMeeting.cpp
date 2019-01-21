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

//HEAD_OF_CONFIG_

static const int MOD=10007;

//TAIL_OF_CONFIG_

//HEAD_OF_JKI'S_HEADER_

	//TYPEDEF
	typedef long long lld;
	typedef unsigned long long u64;
	typedef double dou;
	typedef pair<int, int> pii;

	//COMPARE
	template<class T> inline T MIN(const T x, const T y){ return (x<y)?x:y; }
	template<class T> inline T MAX(const T x, const T y){ return (x>y)?x:y; }

	template<class T> inline void UPDMIN(T &x, const T y){ if(x>y)x=y; }
	template<class T> inline void UPDMAX(T &x, const T y){ if(x<y)x=y; }

	//STL
	template<class T>  inline int SIZE(const T &x){ return (int)x.size(); }
	template<class T>  inline int LENGTH(const T &x){ return (int)x.length(); }
	template<class T1, class T2> inline pair<T1, T2> MP(const T1 &x, const T2 &y){ return make_pair(x, y); }

	//BIT
	inline int BINT(const int x){ return 1<<x; }
	inline lld BLLD(const int x){ return 1LL<<x; }
	inline int BINT_TEST(const int s, const int x){ return (s&BINT(x))!=0; }
	inline int BLLD_TEST(const lld s, const int x){ return (s&BLLD(x))!=0LL; }
	
	template<class T> inline T LOWBIT(const T x){ return (x^(x-1))&x; }
	template<class T> inline int BITCOUNT(const T x){ return (!x)?x:(1+BITCOUNT(x&(x-1))); }

	//CONST VALUE
	const double PI=acos(-1.0);
	const double EPS=1e-5;

	//CALCULATE
	template<class T> inline T SQR(const T x){ return x*x; }
	template<class T1, class T2> inline T1 POW(const T1 x, const T2 y){
		if(!y)return 1;else if((y&1)==0){
			return SQR(POW(x, y>>1));
		}else return POW(x, y^1)*x;
	}

	//NUMBERIC
	template<class T> inline T GCD(const T x, const T y){
		if(x<0)return GCD(-x, y);
		if(y<0)return GCD(x, -y);
		return (!y)?x:GCD(y, x%y);
	}
	template<class T> inline T LCM(const T x, const T y){
		if(x<0)return LCM(-x, y);
		if(y<0)return LCM(x, -y);
		return x*(y/GCD(x, y));
	}
	template<class T> inline T EEA(const T a, const T b, T &x, T &y){
		/* a*x+b*y == GCD(a, b) == EEA(a, b, x, y) */
		if(a<0){ T d=EEA(-a, b, x, y); x=-x; return d; }
		if(b<0){ T d=EEA(a, -b, x, y); y=-y; return d; }
		if(!b){
			x=1; y=0; return a;
		}else{
			T d=EEA(b, a%b, x, y);
			T t=x; x=y; y=t-(a/b)*y;
			return d;
		}
	}
	template<class T> inline vector<pair<T, int> > FACTORIZE(T x){
		vector<pair<T, int> > ret;
		if(x<0)x=-x;
		for (T i=2;x>1;){
			if(x%i==0){
				int count=0;
				for(;x%i==0;x/=i)count++;
				ret.push_back(MP(i, count));
			}
			i++;if(i>x/i)i=x;
		}
		return ret;
	}
	template<class T> inline int ISPRIME(const T x){
		if(x<=1)return 0;
		for(T i=2; SQR(i)<=x; i++)if(x%i==0)return 0;
		return 1;
	}
	template<class T> inline T EULARFUNCTION(T x){
		vector<pair<T, int> > f=FACTORIZE(x);
		for(typename vector<pair<T, int> >::iterator it=f.begin(); it!=f.end(); it++){
			x=x/it->first*(it->first-1);
		}
		return x;
	}
	template<class T> inline T INVERSEE(const T a, const T b){
		T x, y;
		EEA(a, b, x, y);
		return x?x:1;
	}

	//REMINDER-LIZATION
	template<class T> inline T MOD_STD(const T x, const T m){ return (x%m+m)%m; }
	template<class T> inline T MOD_STD(const T x){ return (x%MOD+MOD)%MOD; }
	template<class T> inline T MOD_ADD(const T x, const T y, const T m){ return (x+y)%m; }
	template<class T> inline T MOD_ADD(const T x, const T y){ return (x+y)%MOD; }
	template<class T> inline void MOD_ADD(T *x, const T y, const T m){ *x=(*x+y)%m; }
	template<class T> inline void MOD_ADD(T *x, const T y){ *x=(*x+y)%MOD; }
	template<class T> inline T MOD_MUL(const T x, const T y, const T m){ return (T)((1LL*x*y)%m); }
	template<class T> inline T MOD_MUL(const T x, const T y){ return (T)((1LL*x*y)%MOD); }
	template<class T> inline void MOD_MUL(T *x, const T y, const T m){ *x=(T)((1LL*(*x)*y)%m); }
	template<class T> inline void MOD_MUL(T *x, const T y){ *x=(T)((1LL*(*x)*y)%MOD); }
	template<class T1, class T2> inline T1 MOD_POW(const T1 x, const T2 y, const T1 m){
		if(y==0)return 1%m;else if((y&1)==0){
			T1 z=MOD_POW(x, y>>1, m); return MOD_MUL(z, z, m);
		}else return MOD_MUL(MOD_POW(x, y^1, m), x, m);
	}
	template<class T1, class T2> inline T1 MOD_POW(const T1 x, const T2 y){
		if(y==0)return 1%MOD;else if((y&1)==0){
			T1 z=MOD_POW(x, y>>1); return MOD_MUL(z, z);
		}else return MOD_MUL(MOD_POW(x, y^1), x);
	}

	//MATRIX
	template<class T> class MATX{
		private:
			unsigned long hig, wid;
			T *data;
			
			void __init(){
				this->data=(T*)malloc(sizeof(T)*this->hig*this->wid);
				memset(this->data, 0, sizeof(T)*this->hig*this->wid);
			}

		public:
			MATX(){ 
				this->hig=this->wid=1;
				__init();
			}
			MATX(const unsigned long _len){
				this->hig=this->wid=_len;
				__init();
			}
			MATX(const unsigned long _hig, const unsigned long _wid){
				this->hig=_hig;
				this->wid=_wid;
				__init();
			}
			MATX(const MATX &rhs){
				this->hig=rhs.hig;
				this->wid=rhs.wid;
				this->data=(T*)malloc(sizeof(T)*this->hig*this->wid);
				for(unsigned long x=0; x<this->hig; x++)
					for(unsigned long y=0; y<this->wid; y++)
						this->data[x*this->wid+y]=rhs.at(x, y);
			}
			~MATX(){
				free(this->data);
			}

			T & operator()(const unsigned long x, const unsigned long y){
				if(x>=this->hig || y>=this->wid)return (*(T*)NULL);
				return this->data[x*wid+y];
			}

			MATX & operator=(const MATX &rhs){
				if(this->hig!=rhs.hig || this->wid!=rhs.wid){
					free(this->data);
					this->hig=rhs.hig;
					this->wid=rhs.wid;
					this->data=(T*)malloc(sizeof(T)*this->hig*this->wid);
				}
				for(unsigned long x=0; x<this->hig; x++)
					for(unsigned long y=0; y<this->wid; y++)
						this->data[x*this->wid+y]=rhs.at(x, y);
				return *this;
			}

			const MATX operator+(const MATX &opn) const{
				MATX ret(*this);
				for(unsigned long x=0; x<ret.hig; x++)
					for(unsigned long y=0; y<ret.wid; y++)
						ret.data[x*ret.wid+y]+=opn.at(x, y);
				return ret;
			}
			const MATX operator-(const MATX &opn) const{
				MATX ret(*this);
				for(unsigned long x=0; x<ret.hig; x++)
					for(unsigned long y=0; y<ret.wid; y++)
						ret.data[x*ret.wid+y]-=opn.at(x, y);
				return ret;
			}
			const MATX operator*(const MATX &opn) const{
				MATX ret(this->hig, opn.wid);
				const unsigned long len=MIN(this->wid, opn.hig);
				for(unsigned long x=0; x<ret.hig; x++)
					for(unsigned long y=0; y<ret.wid; y++)
						for(unsigned long z=0; z<len; z++)
							ret.data[x*ret.wid+y]+=this->at(x, z)*opn.at(z, y);
				return ret;
			}

			const MATX mul(const MATX &opn) const{ return *this*opn; }
			template<class T2> const MATX mul(const MATX &opn, const T2 m) const{
				MATX ret(this->hig, opn.wid);
				const unsigned long len=MIN(this->wid, opn.wid);
				for(unsigned long x=0; x<ret.hig; x++)
					for(unsigned long y=0; y<ret.wid; y++)
						for(unsigned long z=0; z<len; z++)
							MOD_ADD(&ret.data[x*ret.wid+y], MOD_MUL(this->at(x, z), opn.at(z, y), m), m);
				return ret;
			}
			
			MATX & operator +=(const MATX &rhs){
				*this=*this+rhs;
				return *this;
			}	
			MATX & operator -=(const MATX &rhs){
				*this=*this-rhs;
				return *this;
			}	
			MATX & operator *=(const MATX &rhs){
				*this=*this*rhs;
				return *this;
			}

			const MATX pow(const unsigned long p) const{
				MATX buff(*this), ret(this->hig, this->wid);
				ret.set_one();
				if(p>0)for(unsigned long i=1;;i<<=1){
					if(p&i)ret*=buff;
					buff*=buff;
					if(i>(p>>1))break;
				}
				return ret;
			}
			template<class T2> const MATX pow(const unsigned long p, const T2 m) const{
				MATX buff(*this), ret(this->hig, this->wid);
				ret.set_one();
				if(p>0)for(unsigned long i=1;;i<<=1){
					if(p&i)ret=ret.mul(buff, m);
					buff=buff.mul(buff, m);
					if(i>(p>>1))break;
				}
				return ret;
			}


			const T at(const unsigned long x, const unsigned long y) const{
				if(x>=this->hig || y>=this->wid)return 0;
				return this->data[x*wid+y];
			}

			void show() const{
				for(unsigned long x=0; x<this->hig; x++){
					for(unsigned long y=0; y<this->wid; y++)
						cout<<this->at(x, y)<<" ";
					cout<<endl;
				}
			}

			void set_one(){
				for(unsigned long x=0; x<this->hig; x++)
					for(unsigned long y=0; y<this->wid; y++)
						this->data[x*this->wid+y]=(x==y)?1:0;
			}

	};

//TAIL_OF_JKI'S_HEADER_

int able1(const int u, const int p, const int cap, const int w){
	if(w>cap)return 0;
	if(g[u]){
		int flag=0, nosub=1;
		for(int i=nbs[u]; i; i=nxt[i]){
			int v=dst[i], w=wht[i];
			if(v==p)continue;
			nosub=0;
			if(!able(v, u, cap))return 0;
			if(able1(v, u, cap, w))flag=1;
		}
		return flag|nosub;
	}else{
		
	}
}

int able0(const int u, const int p, const int cap){
	if(g[u]){
		for(int i=nbs[u]; i; i=nxt[i]){
			int v=dst[i];
			if(v==p)continue;
			if(!able0(v, u, cap))return 0;
		}
		return 1;
	}else{
		int flag=0, nosub=1;
		for(int i=nbs[u]; i; i=nxt[i]){
			int v=dst[i], w=wht[i];
			if(v==p)continue;
			nosub=0;
			if(!able0(v, u, cap))return 0;
			if(able1(v, u, cap, w))flag=1;
		}
		return flag|nosub;
	}
}

int check(const int cap){
	if(cap<0)return 0;
	for(int i=0; i<n; i++){
		if(able0(i, -1, cap))return 1;
	}
	return 0;
}

int main_entry(){
	int lef=0, rig=5000000;
	while(lef<=rig){
		int mid=(lef+rig)>>1;
		if(check(mid)){
			if(!check(mid-1))return mid;
			rig=mid-1;
		}else lef=mid+1;
	}
	return -1;
}

class FoxMeeting {
	public:
	int maxDistance(vector <int> A, vector <int> B, vector <int> L, vector <int> foxes){
		n=SIZE(A)+1;
		m=SIZE(foxes);
		for(int i=1; i<n; i++){
			add_edge(A[i]-1, B[i]-1, L[i]);
		}
		for(int i=0; i<m; i++){
			c[foxes[i]-1]=1;
		}
		return main_entry();
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, 2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 0; verify_case(0, Arg4, maxDistance(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, 3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; verify_case(1, Arg4, maxDistance(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, 2, 3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 0; verify_case(2, Arg4, maxDistance(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {10,8,3,7,2,6,9,1,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5,5,8,10,5,5,6,10,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {71846,10951,42265,37832,29439,95676,83661,28186,21216}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,2,3,4,5,6,7,8,9,10}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 0; verify_case(3, Arg4, maxDistance(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {8,15,22,24,2,25,13,26,18,4,9,29,1,12,3,16,14,21,19,27,17,7,20,10,30,11,6,5,23}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {28,28,8,8,28,28,25,2,13,24,24,22,22,29,4,22,8,4,1,24,21,14,18,16,13,21,14,1,25}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {79374,40629,43195,73589,24200,63937,35339,7598,65109,51764,11142,84017,51078,58051,81387,22035,34883,92710,52283,57337,79309,3383,41904,35839,38242,43208,82062,24676,71838}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3,5,7,9,10,14,17,19,20,21,24,25,28}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 107013; verify_case(4, Arg4, maxDistance(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arr0[] = {34,14,22,9,24,19,11,37,33,21,5,30,1,43,7,31,45,27,6,12,13,35,23,47,49,50,26,40,16,10,48,25,29,15,28,46,4,20,44,17,39,32,38,2,42,8,36,3,41}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {18,18,18,14,9,34,9,24,34,11,18,14,21,21,43,1,22,7,1,30,14,33,13,18,9,5,1,1,26,19,50,33,50,40,29,48,50,37,16,40,48,14,30,22,47,37,7,50,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {22051,11109,85275,6691,43705,47374,27748,5411,62549,84079,89542,38006,82198,24083,16847,66335,3542,72495,37378,73973,85703,51682,68688,94295,31337,
90071,99317,63484,43244,99079,55857,34503,79709,82140,91137,27033,91599,61168,52345,49569,58919,38133,43361,
40718,2115,79278,88841,40966,42023}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {5,12,13,18,23,27,28,29,32,33,34,35,36,37,40,42,43,47,48,49,50}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 89342; verify_case(5, Arg4, maxDistance(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main() {
	FoxMeeting __test;
	__test.run_test(-1);
}
// END CUT HERE
