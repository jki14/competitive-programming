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


static const int one_arr[6] = {0, 1, 1, 2, 2, 3};
static const vector<int> one_vec(one_arr, one_arr+6);

class TreeAndPathLength3 {
	private:
	inline void add_edge(vector<int> &buf, const int u, const int v){
		buf.push_back(u);
		buf.push_back(v);
	}
	public:
	vector <int> construct(int s){
		if(s==1)return one_vec;
		vector<int> ans;
		ans.clear();
		int cnt=2, k=1;
		while(cnt*(cnt+1)<=s)cnt++;
		for(int i=0; i<cnt; i++){
			add_edge(ans, 0, k);
			add_edge(ans, k, k+1);
			k+=2;
		}
		for(s-=cnt*(cnt-1); s; s--){
			add_edge(ans, k-1, k);
			k+=1;
		}
		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 10000; int Arr1[] = {0, 1, 1, 2, 2, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, construct(Arg0)); }
	void test_case_1() { int Arg0 = 2; int Arr1[] = {0, 1, 1, 2, 2, 3, 3, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, construct(Arg0)); }
	void test_case_2() { int Arg0 = 6; int Arr1[] = {0, 1, 1, 2, 0, 3, 3, 4, 0, 5, 5, 6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, construct(Arg0)); }
	void test_case_3() { int Arg0 = 8; int Arr1[] = {0, 1, 1, 2, 1, 3, 3, 4, 3, 5, 5, 6, 5, 7 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, construct(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main() {
	TreeAndPathLength3 __test;
	__test.run_test(-1);
}
// END CUT HERE
