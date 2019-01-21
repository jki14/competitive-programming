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
	
	//COMPARE
	template<class T> inline void UPDMIN(T &x, const T y){ if(x>y)x=y; }
	template<class T> inline void UPDMAX(T &x, const T y){ if(x<y)x=y; }

	//STL
	template<class T>  inline int SIZE(const T &x){ return (int)x.size(); }

//TAIL_OF_JKI'S_HEADER_

#define B 2
#define N 52
#define C 102

const int DEF=0xc0c0c0c0;

int n, a[B][N], ans;
int dp[C][C][N][N];

int core_entry(const int count, const int val, const int ex, const int ey){
	if(~dp[count][val][ex][ey])return dp[count][val][ex][ey];
	dp[count][val][ex][ey]=DEF;
	int k=count&1;
	//error-echeck
	if(count==0){
		if(ex==0 && ey==0)dp[count][val][ex][ey]=0;
		return dp[count][val][ex][ey];
	}
	//push-out;
	for(int i=0;i<n;i++){
		if(a[k][i]>val)continue;
		UPDMAX(dp[count][val][ex][ey], core_entry(count-1, a[k][i]-1, ex, ey)+1);
	}
	//eat-it
	if(k==0){
		if(ex)UPDMAX(dp[count][val][ex][ey], core_entry(count-1, val, ex-1, ey));
	}else{
		if(ey)UPDMAX(dp[count][val][ex][ey], core_entry(count-1, val, ex, ey-1));
	}
	//if(dp[count][val][ex][ey]>0)printf("dp[%d][%d][%d][%d]=%d\n", count, val, ex, ey, dp[count][val][ex][ey]);
	return dp[count][val][ex][ey];
}

class YetAnotherCardGame {
	public:
	int maxCards(vector <int> petr, vector <int> snuke){
		n=SIZE(petr);
		for(int i=0; i<n; i++)a[1][i]=petr[i];
		for(int i=0; i<n; i++)a[0][i]=snuke[i];
		memset(dp, 0xff, sizeof(dp));
		ans=DEF;
		for(int ex=0; ex<=n; ex++){
			for(int ey=0; ey<=n; ey++){
				UPDMAX(ans, core_entry(n*2, 100, ex, ey));
			}
		}
		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(0, Arg2, maxCards(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 1, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(1, Arg2, maxCards(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1, 4, 6, 7, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 7, 1, 5, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(2, Arg2, maxCards(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {19, 99, 86, 30, 98, 68, 73, 92, 37, 69, 93, 28, 58, 36, 86, 32, 46, 34, 71, 29}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {28, 29, 22, 75, 78, 75, 39, 41, 5, 14, 100, 28, 51, 42, 9, 25, 12, 59, 98, 83}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 28; verify_case(3, Arg2, maxCards(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main() {
	YetAnotherCardGame __test;
	__test.run_test(-1);
}
// END CUT HERE
