#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef long long lld;

char tmp[110];

class FoxAndMp3 {
	public:
	vector <string> playList(int n){ 
		vector <string> ans;ans.clear();
		lld num=0LL;
		for(int i=0;i<n && i<50;i++){
			string nex;
			nex.clear();
			num=num*10;
			if(!num)num=1;
			while(num>n){
				num/=10;
				while((num%10)==9){
					num/=10;
				}
				num++;
			}
			//memset(tmp,0,sizeof(tmp));
			sprintf(tmp,"%d.mp3",num);
			nex=tmp;
			ans.push_back(nex);
		}
		return ans;
	}
};

//Powered by [KawigiEdit] 2.0!
