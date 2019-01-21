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

//HEAD_OF_CONFIG_

static const int MOD=1000000007;
static const long long MODL=1000000000000000003LL;
static const double eps=1e-8;

//TAIL_OF_CONFIG_

//HEAD_OF_JKI'S_HEADER_

	//TYPEDEF
	typedef long long lld;
	typedef unsigned long long u64;
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

//TAIL_OF_JKI'S_HEADER

#define N 64
#define S 3100000
#define B 2

#define pre (cur^1)

lld f[B][S];
int v[S], mrk;
int n, cur;

queue<int> que[B];

inline void update(const int x, const lld val, const int i){
	//printf("update(%d,%lld,%i)\n", x, val, i);
	if((x*1LL) < (1LL<<(n-i))){
		if(v[x]!=mrk){
			v[x]=mrk;
			f[cur][x]=0LL;
			que[cur].push(x);
		}
		f[cur][x]+=val;
	}
}

class BracketSequenceDiv1 {
	public:
	long long count(string s){
		n=LENGTH(s);cur=0;
		memset(v, 0xff, sizeof(v));mrk=0;
		while(!que[cur].empty())que[cur].pop();
		while(!que[pre].empty())que[pre].pop();
		f[cur][1]=1LL;
		que[cur].push(1);
		for(int i=0; i<n; i++){
			cur=pre;mrk++;
			for(;!que[pre].empty();que[pre].pop()){
				int x=que[pre].front();
				lld z=f[pre][x];
				update(x, z, i);
				switch(s[i]){
					case '(':
						x=(x<<1)|0;
						update(x, z, i);
						break;
					case ')':
						if(x>1 && (x&1)==0){
							x>>=1;
							update(x, z, i);
						}
						break;
					case '[':
						x=(x<<1)|1;
						update(x, z, i);
						break;
					default:
						if(x>1 && (x&1)==1){
							x>>=1;
							update(x, z, i);
						}
				}
			}
		}
		if(v[1]!=mrk){
			f[cur][1]=0LL;
		}
		return f[cur][1]-1LL;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "[[[[[[[[[[[[[[[[[[[[]]]]]]]]]]]]]]]]]]]]"; long long Arg1 = 3LL; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arg0 = "())"; long long Arg1 = 2LL; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arg0 = "()()"; long long Arg1 = 4LL; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { string Arg0 = "([)]"; long long Arg1 = 2LL; verify_case(3, Arg1, count(Arg0)); }
	void test_case_4() { string Arg0 = "())[]][]([]()]]()]]]"; long long Arg1 = 3854LL; verify_case(4, Arg1, count(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main() {
	BracketSequenceDiv1 __test;
	__test.run_test(-1);
}
// END CUT HERE
