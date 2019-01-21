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

#define S 1100
#define N 24

const int inf=0x3f3f3f3f;

struct seg{
	int lef,rig;
	seg(){ lef=rig=0; }
	seg(const int &_lef, const int &_rig){
		lef=_lef;rig=_rig;
	}
	bool operator < (const seg &_op) const{
		return rig<_op.rig;
	}
};

int x,y,bit[N],c[N][N],a[N][N];
seg b[S];

int check(const int &s){
	for(int i=0;i<x;){int j=i;
		while((s&bit[j])==0 && j+1<x)j++;
		for(int p=0;p<y;p++){
			int typ=0;
			for(int q=i;q<=j;q++){
				if(typ){
					if(c[q][p] && typ!=c[q][p])return 0;
				}else if(c[q][p])typ=c[q][p];
			}
			for(int q=i;q<=j;q++)a[q][p]=typ;
			
		}
		i=j+1;
	}
	return 1;
}

int btsz(const int &s){
	int ret=0;for(int i=0;i<20;i++)if(s&bit[i])ret++;
	return ret;
}

class WolvesAndSheep{
public:

	int getmin(vector <string> _c) {
		
		for(int i=0;i<20;i++)bit[i]=1<<i;
		
		int ans=inf;
		x=_c.size();y=_c[0].length();
		for(int i=0;i<x;i++)
			for(int j=0;j<y;j++)
				c[i][j]=(_c[i][j]=='.')?0:(_c[i][j]=='W'?1:-1);
		for(int s=0;s<bit[x-1];s++){
			if(!check(s))continue;
			int num=0,cnt=0;
			for(int i=0;i<x;i++){
				int typ=a[i][0],src=0;
				for(int j=1;j<y;j++){
					if(typ){
						if(a[i][j]){
							if(a[i][j]!=typ){
								b[num++]=seg(src,j-1);
								src=j;typ=a[i][j];
							}else{
								src=j;
							}
						}
					}else if(a[i][j]){
						src=j;typ=a[i][j];
					}
				}
			}
			sort(b,b+num);int p=-1;
			for(int i=0;i<num;i++){
				if(p<b[i].lef){
					cnt++;
					p=b[i].rig;
				}
			}
			if(ans>cnt+btsz(s))ans=cnt+btsz(s);
		}
		return ans;
	}
	
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"W.WSS",
 "WW.S.",
 ".SSS.",
 "SSS.S",
 ".SS.S"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, getmin(Arg0)); }
	void test_case_1() { string Arr0[] = {".....",
 ".....",
 "....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, getmin(Arg0)); }
	void test_case_2() { string Arr0[] = {".SS",
 "...",
 "S..",
 "W.W"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, getmin(Arg0)); }
	void test_case_3() { string Arr0[] = {"WWWSWWSSWWW",
 "WWSWW.SSWWW",
 "WS.WSWWWWS."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(3, Arg1, getmin(Arg0)); }
	void test_case_4() { string Arr0[] = {".W.S.W.W",
 "W.W.S.W.",
 ".S.S.W.W",
 "S.S.S.W.",
 ".S.W.W.S",
 "S.S.W.W.",
 ".W.W.W.S",
 "W.W.S.S."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(4, Arg1, getmin(Arg0)); }
	void test_case_5() { string Arr0[] = {"W.SSWWSSSW.SS",
 ".SSSSW.SSWWWW",
 ".WWWWS.WSSWWS",
 "SS.WSS..W.WWS",
 "WSSS.SSWS.W.S",
 "WSS.WS...WWWS",
 "S.WW.S.SWWWSW",
 "WSSSS.SSW...S",
 "S.WWSW.WWSWSW",
 ".WSSS.WWSWWWS",
 "..SSSS.WWWSSS",
 "SSWSWWS.W.SSW",
 "S.WSWS..WSSS.",
 "WS....W..WSS."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; verify_case(5, Arg1, getmin(Arg0)); }
	void test_case_6() { string Arr0[] = {"WW..SS",
 "WW..SS",
 "......",
 "......",
 "SS..WW",
 "SS..WW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(6, Arg1, getmin(Arg0)); }

// END CUT HERE


};

// BEGIN CUT HERE
int main(){
	WolvesAndSheep ___test;
	___test.run_test(-1);
	return 0;
}
// END CUT HERE
