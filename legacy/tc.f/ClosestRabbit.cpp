#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

class ClosestRabbit {
public:
	double getExpected(vector <string> board, int r) {
		int n=board.size(), m=board[0].length(), count=0;
		double ans=0.0, total=1.0;
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				if(board[i][j]=='.')count++;
		for(int i=1; i<=r; i++)
			total*=(count-r+i)*1.0/i;
		for(int x0=0; x0<n; x0++){
			for(int y0=0; y0<m; y0++){
				if(board[x0][y0]=='#')continue;
				for(int x1=0; x1<n; x1++){
					for(int y1=0; y1<m; y1++){
						if(board[x1][y1]=='#')continue;
						if(x0==x1 && y0==y1)continue;
						ans+=expect(board, r, x0, y0, x1, y1, total);
					}
				}
			}
		}
		return ans;
	}
	
private:
	int call_dist(const int x0, const int y0, const int x1, const int y1){
		return (x0-x1)*(x0-x1)+(y0-y1)*(y0-y1);
	}
	int dis_infect(const int x0, const int y0, const int x1, const int y1, const int x2, const int y2){
		int dist=call_dist(x0, y0, x1, y1);
		int dist0=call_dist(x0, y0, x2, y2);
		int dist1=call_dist(x1, y1, x2, y2);
		if(dist>dist0 || (dist==dist0 && (x2<x1 || (x2==x1 && y2<y1))))return 0;
		if(dist>dist1 || (dist==dist1 && (x2<x0 || (x2==x0 && y2<y0))))return 0;
		return 1;
	}
	double expect(const vector<string> &board, const int r, const int x0, const int y0, const int x1, const int y1, const double total){
		int n=board.size(), m=board[0].length(), count=0;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(board[i][j]=='#')continue;
				if(dis_infect(x0, y0, x1, y1, i, j)){
					count++;
				}
			}
		}
		if(count<r-2)return 0.0;
		double ret=1.0;
		for(int i=1; i<=r-2; i++)
			ret*=(count-r+2+i)*1.0/i;
		//if(r==4)printf("(%d,%d)&(%d,%d) count=%d %.0f / %.0f\n", x0, y0, x1, y1, count, ret, total);
		return ret*0.5/total;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".#.#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; double Arg2 = 1.0; verify_case(0, Arg2, getExpected(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"..###.",
 ".###.#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; double Arg2 = 1.6; verify_case(1, Arg2, getExpected(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"..###.",
 ".###.#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; double Arg2 = 2.0; verify_case(2, Arg2, getExpected(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {".....",
 "#...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; double Arg2 = 1.253968253968254; verify_case(3, Arg2, getExpected(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {".#####.#####..#....#",
 "#......#....#.##..##",
 ".####..#####..#.##.#",
 ".....#.#...#..#....#",
 "#####..#....#.#....#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; double Arg2 = 5.77311527122319; verify_case(4, Arg2, getExpected(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ClosestRabbit ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
