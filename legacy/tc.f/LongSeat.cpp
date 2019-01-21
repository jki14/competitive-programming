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

	//STL
	template<class T>  inline int SIZE(const T &x){ return (int)x.size(); }

//TAIL_OF_JKI'S_HEADER_

int n, sum, cnt;
vector<string> buff;
vector<int> pool;

int must(const int w){
	sort(pool.begin(), pool.end(), greater<int>());
	int size=SIZE(pool);
	int unsum=sum;
	for(int i=0;i<=size;i++){
		if(unsum*1LL<w*1LL*(cnt+i))return 0;
		if(i<size)unsum-=pool[i];
	}
	return 1;
}

class LongSeat {
	public:
	vector <string> canSit(int L, vector <int> width){
		n=SIZE(width);sum=L;cnt=1;
		buff.clear();
		pool.clear();
		for(int i=0;i<n;i++){
			//printf("sum=%d", sum);
			 if(must(width[i])){
				buff.push_back(string("Sit"));
				cnt++;
				sum-=width[i];
			}else if(sum<width[i]){
				buff.push_back(string("Stand"));
			}else{
				buff.push_back(string("Unsure"));
				pool.push_back(width[i]);
			}
		}
		return buff;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 2; int Arr1[] = {1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"Sit", "Unsure" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, canSit(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 10; int Arr1[] = {100, 2, 4, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"Stand", "Sit", "Sit", "Unsure" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, canSit(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 37; int Arr1[] = {3, 7, 5, 6, 4, 4, 1, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"Sit", "Sit", "Sit", "Unsure", "Unsure", "Unsure", "Sit", "Unsure" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, canSit(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 400; int Arr1[] = {92, 65, 99, 46, 24, 85, 95, 84}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"Sit", "Sit", "Unsure", "Unsure", "Unsure", "Unsure", "Stand", "Unsure" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, canSit(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1000000000; int Arr1[] = {1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"Sit", "Stand", "Stand", "Stand", "Stand", "Stand", "Stand", "Stand" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, canSit(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 1; int Arr1[] = {1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"Stand", "Stand", "Stand", "Stand", "Stand", "Stand", "Stand", "Stand" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, canSit(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main() {
	LongSeat __test;
	__test.run_test(-1);
}
// END CUT HERE
