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

//TAIL_OF_CONFIG_

//HEAD_OF_JKI'S_HEADER_

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

#define N 2600

int n, ans;
int a[N]/*, buf[N]*/;
int presum[N], precnt[N];
int nxtsum[N], nxtcnt[N];

int pre(int lef, int rig){
	lef++;rig++;
	UPDMAX(lef, 1);
	UPDMIN(rig, n);
	if(lef>rig)return 0;
	//printf("%d<-%d = %d\n", lef, rig,  (presum[lef]-presum[rig+1])-(precnt[lef]-precnt[rig+1])*(n-rig));
	//printf("presum[%d]=%d, presum[%d]=%d\n", lef, presum[lef], rig+1, presum[rig+1]);
	//printf("precnt[%d]=%d, precnt[%d]=%d\n", lef, precnt[lef], rig+1, precnt[rig+1]);
	return (presum[lef]-presum[rig+1])-(precnt[lef]-precnt[rig+1])*(n-rig);
}

int nxt(int lef, int rig){
	lef++;rig++;
	UPDMAX(lef, 1);
	UPDMIN(rig, n);
	if(lef>rig)return 0;
	//printf("%d->%d = %d\n", lef, rig,  (nxtsum[rig]-nxtsum[lef-1])-(nxtcnt[rig]-nxtcnt[lef-1])*(lef-1));
	//printf("nxtsum[%d]=%d, nxtsum[%d]=%d\n", rig, nxtsum[rig], lef-1, nxtsum[lef-1]);
	//printf("nxtcnt[%d]=%d, nxtcnt[%d]=%d\n", rig, nxtcnt[rig], lef-1, nxtcnt[lef-1]);
	return (nxtsum[rig]-nxtsum[lef-1])-(nxtcnt[rig]-nxtcnt[lef-1])*(lef-1);
}

int main_entry(){
	ans=0;

	precnt[n+1]=presum[n+1]=0;
	for(int i=n; i; i--){
		precnt[i]=precnt[i+1]+a[i-1];
		presum[i]=presum[i+1]+(a[i-1]?(n-i+1):0);
	}
	precnt[0]=precnt[1];
	presum[0]=presum[1];

	nxtcnt[0]=nxtsum[0]=0;
	for(int i=1; i<=n; i++){
		nxtcnt[i]=nxtcnt[i-1]+a[i-1];
		nxtsum[i]=nxtsum[i-1]+(a[i-1]?i:0);
	}
	nxtcnt[n+1]=nxtcnt[n];
	nxtsum[n+1]=nxtsum[n];

	/*for(int i=n-1; ~i; i--){
		buf[i]=1;
		if(i<n-1 && !a[i+1])buf[i]=buf[i+1]+1;
	}*/
	for(int hed=0; hed<n; hed++){
		int til=hed;
		for(int mid=hed; mid<n && til<n; mid++){
			int count=pre(hed, mid-1);
			UPDMAX(til, mid);
			while(til<n && nxt(mid+1, til)<count)til++;
			while(til<n && nxt(mid+1, til)==count){
				//printf("hed=%d mid=%d til=%d\n", hed, mid ,til);
				ans++;
				til++;
			}
			//printf("ans=%d\n", ans);
		}
	}
	return ans;
}

class BalancedSubstrings {
	public:
	int countSubstrings(string s){
		n=LENGTH(s);
		for(int i=0; i<n; i++)
			a[i]=s[i]-'0';
		return main_entry();
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cout << "Test Case #" << Case << "..."; if (Expected == Received) cout << "PASSED" << endl; else { cout << "FAILED" << endl; cout << "\tExpected: \"" << Expected << '\"' << endl; cout << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "011"; int Arg1 = 4; verify_case(0, Arg1, countSubstrings(Arg0)); }
	void test_case_1() { string Arg0 = "10111"; int Arg1 = 10; verify_case(1, Arg1, countSubstrings(Arg0)); }
	void test_case_2() { string Arg0 = "00000"; int Arg1 = 15; verify_case(2, Arg1, countSubstrings(Arg0)); }
	void test_case_3() { string Arg0 = "0000001000000"; int Arg1 = 91; verify_case(3, Arg1, countSubstrings(Arg0)); }
	void test_case_4() { string Arg0 = "100110001001"; int Arg1 = 49; verify_case(4, Arg1, countSubstrings(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main() {
	BalancedSubstrings __test;
	__test.run_test(-1);
}
// END CUT HERE
