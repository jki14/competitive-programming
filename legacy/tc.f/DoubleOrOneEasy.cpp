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

//HEAD_OF_JKI'S_HEADER_

	//COMPARE
	template<class T> inline T MIN(const T x, const T y){ return (x<y)?x:y; }
	template<class T> inline T MAX(const T x, const T y){ return (x>y)?x:y; }

	template<class T> inline void UPDMIN(T &x, const T y){ if(x>y)x=y; }
	template<class T> inline void UPDMAX(T &x, const T y){ if(x<y)x=y; }

//TAIL_OF_JKI'S_HEADER_

const int inf=0x3f3f3f3f;

class DoubleOrOneEasy {
	private:
	int calc(const int tar, const int dou){
		int rem=tar>>dou,ret=0;
		if(rem>1){
			ret=rem;
			rem=tar&((1<<dou)-1);
			for(int k=1; k<=rem; k<<=1){
				if(rem&k)ret++;
			}
		}else{
			for(int k=1; k<=tar; k<<=1){
				if(tar&k)ret++;
			}
		}
		return ret;
	}
	public:
	int minimalSteps(int a, int b, int newA, int newB){
		int ans=inf;
		for(int x=0; x<=30 && a*(1<<x)<=newA && b*(1<<x)<=newB; x++){
			if(newA-(a*(1<<x))!=newB-(b*(1<<x)))continue;
			int y=newA-(a*(1<<x));
			int k=x+calc(y, x);
			UPDMIN(ans, k);
		}
		if(ans!=inf)
			return ans;
		else return -1;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 100; int Arg1 = 1000; int Arg2 = 101; int Arg3 = 1001; int Arg4 = 1; verify_case(0, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 100; int Arg1 = 1000; int Arg2 = 202; int Arg3 = 2002; int Arg4 = 2; verify_case(1, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; int Arg3 = 1; int Arg4 = -1; verify_case(2, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 111111111; int Arg2 = 8; int Arg3 = 888888888; int Arg4 = 3; verify_case(3, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 111111111; int Arg2 = 9; int Arg3 = 999999999; int Arg4 = -1; verify_case(4, Arg4, minimalSteps(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main() {
	DoubleOrOneEasy __test;
	__test.run_test(-1);
}
// END CUT HERE
