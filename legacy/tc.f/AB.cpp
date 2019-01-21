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

class AB{

public:

	string createString(int n, int m){
		string ans;ans.clear();
		int top=(n>>1)*(n-(n>>1));
		if(top<m)return ans;
		for(int i=0; i<n; i++)
			ans.push_back(i<(n>>1)?'A':'B');
		int key=(n>>1)-1, pos;
		pos=key;
		while(top>m){
			printf("n=%d pos=%d ans=%c\n", n, pos, ans[pos+1]);
			if(pos<n && ans[pos+1]=='B'){
				swap(ans[pos], ans[pos+1]);
				pos++;
				top--;
			}else{
				pos=--key;
			}
		}
		return ans;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 0; string Arg2 = "ABB"; verify_case(0, Arg2, createString(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 0; string Arg2 = "BA"; verify_case(1, Arg2, createString(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 0; string Arg2 = ""; verify_case(2, Arg2, createString(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 0; string Arg2 = "BAABBABAAB"; verify_case(3, Arg2, createString(Arg0, Arg1)); }

// END CUT HERE


};

// BEGIN CUT HERE
int main(){
	AB ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
