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
	template<class T> inline int _bitsize(const T &x){ return (x==0)?0:(1+_bitsize(x&(x-1))); }

	//CONST VALUE

	const dou _pi=acos(-1.0);
	const dou _eps=1e-5;

	//CALCULATE

	template<class T> inline T _sqr(const T &x){ return x*x; }

	//NUMBERIC

	template<class T> inline T _gcd(const T &x,const T &y){
		if(x<0)return _gcd(-x,y);
		if(y<0)return _gcd(x,-y);
		return (y==0)?x:_gcd(y,x%y);
	}
	template<class T> inline T _lcm(const T &x,const T &y){
		if(x<0)return _lcm(-x,y);
		if(y<0)return _lcm(x,-y);
		return x*(y/_gcd(x,y));
	}
	template<class T> inline T _euc(const T &a,const T &b,T &x,T &y){ 
		/* a*x+b*y == _euc(); */
		if(a<0){T d=_euc(-a,b,x,y);x=-x;return d;} 
	   	if(b<0){T d=_euc(a,-b,x,y);y=-y;return d;} 
	      	if(b==0){
			x=1;y=0;return a;
		}else{
			T d=_euc(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;
			return d;
		}
	}
	template<class T> inline vector<pair<T,int> > _fac(T n){
		vector<pair<T,int> > ret;for (T i=2;n>1;){
			if (n%i==0){int cnt=0;for (;n%i==0;cnt++,n/=i);ret.push_back(_mkpr(i,cnt));} 
	   		i++;if (i>n/i) i=n;
		}
		if (n>1) ret.push_back(_mkpr(n,1));return ret;
	}
	template<class T> inline int _prm(const T &x){
		if(x<=1)return 0;
		for(T i=2;sqr(i)<=x;i++)if(x%i==0)return 0;
		return 1;
	}
	template<class T> inline T _phi(T x){ 
		/* EularFunction:return the number of integers which are the relatively prime number of x and less than x. */
		vector<pair<T,int> > f=_fac(x);T ret=x;
		for(int i=0;i<_size(f);i++)ret=ret/f[i].first*(f[i].first-1);
		return ret;
	}
	template<class T> inline T _inv(T a,T b){
		/* if(k%a==0) (k/a)%b==((k%b)*(_inv()%b))%b */
		/*	original code begin
		T x0=1,y0=0,x1=0,y1=1;
		for(T r=a%b;r!=0;r=a%b){ T k=a/b,dx=x0-k*x1,dy=y0-k*y1;x0=x1;y0=y1;x1=dx;y1=dy;a=b;b=r; }
		if(x1==0)x1=1;return x1;
		original code end	*/
		T x,y;_euc(a,b,x,y);
		if(x==0)x=1;return x;
	}
	template<class T> inline T _cmod(T x,T m){ return (x%m+m)%m; }
	template<class T> inline T _amod(T x,T y,T m){ return x=((x+y)%m+m)%m; }
	template<class T> inline T _mmod(T x,T y,T m){ return (T)((((lld)x)*((lld)y)%((lld)m)+((lld)m))%((lld)m)); }
	template<class T> inline T _pmod(T x,T y,T m){
		if(y==0)return 1%m;else if((y&1)==0){ 
			T z=_pmod(x,y>>1,m);return _mmod(z,z,m); 
		}else return _mmod(_pmod(x,y^1,m),x,m);
	}
	#define _cmd(x) _cmod(x,mod)
	#define _amd(x,y) _amod(x,y,mod)
	#define _mmd(x,y) _mmod(x,y,mod)
	#define _pmd(x,y) _pmod(x,y,mod)

	//MATRIX OPERATIONS

	const int _MTRXSIZE = 40;
	template<class T> inline void _shwMTRX(int n,T A[_MTRXSIZE][_MTRXSIZE]){
		for(int i=0;i<n;i++){ for(int j=0;j<n;j++)cout<<A[i][j]<<" ";cout<<endl; }
	}
	template<class T> inline void _stdMTRX(int n,T A[_MTRXSIZE][_MTRXSIZE]){
		for(int i=0;i<n;i++)for(int j=0;j<n;j++) A[i][j]=(i==j)?1:0;
	}
	template<class T> inline void _addMTRX(int n,T C[_MTRXSIZE][_MTRXSIZE],T A[_MTRXSIZE][_MTRXSIZE],T B[_MTRXSIZE][_MTRXSIZE]){
		for(int i=0;i<n;i++)for(int j=0;j<n;j++) C[i][j]=A[i][j]+B[i][j];
	}
	template<class T> inline void _subMTRX(int n,T C[_MTRXSIZE][_MTRXSIZE],T A[_MTRXSIZE][_MTRXSIZE],T B[_MTRXSIZE][_MTRXSIZE]){
		for(int i=0;i<n;i++)for(int j=0;j<n;j++) C[i][j]=A[i][j]-B[i][j];
	}
	template<class T> inline void _mulMTRX(int n,T C[_MTRXSIZE][_MTRXSIZE],T _A[_MTRXSIZE][_MTRXSIZE],T _B[_MTRXSIZE][_MTRXSIZE]){
		T A[_MTRXSIZE][_MTRXSIZE],B[_MTRXSIZE][_MTRXSIZE];
		for(int i=0;i<n;i++)for(int j=0;j<n;j++){ A[i][j]=_A[i][j];B[i][j]=_B[i][j];C[i][j]=0; }
		for(int i=0;i<n;i++)for(int j=0;j<n;j++)for(int k=0;k<n;k++)C[i][j]+=A[i][k]*B[k][j];
	}
	template<class T> inline void _addModMTRX(int n,T m,T C[_MTRXSIZE][_MTRXSIZE],T A[_MTRXSIZE][_MTRXSIZE],T B[_MTRXSIZE][_MTRXSIZE]){
		for(int i=0;i<n;i++)for(int j=0;j<n;j++) C[i][j]=_cmod(A[i][j]+B[i][j],m);
	}
	template<class T> inline void _subModMTRX(int n,T m,T C[_MTRXSIZE][_MTRXSIZE],T A[_MTRXSIZE][_MTRXSIZE],T B[_MTRXSIZE][_MTRXSIZE]){
		for(int i=0;i<n;i++)for(int j=0;j<n;j++) C[i][j]=_cmod(A[i][j]-B[i][j],m);
	}
	template<class T> inline void _mulModMTRX(int n,T m,T C[_MTRXSIZE][_MTRXSIZE],T _A[_MTRXSIZE][_MTRXSIZE],T _B[_MTRXSIZE][_MTRXSIZE]){
		T A[_MTRXSIZE][_MTRXSIZE],B[_MTRXSIZE][_MTRXSIZE];
		for(int i=0;i<n;i++)for(int j=0;j<n;j++){ A[i][j]=_A[i][j];B[i][j]=_B[i][j];C[i][j]=0; }
		for(int i=0;i<n;i++)for(int j=0;j<n;j++)for(int k=0;k<n;k++)C[i][j]=(C[i][j]+_mmod(A[i][k],B[k][j],m))%m;
	}
	template<class T> inline void _powModMTRX(int n,T y,T m,T C[_MTRXSIZE][_MTRXSIZE],T X[_MTRXSIZE][_MTRXSIZE]){
		T R[_MTRXSIZE][_MTRXSIZE];for(int i=0;i<n;i++)for(int j=0;j<n;j++)R[i][j]=X[i][j];_stdMTRX(n,C);
		if(y>0)for(T i=1;;i<<=1){
			if(y&i)_mulModMTRX(n,m,C,C,R);
			_mulModMTRX(n,m,R,R,R);
			if(i>(y>>1))break;
		}
	}

	//FRACTION
	template<class T> struct _frct{T a,b;_frct(T a=0,T b=1);string toString();};  
	template<class T> _frct<T>::_frct(T a,T b){T d=_gcd(a,b);a/=d;b/=d;if (b<0) a=-a,b=-b;this->a=a;this->b=b;}
	template<class T> string _frct<T>::toString(){ostringstream tout;tout<<a<<"/"<<b;return tout.str();}
	template<class T> _frct<T> operator+(_frct<T> p,_frct<T> q){return _frct<T>(p.a*q.b+q.a*p.b,p.b*q.b);}  
	template<class T> _frct<T> operator-(_frct<T> p,_frct<T> q){return _frct<T>(p.a*q.b-q.a*p.b,p.b*q.b);}  
	template<class T> _frct<T> operator*(_frct<T> p,_frct<T> q){return _frct<T>(p.a*q.a,p.b*q.b);}  
	template<class T> _frct<T> operator/(_frct<T> p,_frct<T> q){return _frct<T>(p.a*q.b,p.b*q.a);}  

//TAIL_OF_TEMPLATE_BY_JKI14


class MovingRooksDiv1{
	public:
	vector <int> move(vector <int> Y1, vector <int> Y2){
	}
    
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, move(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, move(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,2,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {-1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, move(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {2,1,0,3,5,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,2,3,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1, 0, 2, 1, 2, 4, 5 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, move(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {10,9,8,7,6,5,4,3,2,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,2,3,4,5,6,7,8,9,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 7, 0, 8, 0, 9, 0, 10, 1, 2, 1, 3, 1, 4, 1, 5, 1, 6, 1, 7, 1, 8, 1, 9, 1, 10, 2, 3, 2, 4, 2, 5, 2, 6, 2, 7, 2, 8, 2, 9, 2, 10, 3, 4, 3, 5, 3, 6, 3, 7, 3, 8, 3, 9, 3, 10, 4, 5, 4, 6, 4, 7, 4, 8, 4, 9, 4, 10, 5, 6, 5, 7, 5, 8, 5, 9, 5, 10, 6, 7, 6, 8, 6, 9, 6, 10, 7, 8, 7, 9, 7, 10, 8, 9, 8, 10, 9, 10 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, move(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(){
	MovingRooksDiv1 ___test;
	___test.run_test(-1);
}
// END CUT HERE 
