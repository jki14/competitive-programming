// BEGIN CUT HERE
// PROBLEM STATEMENT
// John has a sequence of digits.
He and Brus will now play with the sequence.


First, John will repeat the following operation k times:
He will choose two different positions in the sequence, and swap the elements at those positions.
(John makes each choice uniformly at random.
That is, each time John chooses two positions, each pair of different positions has the same probability of being chosen.)


Afterwards, Brus will randomly choose a non-empty contiguous subsequence of John's sequence.
He will compute the sum of all elements in the chosen subsequence and he will write it down on a piece of paper.
(Brus also makes his choice uniformly at random.
That is, each possible contiguous subsequence has the same probability of being chosen.)


You are given a vector <string> sequence.
Concatenate all elements of sequence to get the string s.
For each i, the i-th character of s is a digit ('0'-'9') representing the digit at index i in John's original sequence.


Return the expected value of the sum Brus writes down.

DEFINITION
Class:TheSwapsDivOne
Method:find
Parameters:vector <string>, int
Returns:double
Method signature:double find(vector <string> sequence, int k)


NOTES
-The returned value must be accurate to within a relative or absolute value of 1E-9.


CONSTRAINTS
-sequence will contain between 2 and 47 elements, inclusive.
-Each element of sequence will contain between 1 and 47 characters, inclusive.
-Each element of sequence will consist of only decimal digits ('0'-'9').
-k will be between 1 and 1,000,000, inclusive.


EXAMPLES

0)
{"4", "77"}
1

Returns: 10.0

There are three equally likely swaps John might make.
If the first two elements are swapped, John will get the sequence {7,4,7}.
Then Brus chooses one of the six possible subsequences.
Their sums are 7, 4, 7, 11, 11 and 18.
Thus the expected value is (7 + 4 + 7 + 11 + 11 + 18)/6 = 29/3.

If the first and the last elements are swapped, the sequence becomes {7,7,4}, and the subsequence sums are 7, 7, 4, 14, 11 and 18.
The expected value in this case is (7 + 7 + 4 + 14 + 11 + 18)/6 = 61/6.

When the last two elements are swapped, the sequence doesn't change and the expected value is equal to 61/6 as well.
Finally, the overall expected value is equal to (29/3 + 61/6 + 61/6)/3 = 10.


1)
{"4", "77"}
47

Returns: 10.0



2)
{"1", "1", "1", "1", "1", "1", "1"}
1000000

Returns: 3.0



3)
{"572685085149095989026478064633266980348504469", "19720257361", "9", "69"}
7

Returns: 98.3238536775161



// END CUT HERE
#line 92 "TheSwapsDivOne.cpp"

#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<climits>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<list>
#include<bitset>
#include<set>
#include<map>
#include<functional>
#include<numeric>
#include<utility>
#include<iomanip>
using namespace std;

//HEAD_OF_TEMPLATE_BY_JKI14

	//TYPEDEF
	
	typedef long long lld;
	typedef double dou;
	typedef pair<int,int> pii;

	//COMPARE
	
	inline int min(const int &x, const int &y){ return x<y?x:y; }
	inline lld min(const lld &x, const lld &y){ return x<y?x:y; }
	inline dou min(const dou &x, const dou &y){ return x<y?x:y; }

	inline int max(const int &x, const int &y){ return x>y?x:y; }
	inline lld max(const lld &x, const lld &y){ return x>y?x:y; }
	inline dou max(const dou &x, const dou &y){ return x>y?x:y; }

	template<class T> inline void _updmin(T &x,const T &y){ if(x>y)x=y; }
	template<class T> inline void _updmax(T &x,const T &y){ if(x<y)x=y; }

	//STL
	
	#define _size(x) ((int)(x.size()))
	#define _mkpr(x,y) make_pair(x,y)

	
//TAIL_OF_TEMPLATE_BY_JKI14

#define N 3100

const dou eps=1e-9;

int n;
dou a[N],sum;

int equal(const dou &x,const dou &y){ return fabs(x-y)<eps; }

class TheSwapsDivOne {
	public:
	double find(vector <string> seq, int m) {n=0;sum=0.0;
		for(int i=0;i<_size(seq);i++){
			for(int j=0;j<_size(seq[i]);j++){
				a[n++]=(dou)(seq[i][j]-'0');
				sum+=a[n-1];
			}
		}
		dou p1=1.0/((dou)n)+1.0/((dou)(n-1));
		dou p2=((dou)(n-2))/((dou)n);
		dou p0=((dou)n)*((dou)(n-1));
		for(int i=0;i<m;i++){int flag=1;
			for(int j=0;j<n;j++){
				a[j]=((sum-a[j])*p1+a[i]*p2)/p0;
				if(j && !equal(a[j],a[j-1]))flag=0;
			}
			if(flag)break;
		}
		dou s=0.0;
		for(int i=0;i<n;i++){
			s+=a[i]*((dou)(n-i))*((dou)(i+1));
		}
		return s/p0;
	}
};
