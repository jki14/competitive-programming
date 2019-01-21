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

static const int MOD=1000000007;
static const long long MODL=1000000000000000003LL;

//TAIL_OF_CONFIG_

//HEAD_OF_JKI'S_HEADER_

	//REMINDER-LIZATION
	template<class T> inline T MOD_STD(const T x, const T m=MOD){ return (x%m+m)%m; }
	template<class T> inline void MOD_STD(T *x, const T m=MOD){ *x=(*x%m+m)%m; }
	template<class T> inline T MOD_ADD(const T x, const T y, const T m=MOD){ return (x+y)%m; }
	template<class T> inline void MOD_ADD(T *x, const T y, const T m=MOD){ *x=(*x+y)%m; }
	template<class T> inline T MOD_MUL(const T x, const T y, const T m=MOD){ return (T)((1LL*x*y)%m); }
	template<class T> inline void MOD_MUL(T *x, const T y, const T m=MOD){ *x=(T)((1LL*(*x)*y)%m); }
	template<class T1, class T2> inline T1 MOD_POW(const T1 x, const T2 y, const T1 m=MOD){
		if(y==0)return 1%m;else if((y&1)==0){
			T1 z=MOD_POW(x, y>>1, m); return MOD_MUL(z, z, m);
		}else return MOD_MUL(MOD_POW(x, y^1, m), x, m);
	}

//TAIL_OF_JKI'S_HEADER_

class point_t{
	public:
	int x, y;
	point_t(const int lhs=0, const int rhs=0){
		this->x=lhs;
		this->y=rhs;
	}
	bool operator < (const point_t &rhs) const{
		return (this->x!=rhs.x)?(this->x<rhs.x):(this->y<rhs.y);
	}
};

class TheEmpireStrikesBack {
	private:
	int n, m, k;
	vector<point_t> p, a;
	int able(const int cap){
		int cur=k, i=0, j;
		for(; i<m; i++){
			if(!cur)return 0;
			cur--;
			for(j=i; j+1<m && a[i].y-a[j+1].y<=cap; )j++;
			for(i=j; i+1<m && a[i+1].x-a[j].x<=cap; )i++;
		}
		return 1;
	}
	int core_entry(){
		int lef=0, rig=a[0].y-a[m-1].y;
		while(lef<=rig){
			int mid=(lef+rig)>>1;
			if(able(mid)){
				if(mid==lef || !able(mid-1))return mid;
				rig=mid-1;
			}else lef=mid+1;
		}
		return -1;
	}
	public:
	int find(int AX, int BX, int CX, int AY, int BY, int CY, int N, int M){
		n=N; m=0; k=M;
		p.resize(n);
		a.resize(n);
		p[0].x=MOD_STD(AX);
		p[0].y=MOD_STD(AY);
		for(int i=1; i<n; i++){
			p[i].x=MOD_STD(MOD_ADD(MOD_MUL(p[i-1].x,BX),CX));
			p[i].y=MOD_STD(MOD_ADD(MOD_MUL(p[i-1].y,BY),CY));
		}
		sort(p.begin(), p.end());
		for(int i=0; i<n; i++){
			while(m>0 && a[m-1].y<=p[i].y)m--;
			a[m].x=p[i].x;
			a[m].y=p[i].y;
			m++;
		}
		a.resize(m);
		return core_entry();
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; int Arg3 = 2; int Arg4 = 2; int Arg5 = 2; int Arg6 = 2; int Arg7 = 1; int Arg8 = 0; verify_case(0, Arg8, find(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; int Arg3 = 2; int Arg4 = 4; int Arg5 = 1000000000; int Arg6 = 2; int Arg7 = 1; int Arg8 = 1; verify_case(1, Arg8, find(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 3; int Arg2 = 8; int Arg3 = 10000; int Arg4 = 10; int Arg5 = 999910000; int Arg6 = 3; int Arg7 = 1; int Arg8 = 30; verify_case(2, Arg8, find(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_3() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; int Arg4 = 0; int Arg5 = 0; int Arg6 = 100000; int Arg7 = 1000; int Arg8 = 0; verify_case(3, Arg8, find(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_4() { int Arg0 = 10; int Arg1 = 20; int Arg2 = 30; int Arg3 = 40; int Arg4 = 50; int Arg5 = 60; int Arg6 = 100000; int Arg7 = 10; int Arg8 = 15720; verify_case(4, Arg8, find(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main() {
	TheEmpireStrikesBack __test;
	__test.run_test(-1);
}
// END CUT HERE
