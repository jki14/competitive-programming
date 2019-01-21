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

#define N 32
const int m=3;
const lld INF=0x3f3f3f3f3f3f3f3fLL;

int n;
char a[N];
lld f[N][m], ans;

int main_entry(){
	memset(f, 0x3f, sizeof(f));
	switch(a[0]){
		case '?':
			f[0][0]=4LL;
			f[0][1]=8LL;
			f[0][2]=1LL;
			break;
		case '9':
			f[0][2]=9LL;
			break;
		case '8':
			f[0][1]=8LL;
			f[0][2]=8LL;
			break;
		case '7':
			f[0][0]=7LL;
			break;
		case '5':
			f[0][2]=5LL;
			break;
		case '4':
			f[0][0]=4LL;
			break;
		case '1':
			f[0][2]=1LL;
			break;
		default:
			return 1;
	}
	for(int i=0; i+1<n; i++){
		if(f[i][0]!=INF){
			switch(a[i+1]){
				case '?':
					UPDMIN(f[i+1][0], f[i][0]*10LL+4LL);
					UPDMIN(f[i+1][1], f[i][0]*10LL+8LL);
					UPDMIN(f[i+1][2], f[i][0]*10LL+5LL);
					break;
				case '9':
					UPDMIN(f[i+1][2], f[i][0]*10LL+9LL);
					break;
				case '8':
					UPDMIN(f[i+1][1], f[i][0]*10LL+8LL);
					UPDMIN(f[i+1][2], f[i][0]*10LL+8LL);
					break;
				case '7':
					UPDMIN(f[i+1][0], f[i][0]*10LL+7LL);
					break;
				case '5':
					UPDMIN(f[i+1][2], f[i][0]*10LL+5LL);
					break;
				case '4':
					UPDMIN(f[i+1][0], f[i][0]*10LL+4LL);
			}
		}
		if(f[i][1]!=INF){
			switch(a[i+1]){
				case '?':
					UPDMIN(f[i+1][1], f[i][1]*10LL+8LL);
					UPDMIN(f[i+1][2], f[i][1]*10LL+9LL);
					break;
				case '9':
					UPDMIN(f[i+1][2], f[i][1]*10LL+9LL);
					break;
				case '8':
					UPDMIN(f[i+1][1], f[i][1]*10LL+8LL);
			}
		}
		if(f[i][2]!=INF){
			switch(a[i+1]){
				case '?':
					UPDMIN(f[i+1][1], f[i][2]*10LL+1LL);
					UPDMIN(f[i+1][2], f[i][2]*10LL+2LL);
					UPDMIN(f[i+1][1], f[i][2]*10LL+4LL);
					UPDMIN(f[i+1][2], f[i][2]*10LL+5LL);
					break;
				case '5':
					UPDMIN(f[i+1][2], f[i][2]*10LL+5LL);
					break;
				case '4':
					UPDMIN(f[i+1][1], f[i][2]*10LL+4LL);
					break;	
				case '2':
					UPDMIN(f[i+1][2], f[i][2]*10LL+2LL);
					break;
				case '1':
					UPDMIN(f[i+1][1], f[i][2]*10LL+1LL);
			}
		}

	}
	ans=f[n-1][1];
	if(ans==INF)return 1;
	return 0;
}

class LuckySum {
	public:
	long long construct(string note){
		n=LENGTH(note);
		for(int i=0; i<n; i++)a[i]=note[i];
		if(main_entry()){
			return -1LL;
		}
		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "?"; long long Arg1 = 8LL; verify_case(0, Arg1, construct(Arg0)); }
	void test_case_1() { string Arg0 = "?1"; long long Arg1 = 11LL; verify_case(1, Arg1, construct(Arg0)); }
	void test_case_2() { string Arg0 = "4?8"; long long Arg1 = 448LL; verify_case(2, Arg1, construct(Arg0)); }
	void test_case_3() { string Arg0 = "2??"; long long Arg1 = -1LL; verify_case(3, Arg1, construct(Arg0)); }
	void test_case_4() { string Arg0 = "??????????????"; long long Arg1 = 11888888888888LL; verify_case(4, Arg1, construct(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main() {
	LuckySum __test;
	__test.run_test(-1);
}
// END CUT HERE
