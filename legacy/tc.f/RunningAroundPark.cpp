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
	#define _size(x) ((int)(x.size()))
	#define _mkpr(x,y) make_pair(x,y)
//TAIL_OF_TEMPLATE_BY_JKI14

class RunningAroundPark{

public:

	int numberOfLap(int N, vector <int> d){
		int ret=0, cur=0x3f3f3f3f;
		for(int i=0;i<_size(d);i++){
			if(d[i]<=cur)ret++;
			cur=d[i];
		}
		return ret;
	}

	


};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
