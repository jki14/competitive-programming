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
#include <stack>
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
	template<class T> inline T SQR(const T x){ return x*x; }
	template<class T1, class T2> inline T1 POW(const T1 x, const T2 y){
		if(!y)return 1;else if((y&1)==0){
			return SQR(POW(x, y>>1));
		}else return POW(x, y^1)*x;
	}

	template<class T> inline int ISPRIME(const T x){
		if(x<=1)return 0;
		for(T i=2; SQR(i)<=x; i++)if(x%i==0)return 0;
		return 1;
	}
//TAIL_OF_JKI'S_HEADER

#define L 16

set<int> vst;
char buf[L];

int next(const int x){
	sprintf(buf, "%d", x);
	int nxt=0;
	for(int i=0; buf[i]; i++){
		nxt+=SQR(buf[i]-'0');
	}
	return nxt;
}

class ExploringNumbers {
	public:
	int numberOfSteps(int n){
		int m=n;
		vst.clear();
		for(int i=0; i<m; i++){
			if(ISPRIME(n)){
				return i+1;
			}
			if(vst.count(n)){
				return -1;
			}
			vst.insert(n);
			n=next(n);
		}
		return -1;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 1; verify_case(0, Arg1, numberOfSteps(Arg0)); }
	void test_case_1() { int Arg0 = 57; int Arg1 = 4; verify_case(1, Arg1, numberOfSteps(Arg0)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = -1; verify_case(2, Arg1, numberOfSteps(Arg0)); }
	void test_case_3() { int Arg0 = 6498501; int Arg1 = 2; verify_case(3, Arg1, numberOfSteps(Arg0)); }
	void test_case_4() { int Arg0 = 989113; int Arg1 = 6; verify_case(4, Arg1, numberOfSteps(Arg0)); }
	void test_case_5() { int Arg0 = 12366; int Arg1 = -1; verify_case(5, Arg1, numberOfSteps(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main() {
	ExploringNumbers __test;
	__test.run_test(-1);
}
// END CUT HERE
