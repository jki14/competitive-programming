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
	template<class T>  inline int SIZE(const T &x){ return (int)x.size(); }

//TAIL_OF_JKI'S_HEADER

class AlmostFibonacciKnapsack {
	private:
	vector<lld> fib, pre;
	bitset<100> sup[100], key;
	int find(const lld x){ 
		int lef=0, rig=SIZE(pre)-1;
		while(lef<=rig){
			int mid=(lef+rig)>>1;
			if(pre[mid]>=x){
				if(mid==lef || pre[mid-1]<x)return mid;
				rig=mid-1;
			}else lef=mid+1;
		}
		printf("oops!!\n");
		return -1; 
	}
	int first(const lld x){
		if(x==1LL)return -1;
		int y=find(x);
		//printf("%d\n", y);
		key^=sup[y+1];
		if(pre[y]==x){
			return 0;
		}else return first(pre[y]-x)*-1;
	}
	int second(){
		//printf("second()\n");
		for(int i=99; i>1; i--){
			if(key[i])continue;
			if(key[i-1] && key[i-2]){
				key[i]=1;
				key[i-1]=0;
				key[i-2]=0;
				return 0;
			}
		}
		return 1;
	}
	int second_(){
		//printf("second_()\n");
		for(int i=0; i<98; i++){
			if(key[i] || key[i+1])continue;
			if(key[i+2]){
				key[i]=1;
				key[i+1]=1;
				key[i+2]=0;
				return 0;
			}
		}
		return -1;
	}
	public:
	AlmostFibonacciKnapsack(){
		for(int i=0; i<100; i++)sup[i]=bitset<100>(string(i, '1'));
		fib.clear();
		fib.push_back(2LL);
		fib.push_back(3LL);
		for(int idx=2; ; idx++){
			lld cur=fib[idx-2]+fib[idx-1]-1LL;
			if(cur>1000000000000000000LL)break;
			fib.push_back(cur);
		}
		pre.clear();
		pre.push_back(fib[0]);
		for(int idx=1; ; idx++){
			lld cur=pre[idx-1]+fib[idx];
			pre.push_back(cur);
			if(cur>1000000000000000000LL)break;
		}
	}
	vector <int> getIndices(long long x){
		key.reset();
		int f=first(x);
		if(f==1){
			if(second()){
				printf("+Error %lld!!\n", x);
			}
		}else if(f==-1){
			if(second_()){
				printf("-Error %lld!!\n", x);
			}
		}
		vector<int> res;
		lld sum=0LL;
		for(int i=0; i<100; i++)if(key[i]){
			res.push_back(i+1);
			sum+=fib[i];
		}
		if(sum!=x)printf("=Error %lld!!\n", x);
		return res;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { long long Arg0 = 148LL; int Arr1[] = {6, 10, 8, 5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getIndices(Arg0)); }
	void test_case_1() { long long Arg0 = 2LL; int Arr1[] = {1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getIndices(Arg0)); }
	void test_case_2() { long long Arg0 = 13LL; int Arr1[] = {2, 3, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getIndices(Arg0)); }
	void test_case_3() { long long Arg0 = 3LL; int Arr1[] = {2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getIndices(Arg0)); }
	void test_case_4() { long long Arg0 = 86267769395LL; int Arr1[] = {3, 14, 15, 9, 26, 53, 5, 8 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, getIndices(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main() {
	AlmostFibonacciKnapsack __test;
	__test.run_test(-1);
	for(lld i=2LL; i<100000000LL; i++)
		__test.getIndices(i);
}
// END CUT HERE
