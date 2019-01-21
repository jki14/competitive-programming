// BEGIN CUT HERE
// PROBLEM STATEMENT
// This problem statement contains superscripts and/or subscripts. These may not display properly outside the applet.

Manao is studying graph theory and simple cycles in particular. A simple cycle of length L ≥ 3 in graph G is a sequence of vertices (v0, v1, ..., vL-1) such that all v0, v1, ..., vL-1 are pairwise distinct and for each i=0..L-1, an edge between vi and v(i+1) mod L exists in G.

Manao is interested in graphs formed by connecting two trees. The connection process is as follows. Manao takes two trees composed of N vertices each. The vertices in each tree are labeled from 0 to N - 1. Then, he generates a permutation P of numbers from 0 to N - 1 uniformly at random. Finally, the graph is formed by connecting vertex i of the first tree to vertex P[i] of the second tree, for each i from 0 to N - 1. To remove ambiguity, the vertices of the first tree within the graph are referred to as A0, A1, ..., AN-1 and the vertices of the second graph are referred to as B0, B1, ..., BN-1. Manao wants to know the expected number of simple cycles of length K in the resulting graph.

You are given two vector <string>s, tree1 and tree2. Merge the elements of tree1 to obtain a single string formatted as a space-separated list of N - 1 integers describing the first tree. Let x[i] denote the i-th integer (0-based index) in the list. Then, for each i, we have 0 ≤ x[i] ≤ i and in our tree the vertices x[i] and i+1 are connected by an edge. tree2 describes the second tree in the same fashion.
Compute and return the expected number of simple cycles of length K in the graph formed by connecting the two given trees as described above. Two simple cycles are equal if one of them can be cyclically shifted, or reversed and cyclically shifted, to coincide with the second. According to this definition, (1, 2, 3, 4), (2, 3, 4, 1) and (3, 2, 1, 4) are all equal.

DEFINITION
Class:TreeUnion
Method:expectedCycles
Parameters:vector <string>, vector <string>, int
Returns:double
Method signature:double expectedCycles(vector <string> tree1, vector <string> tree2, int K)


NOTES
-The returned value must have an absolute or relative error less than 1e-9.


CONSTRAINTS
-The concatenation of elements of tree1 will be formatted as a space-separated list of N - 1 integers, where N is between 2 and 300, inclusive.
-tree1 will contain between 1 and 50 elements, inclusive.
-Each element of tree1 will be between 1 and 50 characters long, inclusive.
-For each i, the i-th integer (0-based index) in the concatenation of elements of tree1 will be between 0 and i, inclusive, and will have no extra leading zeros.
-The concatenation of elements of tree2 will be formatted as a space-separated list of N - 1 integers, where N is between 2 and 300, inclusive.
-tree2 will contain between 1 and 50 elements, inclusive.
-Each element of tree2 will be between 1 and 50 characters long, inclusive.
-For each i, the i-th integer (0-based index) in the concatenation of elements of tree2 will be between 0 and i, inclusive, and will have no extra leading zeros.
-K will be between 3 and 7, inclusive.


EXAMPLES

0)
{"0"}
{"0"}
4

Returns: 1.0

Manao has two trees with two vertices each. He can connect them in two ways:



Either way, the resulting graph is a single cycle of length 4.

1)
{"0 1"}
{"0 1"}
4

Returns: 1.3333333333333333

Manao has two chains composed of three vertices each. There are 6 possible permutations which result in the following graphs:



Each of the two graphs shown in the topmost row contains two cycles of length 4.
(Note that in each case the two cycles share the edge A1B1.)
Each of the other four graphs only contains one cycle of length 4.
Thus the expected number of cycles of length 4 is (2+2+1+1+1+1)/6 = 8/6 = 1.3333333333.

2)
{"0 1"}
{"0 1"}
6

Returns: 0.3333333333333333

These are the same trees as in the previous example, but this time Manao is looking for simple cycles with 6 vertices. Only the topmost two graphs contain a cycle of length 6, thus the expected number of such cycles for a random permutation P is 1/3.

3)
{"0 ", "1 1 1"}
{"0 1 0 ", "1"}
5

Returns: 4.0

The corresponding trees are these:




4)
{"0 1 2 0 1 2 0 1 2 5 6 1", "0 11", " 4"}
{"0 1 1 0 2 3 4 3 4 6 6", " 10 12 12"}
7

Returns: 13.314285714285713

Do not forget to concatenate the elements of the lists first.

// END CUT HERE
#line 99 "TreeUnion.cpp"

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

#define N 1100

int n;
int a[N][N],b[N][N];
int sa[N],sb[N];
char cs[N];

void tran(const string &_a,int a[N][N]){
	int p=0,u=1,v;
	for(int i=0;i<_size(_a);i++){
		if(_a[i]==' '){
			if(!p)continue;
			cs[p++]=0;
			sscanf(cs,"%d",&v);
			a[u][v]=a[v][u]=1;
			u++;p=0;
		}else cs[p++]=_a[i];
	}
	n=u;
}

void floyed(int a[N][N],int sa[N]){
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				_updmin(a[i][j],a[i][k]+a[k][j]);
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			sa[a[i][j]]++;
}

class TreeUnion {
	public:
	double expectedCycles(vector <string> _a, vector <string> _b, int K) {	
		string tmp;tmp.clear();
		for(int i=0;i<_size(_a);i++)tmp=tmp+_a[i];
		memset(a,0x3f,sizeof(a));
		tran(tmp,a);
		tmp.clear();
		for(int i=0;i<_size(_b);i++)tmp=tmp+_b[i];
		memset(b,0x3f,sizeof(b));
		tran(tmp,b);
		for(int i=0;i<n;i++)a[i][i]=b[i][i]=0;
		memset(sa,0,sizeof(sa));
		memset(sb,0,sizeof(sb));
		floyed(a,sa);floyed(b,sb);
		double ans=0.0;
		for(int i=1;i<n;i++){
			int j=K-i-2;
			if(j<=0)continue;
			ans+=((double)sa[i])*((double)sb[j])*2.0;
		}
		ans/=(double)(n*(n-1));
		return ans;
	}
};
