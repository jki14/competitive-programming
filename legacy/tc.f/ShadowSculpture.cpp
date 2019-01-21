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

#define N 16
#define R 6

static const int dx[R]={ 1,-1,0,0,0,0 };
static const int dy[R]={ 0,0,1,-1,0,0 };
static const int dz[R]={ 0,0,0,0,1,-1 };

class ShadowSculpture {
public:
	string possible(vector <string> XY, vector <string> YZ, vector <string> ZX) {
		n=XY.size();
		memset(f, 0xff, sizeof(f));
		for(int x=0; x<n; x++)
			for(int y=0; y<n; y++)
				if(XY[x][y]=='N'){
					for(int z=0; z<n; z++)
						f[x][y][z]=0;
				}
		for(int y=0; y<n; y++)
			for(int z=0; z<n; z++)
				if(YZ[y][z]=='N'){
					for(int x=0; x<n; x++)
						f[x][y][z]=0;
				}
		for(int z=0; z<n; z++)
			for(int x=0; x<n; x++)
				if(ZX[z][x]=='N'){
					for(int y=0; y<n; y++)
						f[x][y][z]=0;
				}
		StableCheck();
		if(!ShadowCheck(XY, YZ, ZX))
			return "Impossible";
		else return "Possible";
	}

private:
	int f[N][N][N], n;
	set<int> total;

	int ShadowCheck(const vector<string> &XY, const vector<string> &YZ, const vector<string> &ZX){
		for(int x=0; x<n; x++)
			for(int y=0; y<n; y++)
				if(XY[x][y]=='Y'){
					set<int> sub;sub.clear();
					for(int z=0; z<n; z++){
						if(!f[x][y][z])continue;
						sub.insert(f[x][y][z]);
					}
					for(set<int>::iterator it=total.begin(); it!=total.end(); ){
						if(sub.find(*it)==sub.end()){
							set<int>::iterator dt=it; it++;
							total.erase(dt);
						}else it++;
					}
					if(total.empty())return 0;
				}
		for(int y=0; y<n; y++)
			for(int z=0; z<n; z++)
				if(YZ[y][z]=='Y'){
					set<int> sub;sub.clear();
					for(int x=0; x<n; x++){
						if(!f[x][y][z])continue;
						sub.insert(f[x][y][z]);
					}
					for(set<int>::iterator it=total.begin(); it!=total.end(); ){
						if(sub.find(*it)==sub.end()){
							set<int>::iterator dt=it; it++;
							total.erase(dt);
						}else it++;
					}
					if(total.empty())return 0;
				}
		for(int z=0; z<n; z++)
			for(int x=0; x<n; x++)
				if(ZX[z][x]=='Y'){
					set<int> sub;sub.clear();
					for(int y=0; y<n; y++){
						if(!f[x][y][z])continue;
						sub.insert(f[x][y][z]);
					}
					for(set<int>::iterator it=total.begin(); it!=total.end(); ){
						if(sub.find(*it)==sub.end()){
							set<int>::iterator dt=it; it++;
							total.erase(dt);
						}else it++;
					}
					if(total.empty())return 0;
				}
		return 1;
	}

	void dfs(const int x, const int y, const int z, const int flag){
		f[x][y][z]=flag;
		for(int i=0; i<R; i++){
			int _x=x+dx[i], _y=y+dy[i], _z=z+dz[i];
			if(_x<0 || _x>=n || _y<0 || _y>=n || _z<0 || _z>=n)continue;
			if(!~f[_x][_y][_z])
				dfs(_x, _y, _z, flag);
		}
	}

	void StableCheck(){
		int flag=0;
		total.clear();
		for(int x=0; x<n; x++)
			for(int y=0; y<n; y++)
				for(int z=0; z<n; z++)
					if(!~f[x][y][z]){
						dfs(x, y, z, ++flag);
						total.insert(flag);
					}
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] ={"YYYYY", "YYNYY", "YYYYY", "YYNYY", "YYYYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] ={"YYYYY", "YYNYY", "YYYYY", "YYNYY", "YYYYY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"YYYYY", "YYNYY", "YYYYY", "YYNYY", "YYYYY"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Possible"; verify_case(0, Arg3, possible(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"YN","NY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YN","NY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"YN","NY"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Impossible"; verify_case(1, Arg3, possible(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"YYY","YNY","YYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YYY","YNY","YYY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"YYY","YNY","YYY"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Possible"; verify_case(2, Arg3, possible(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"YYY","YNY","YYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYY","YNY","YYY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"YYY","YNY","YYN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Impossible"; verify_case(3, Arg3, possible(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"N"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"N"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"N"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Possible"; verify_case(4, Arg3, possible(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ShadowSculpture ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
