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

//TAIL_OF_JKI'S_HEADER_

#define N 110

class CountryGroupHard {
	private:
	int n, a[N], f[N][N];
	int sati(const int x, const int y){
		int flag=0;
		for(int i=x-y; i<x; i++){
			if(flag && a[i] && a[i]!=flag)return 0;
			if(a[i])flag=a[i];
		}
		return (flag==0 || flag==y);
	}
	int judge(){
		int sum=0;
		for(int j=0; j<=n; j++){
			if(f[n][j] && sati(n, j)){
				sum+=f[n][j];
				if(sum>2)sum=2;
			}
		}
		return sum==1;
	}
	public:
	string solve(vector <int> arg_a){
		n=SIZE(arg_a);
		for(int i=0; i<n; i++)a[i]=arg_a[i];
		memset(f, 0, sizeof(f));f[0][0]=1;
		for(int i=0; i<n; i++){
			for(int j=0; j<=i; j++){
				if(!f[i][j])continue;
				//printf("f[%d][%d]=%d\n", i, j, f[i][j]);
				//not same
				if(sati(i, j)){
					f[i+1][1]+=f[i][j];
					if(f[i+1][1]>2)f[i+1][1]=2;
				}
				//same
				if(i && !(a[i-1] && a[i] && a[i-1]!=a[i])){
					f[i+1][j+1]+=f[i][j];
					if(f[i+1][j+1]>2)f[i+1][j+1]=2;
				}
			}
		}
		return judge()?"Sufficient":"Insufficient";
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,2,3,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Sufficient"; verify_case(0, Arg1, solve(Arg0)); }
	void test_case_1() { int Arr0[] = {0,2,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Insufficient"; verify_case(1, Arg1, solve(Arg0)); }
	void test_case_2() { int Arr0[] = {0,3,0,0,3,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Sufficient"; verify_case(2, Arg1, solve(Arg0)); }
	void test_case_3() { int Arr0[] = {0,0,3,3,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Insufficient"; verify_case(3, Arg1, solve(Arg0)); }
	void test_case_4() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Sufficient"; verify_case(4, Arg1, solve(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main() {
	CountryGroupHard __test;
	__test.run_test(-1);
}
// END CUT HERE
