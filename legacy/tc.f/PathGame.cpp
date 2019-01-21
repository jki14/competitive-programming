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

class PathGame {
public:
	string judge(vector <string> b) {
		int n=b[0].length();
		int *a=(int*)malloc(sizeof(int)*n);
		int ***g=(int***)malloc(sizeof(int**)*(n+1));
		for(int i=0; i<=n; i++){
			g[i]=(int**)malloc(sizeof(int*)*4);
			for(int j=0; j<4; j++)
				g[i][j]=(int*)malloc(sizeof(int*)*4);
		}

		for(int i=0;i<n;i++)
			a[i]=pass(b, n, 0, i)|(pass(b, n, 1, i)<<1);
		for(int i=0; i<=n; i++)
			for(int j=0; j<4; j++)
				for(int k=0; k<4; k++)
					g[i][j][k]=~0;
		
		int ans=0;
		for(int i=0; i<n; i++){
			if(!a[i])continue;
			int len=1;while(i+len<n && a[i+len])len++;
			ans ^= sg(len, a[i], a[i+len-1], g);
			i+=len;
		}

		free(a);
		for(int i=0; i<=n; i++){
			for(int j=0; j<4; j++)
				free(g[i][j]);
			free(g[i]);
		}
		free(g);

		return (ans>0)?"Snuke":"Sothe";
	}

private:
	int pass(const vector<string> &b, const int n, const int &x, const int &y){
		if(b[x][y]=='#')return 0;
		if(b[x^1][y]=='#')return 0;
		if(y-1>=0 && b[x^1][y-1]=='#')return 0;
		if(y+1< n && b[x^1][y+1]=='#')return 0;
		return 1;
	}

	int sg(const int &k, const int &l, const int &r, int ***g){
		if(~g[k][l][r])return g[k][l][r];
		set<int> s;
		for(int i=0; i<k; i++){
			for(int j=1; j<3; j++){
				if(i==0   && (!(l&j)))continue;
				if(i==k-1 && (!(r&j)))continue;
				int mid=j;
				int lef=(i==1  )?l&mid:l;
				int rig=(i==k-2)?r&mid:r;
				s.insert(sg(i, lef, (i==1)?lef:mid, g)^sg(k-i-1, (i==k-2)?rig:mid, rig, g));
			}
		}
		for(int key=0;;key++)
			if(s.find(key)==s.end()){
				return g[k][l][r] = key;
			}
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"."
,"."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Snuke"; verify_case(0, Arg1, judge(Arg0)); }
	void test_case_1() { string Arr0[] = {"#."
,".."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Snuke"; verify_case(1, Arg1, judge(Arg0)); }
	void test_case_2() { string Arr0[] = {"....."
,"..#.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Sothe"; verify_case(2, Arg1, judge(Arg0)); }
	void test_case_3() { string Arr0[] = {".#..."
,"....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Snuke"; verify_case(3, Arg1, judge(Arg0)); }
	void test_case_4() { string Arr0[] = {".....#..#........##......."
,"..........#..........#...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Snuke"; verify_case(4, Arg1, judge(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PathGame ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
