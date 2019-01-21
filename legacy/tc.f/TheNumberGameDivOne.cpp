// BEGIN CUT HERE
// PROBLEM STATEMENT
// John and Brus play a game with a number.
The game starts with a positive integer n.
The two players take alternating turns, John starts.
Each move looks as follows:
Let C be the current value of the integer.
The current player has to choose a positive divisor of the number C, other than 1 and C.
Once he chooses the divisor, he has to subtract it from C.
The result is the new number with which the other player now starts his move.
If a player cannot make a valid move, he loses the game.


For example, if they start with n=15, one possible gameplay can look as follows:

John takes the number 15, chooses its divisor 3, and decreases the number to 15-3 = 12.
Brus takes the number 12, chooses its divisor 4, and decreases the number to 12-4 = 8.
John takes the number 8, chooses its divisor 2, and decreases the number to 8-2 = 6.
Brus takes the number 6, chooses its divisor 3, and decreases the number to 6-3 = 3.
John takes the number 3, and as there are no divisors other than 1 and 3, he has no valid move and thus he loses the game.



You are given the long long n.
Assume that both players use the optimal strategy while playing the game.
Return "John" (quotes for clarity) if John wins the game and "Brus" otherwise.


DEFINITION
Class:TheNumberGameDivOne
Method:find
Parameters:long long
Returns:string
Method signature:string find(long long n)


CONSTRAINTS
-n will be between 1 and 10^18, inclusive.


EXAMPLES

0)
6

Returns: "John"

John has two possible moves: either decrease 6 by 2 or decrease 6 by 3.
If he chooses the second option, Brus will have no possible moves, hence John will win the game.

1)
2

Returns: "Brus"



2)
747

Returns: "Brus"



3)
128

Returns: "Brus"



// END CUT HERE
#line 74 "TheNumberGameDivOne.cpp"

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

//TAIL_OF_TEMPLATE_BY_JKI14


class TheNumberGameDivOne {
	public:
	string find(lld n) {
		int k=0;
		while(n&1){ n>>=1;k++; }
		if(!k || ((k&1) && n==1LL))
			return "Brus";
		else return "John";
	}
};
