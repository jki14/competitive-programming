// BEGIN CUT HERE
// PROBLEM STATEMENT
// Let A be a matrix with N rows and N columns and P be a permutation of integers from 0 to N-1. Consider the following sum: Sum(A, P) = A[0, P[0]] + A[1, P[1]] + ... + A[N-1, P[N-1]], where A[i, j] is the element of A in row i and column j (all indices in this problem are 0-based). The matrix A is called nice if Sum(A, P) is always equal to the same value disregarding of the choice of permutation P.

Fox Ciel wants to draw a nice matrix on the blackboard. She is given a vector <string> board. It contains N elements and each element contains N characters. If j-th character of board[i] is a digit '0', '1', '2', ..., '9', then A[i, j] must be equal to this digit. If j-th character of board[i] is '-', then A[i, j] can be equal to any non-negative integer (it is allowed to be greater than 9).

Let T be the number of different matrices that satisfy all Ciel's requirements (the constraints will guarantee that the number of such matrices is finite). Compute and return the value of (T modulo 1,000,000,007).


DEFINITION
Class:EqualSums
Method:count
Parameters:vector <string>
Returns:int
Method signature:int count(vector <string> board)


CONSTRAINTS
-board will contain between 1 and 50 elements, inclusive.
-Each element of board will contain exactly N characters, where N is the number of elements in board.
-Each character in board will be one of '-', '0', '1', '2', ..., '9'.
-The number of matrices that satisfy all Ciel's requirements will be finite.


EXAMPLES

0)
{"1-",
 "-2"}

Returns: 4

The sum A[0, 1] + A[1, 0] must be equal to 3.

1)
{"123",
 "4--",
 "--9"}

Returns: 1



2)
{"9--",
 "-9-",
 "--9"}

Returns: 271



3)
{"11",
 "12"}

Returns: 0

There are no nice matrices that match the given board, so T = 0.

4)
{"-4--",
 "-0-2",
 "--1-",
 "4---"}


Returns: 10



5)
{"--2",
 "02-",
 "-10"}


Returns: 0



6)
{"----------1---------------0-----7-----------------",
 "-----4--------------------------------------------",
 "--------5-------------5-3---5---------------6-----",
 "-------2----------1-------------------------------",
 "-----4--------------------------------------------",
 "-----3--------------------------------------------",
 "-6----------5-------------------------------------",
 "-------------------------------7---5----------6---",
 "--------6-------------6-4---6---------------7-----",
 "-------------4----------------5-------------------",
 "3------------------------------------------6------",
 "3------------------------------------------6------",
 "-------------4----------------5-------------------",
 "---------------2-------------------------3--------",
 "--2------------------------------------------2----",
 "---8---------------1-------------------3----------",
 "---------------3----------------------------------",
 "----7----------------5---0-----------------------5",
 "----------------5-------------------------3-----1-",
 "----------1---------------0-----7-----------------",
 "-------------5----------------6-------------------",
 "-7----------6-------------------------------------",
 "---8---------------1-------------------3----------",
 "-----------------------3--------------------------",
 "----8----------------6---1-----------------------6",
 "------------------------------------------4-----2-",
 "-----------5---------------5----------------------",
 "-----------------------------6--------------------",
 "----8----------------6---1-----------------------6",
 "----------------5-------------------------3-----1-",
 "-------------------------------6---4--2-------5---",
 "-6----------5-------------------------------------",
 "--------5-------------5-3---5---------------6-----",
 "-------------5----------------6-------------------",
 "-----3--------------------------------------------",
 "---------------2-------------------------3--------",
 "---------4---------------------------6------------",
 "-------------------------------6---4--2-------5---",
 "------2-------------1------------22---------------",
 "--------5-------------5-3---5---------------6-----",
 "-----------5--3------------5----------------------",
 "--2------------------------------------------2----",
 "---------5---------------------------7------------",
 "-------------4----------------5-------------------",
 "-----------------5------------------4---6------2--",
 "-------------------------------6---4--2-------5---",
 "-----------------------2--------------------------",
 "----------------6-------------------------4-----2-", 
 "-------------------------------6---4--2-------5---",
 "--------5-------------5-3---5---------------6-----"}

Returns: 45094393



// END CUT HERE
#line 140 "EqualSums.cpp"

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
	template<class T> inline T _mmod(T x,T y,T m){ return (T)((((lld)x)*((lld)y)%((lld)m)+((lld)m))%((lld)m)); }
	template<class T> inline T _pmod(T x,T y,T m){
		if(y==0)return 1%m;else if((y&1)==0){ 
			T z=_pmod(x,y>>1,m);return _mmod(z,z,m); 
		}else return _mmod(_pmod(x,y^1,m),x,m);
	}

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

class EqualSums {
	public:
	int count(vector <string> board) {
		
	}
};
