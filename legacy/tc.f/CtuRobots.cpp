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

#define N 512
#define M 11000

int n, m, wht[N], idx[N];
double val[N], f[N][M];

static int cmp(const int x, const int y){
	return val[x]<val[y];
}

class CtuRobots {
	public:
	double maxDist(int B, vector <int> cost, vector <int> cap){
		n=SIZE(cost); m=B;
		for(int i=0; i<n;i++){
			wht[i]=cost[i];
			val[i]=cap[i]*1.0;
			idx[i]=i;
		}
		sort(idx, idx+n, cmp);
		memset(f, 0, sizeof(f));
		for(int i=1; i<=n; i++){int k=idx[i-1];
			for(int j=0; j<=m; j++){
				UPDMAX(f[i][j], f[i-1][j]);
				if(j)UPDMAX(f[i][j], f[i][j-1]);
				if(j>=wht[k]){
					double buff=f[i-1][j-wht[k]]/3.0+val[k];
					UPDMAX(f[i][j], buff);
				}
			}
		}
		return f[n][m]/2.0;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 100; int Arr1[] = {50,25}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 0.6666666666666666; verify_case(0, Arg3, maxDist(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 25; int Arr1[] = {23,5,8,20,15}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {108,30,42,100,94}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 55.0; verify_case(1, Arg3, maxDist(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1382; int Arr1[] = {0,0,0,1000,1000,0,1000,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2039,4819,5923,1577,8749,9182,3652,4918}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 6503.238683127572; verify_case(2, Arg3, maxDist(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 209; int Arr1[] = {185,130,109,1,45,117,127,13,2,37,6,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {93,5,278,4,20,54,93,213,103,5,225,32,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 190.48376771833563; verify_case(3, Arg3, maxDist(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 9956; int Arr1[] = {3229,736,1325,2680,410,1227,1378,499,1525,1722,1262,2080,2581,1505,1019,
480,3155,836,2697,616,136,2032,2345,3154,1953,1654,344,3079,1426,199,2857,
1714,2952,996,1567,2674,2054,2110,949,2412,2148,1016,234,1932,1554,1943,
1625,1266,258,2924,49,1693,3140,309,557,12,2760,227,2497,330,646,1935,3032,
2671,2433,164,1472,3080,717,221,2483,1309,1174,12,917,2335,3086,148,64,189,
2628,1660,2983,109,1920,2470}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {934850,214,15807606,2426,176520,1900009,1184867,40550,1774843,2953,77834310,
7276,3139890,695,213862217,13,193864,189,557664,1206555,85133,381662,4887,
115027,2186890,218075,1,2024,9,95244962,7,906,3485642,52962078,58645759,785706,
303,18,189,819600,17528041,11616471,92719012,82351,12752,634,26122233,215485,
58,5506810,101874,130429471,2,1,68966,76303,321766922,463,26,225,207,52,1739,
246841,496,228,4749453,191,79,10560,1414194,7529,13,521935,1,2,11590618,4020,
105,3,28,3,2855,189909573,1,295052}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 2.1034261053998655E8; verify_case(4, Arg3, maxDist(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 8852; int Arr1[] = {2547,912,2592,1085,296,523,2257,2347,1822,261,334,2159,528,2739,201,964,427,
2038,26,2361,234,2063,2885,2178,2708,730,2902,326,306,2794,1725,13,137,2169,
388,1124,1464,2120,2357,1544,2794,2260,185,650,2852,124,1767,453,1331,1397,
1991,1166,413,1428,2862,1194,1139,571,1299,1232,267,2027,746,1971,2695,2586,
185,1319,1088,2818,2604,1798,475,1252,1767,2277,545,601,2160,325,2749,1161,
1172,1075,1925,2468,1596,1116,1558,2226,1302,796,775,1105,418,334,2872,1921,
2830,2448,2914,2634,1386,2516,492,1029,1134,2934,2017,1741,1675,2593,2233,
2401,68,683,2053,155,183,923,2276,1823,65,2290,2448,92,2468,819,837,303,1440,
705,291,2348,2562,765,1926,14,2514,2403,2671,1143,1358,121,376,2874,2447,1769,
1686,967,967,2492,2472,2014,1686,2291,1093,1801,818}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {263268,256181,476791,365614,265352,19307,243180,84909,98175,367524,241474,479623,
277638,111229,155356,415525,234382,97870,451466,58375,268277,404582,484789,458230,
529286,449840,103208,199505,319373,294746,78005,326456,14418,257144,135669,238651,
411723,99122,20421,298154,278407,153564,24778,73065,110408,392693,510192,362399,
333830,125893,130946,345134,261418,230632,306751,451242,175675,459988,150787,349338,
134594,255227,263645,180770,436965,502871,242085,318340,220576,189202,395789,390659,
101649,337117,440471,466547,513054,316694,30382,38826,472506,67698,223953,397305,
325564,57949,194651,443500,443188,431386,220061,400640,286085,189461,324214,171813,
420711,260549,426526,208052,83343,429483,366076,52443,224742,333286,544259,335276,
93282,326772,82841,225256,270357,547610,397526,193336,182374,439866,255860,111363,
509167,228847,218257,39438,212242,378338,88972,127544,59230,428847,155553,116333,
255176,396356,223463,226360,38283,6238,173455,447707,332111,60485,398523,462205,
55397,148417,529738,460063,177715,404809,336155,50750,24165,530386,394811,512481,
230296,45797,370008}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 408339.73124862404; verify_case(5, Arg3, maxDist(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main() {
	CtuRobots __test;
	__test.run_test(-1);
}
// END CUT HERE
