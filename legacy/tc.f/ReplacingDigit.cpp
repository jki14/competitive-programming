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
	template<class T>  inline int SIZE(const T &x){ return (int)x.size(); }
	template<class T>  inline int LENGTH(const T &x){ return (int)x.length(); }
	template<class T1, class T2> inline pair<T1, T2> MP(const T1 &x, const T2 &y){ return make_pair(x, y); }
//TAIL_OF_JKI'S_HEADER

#define L 8

int n;
vector<int> dig[L];
priority_queue<int> pq;

void init(int x){
	for(int i=0; x>0; i++, x/=10){
		dig[i].push_back(x%10);
	}
}

void greedy_entry(){
	for(int i=L-1; ~i; i--){
		if(dig[i].empty())continue;
		sort(dig[i].begin(), dig[i].end());
		for(vector<int>::iterator it=dig[i].begin(); it!=dig[i].end(); it++){
			if(pq.empty() || pq.top()<=*it)break;
			*it=pq.top();
			pq.pop();
		}
	}
}

int get_result(){
	int sum=0, base=1;
	for(int i=0; i<L; i++){
		for(vector<int>::iterator it=dig[i].begin(); it!=dig[i].end(); it++){
			sum+=base*(*it);
		}
		base*=10;
	}
	return sum;
}

class ReplacingDigit {
	public:
	int getMaximumStockWorth(vector <int> A, vector <int> D){
		n = SIZE(A);
		for(int i=0; i<L; i++){
			dig[i].clear();
		}
		for(vector<int>::const_iterator it=A.begin(); it!=A.end(); it++){
			init(*it);
		}
		while(!pq.empty())pq.pop();
		for(int i=0; i<SIZE(D); i++){
			for(int k=0; k<D[i]; k++)
				pq.push(i+1);
		}
		greedy_entry();
		return get_result();
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {100, 90}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0, 0, 0, 2, 1, 0, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 745; verify_case(0, Arg2, getMaximumStockWorth(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 1, 1, 1, 1, 1, 1, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; verify_case(1, Arg2, getMaximumStockWorth(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {123456}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9, 8, 7, 6, 5, 4, 3, 2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 988777; verify_case(2, Arg2, getMaximumStockWorth(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {10, 970019, 1976, 10936, 68750, 756309, 37600, 559601, 6750, 76091, 640, 312, 312, 90, 8870}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {11, 2, 8, 10, 7, 6, 3, 1, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3297500; verify_case(3, Arg2, getMaximumStockWorth(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {111, 111, 111, 111, 111, 111, 111, 111, 111}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 198; verify_case(4, Arg2, getMaximumStockWorth(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main() {
	ReplacingDigit __test;
	__test.run_test(-1);
}
// END CUT HERE
