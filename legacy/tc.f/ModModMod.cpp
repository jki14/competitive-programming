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

	//STL
	template<class T>  inline int SIZE(const T &x){ return (int)x.size(); }
	template<class T>  inline int LENGTH(const T &x){ return (int)x.length(); }
	template<class T1, class T2> inline pair<T1, T2> MP(const T1 &x, const T2 &y){ return make_pair(x, y); }

//TAIL_OF_JKI'S_HEADER_

#define N 5100
#define M 11000000

int n, m, a[N], buf[M];

class ModModMod {
	public:
	long long findSum(vector <int> arr, int R){	
		n=SIZE(arr);m=0;
		for(int i=0;i<n;i++){
			if(m && a[m-1]<=arr[i])continue;
			a[m++]=arr[i];
		}
		int key=m-2, cur=-1;
		lld ans=0LL;
		for(int x=0; x<=R; x++){
			if(x<a[m-1]){
				buf[x]=x;
			}else{
				if(key>=0){
					if(!(x%a[key])){
						buf[x]=buf[cur=0];
						key--;
					}else buf[x]=buf[++cur];
				}else buf[x]=buf[++cur];
			}
			//printf("buf[%d]=%d\n", x, buf[x]);
			ans+=buf[x]*1LL;
		}
		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5,3,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; long long Arg2 = 4LL; verify_case(0, Arg2, findSum(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {33, 15, 7, 10, 100, 9, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 64; long long Arg2 = 92LL; verify_case(1, Arg2, findSum(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {995,149,28,265,275,107,555,241,702,462,519,212,362,478,783,381,602,546,183,886,59,317,977,612,328,91,771,131}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 992363; long long Arg2 = 12792005LL; verify_case(2, Arg2, findSum(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; long long Arg2 = 4950LL; verify_case(3, Arg2, findSum(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {2934}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10000000; long long Arg2 = 14664070144LL; verify_case(4, Arg2, findSum(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main() {
	ModModMod __test;
	__test.run_test(-1);
}
// END CUT HERE
