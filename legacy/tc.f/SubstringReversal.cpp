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

#define L 3100

int x,y,n;
char a[L];

string bst,now;

class SubstringReversal{

public:

	vector <int> solve(string S){
		n=S.length();for(int i=0;i<n;i++)a[i]=S[i];

		for(y=-1,x=0;x<n;x++){int flag=0;
			for(int z=x+1;z<n;z++){
				if(a[z]<a[x]){flag=1;
					bst.clear();y=x;
					for(int i=x;i<n;i++)bst.push_back(a[i]);
					
					for(int i=x+1;i<n;i++){
						now.clear();
						for(int k=i;k>=x;k--)now.push_back(a[k]);
						for(int k=i+1;k<n;k++)now.push_back(a[k]);
						if(now<bst){
							bst=now;y=i;
						}
					}
				}
				if(flag)break;
			}
			if(flag)break;
		}
		
		if(y<0)x=y=0;
		vector<int> ret;ret.clear();
		ret.push_back(x);ret.push_back(y);
		return ret;
	}

	


};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
