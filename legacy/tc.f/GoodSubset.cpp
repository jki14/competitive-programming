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
	
#define _size(x) ((int)(x.size()))
#define _mkpr(x,y) make_pair(x,y)

const int mod = 1000000007;

class GoodSubset{

public:

	void mapush(map<int, int> &s, const int x, const int y){
		map<int, int>::iterator it = s.find(x);
		if(it!=s.end()){
			it->second=(it->second+y)%mod;
		}else s.insert(_mkpr(x,y));
	}

	int numberOfSubsets(int goodValue, vector <int> d){
		map<int, int> f,g;f.clear();
		f.insert(_mkpr(goodValue, 1));
		for(int i=0;i<_size(d);i++){
			int key=d[i];g.clear();
			for(map<int, int>::iterator it=f.begin();it!=f.end();it++){
				if((it->first%key)!=0)continue;
				mapush(g, it->first/key, it->second);
			}
			for(map<int, int>::iterator it=g.begin();it!=g.end();it++){
				mapush(f, it->first, it->second);
			}
		}
		map<int, int>::iterator it=f.find(1);
		int ret=0;
		if(it!=f.end())ret=it->second-(goodValue==1?1:0);
		return (ret%mod+mod)%mod;
	}

	


};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
