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

#define N 2333
#define M 5666
#define K 5

int n, m, h, c;
int nbs[N], dst[M], nxt[M], enm;
int mrk[N], cut[M], d[N];
int route[N], msk, sum;
int que[N], til, way[N];
int num_c[K], idx_c[K][N];

inline int opn_w(const int x){ return (x&1)?(x+1):(x-1); }

inline void addedge(const int u, const int v){
	//printf("add %d<->%d\n", u, v);
	nxt[++enm]=nbs[u];nbs[u]=enm;dst[enm]=v;
	nxt[++enm]=nbs[v];nbs[v]=enm;dst[enm]=u;
}

int dfs(const int u, const int d){
	int chd[2], len=0;sum++;
	for(int i=nbs[u]; i; i=nxt[i]){
		if(cut[i] || i==opn_w(route[u]))continue;
		const int v=dst[i];
		if(mrk[v]==msk)return 0;
		mrk[v]=msk;
		route[v]=i;
		if(len==2)return 0;
		chd[len++]=v;
	}
	if(d==h && len>0)return 0;
	if(d<h && len!=2)return 0;
	for(int i=0; i<len; i++)if(!dfs(chd[i], d+1))return 0;
	return 1;
}

int check(){
	memset(d, 0, sizeof(d));
	for(int i=1; i<=enm; i++){
		if(cut[i])continue;
		d[dst[i]]++;
	}
	int rut=-1;for(int i=0; i<n; i++){
		if(d[i]==2 && rut>=0)return 0;
		if(d[i]==2)rut=i;
	}
	if(rut<0)return 0;
	route[rut]=0x3fffffff;
	msk++;
	sum=0;
	return dfs(rut, 1) && sum==n;
}

int catch_c(const int u, const int index){
	que[++til]=u;way[til]=route[u];
	//printf("que[%d]=%d\n", til, que[til]);
	for(int i=nbs[u]; i; i=nxt[i]){
		if(cut[i] || i==opn_w(route[u]))continue;
		const int v=dst[i];
		if(mrk[v]==msk){
			num_c[index]=0;
			idx_c[index][num_c[index]++]=i;
			//printf("til=%d\n", til);
			while(1){
				if(que[til]==v)break;
				/*if(way[til]>=0x3fffffff){
					printf("u=%d v=%d til=%d que[til]=%d msk=%d\n", u, v, til, que[til], msk);
				}*/
				idx_c[index][num_c[index]++]=way[til--];
			}
			return 1;
		}else{
			mrk[v]=msk;
			route[v]=i;
			if(catch_c(v, index))return 1;
		}
	}
	mrk[que[til]]=0xfffffff;
	til--;
	return 0;
}

int find_c(const int cuted){
	if(cuted==c){
		//printf("GOAL!!\n");
		return check();
	}
	til=0;
	route[0]=0x3fffffff;
	msk++;
	if(!catch_c(0, cuted)){
		//printf("Damm!!\n");
		return 0;
	}
	//if(num_c[cuted]>21)return 0;
	//printf("cuted=%d:\n", cuted);
	/*for(int i=0; i<num_c[cuted]; i++){
		printf(" %d", idx_c[cuted][i]);
	}*/
	//printf("\n");
	for(int i=0; i<num_c[cuted]; i++){
		int x=idx_c[cuted][i];
		int y=opn_w(x);
		cut[x]++;cut[y]++;
		//printf("cut %d\n", x);
		if(find_c(cuted+1))return 1;
		cut[x]--;cut[y]--;
	}
	return 0;
}

class TheKingsRoadsDiv1 {
	public:
	string getAnswer(int _h, vector <int> a, vector <int> b) {
		h=_h;n=(1<<h)-1;c=3;
		memset(nbs, 0, sizeof(nbs));enm=0;
		m=a.size();
		for(int i=0; i<m; i++){
			if(a[i]==b[i]){
				c--;
				continue;
			}
			addedge(a[i]-1, b[i]-1);
		}
		memset(cut, 0, sizeof(cut));
		memset(mrk, 0xff, sizeof(mrk));msk=0xffffffff;
		memset(route, 0, sizeof(route));
		return find_c(0)?"Correct":"Incorrect";
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {1, 3, 2, 2, 3, 7, 1, 5, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {6, 5, 4, 7, 4, 3, 3, 1, 7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Correct"; verify_case(0, Arg3, getAnswer(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; int Arr1[] = {1, 2, 1, 3, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 1, 2, 3, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Incorrect"; verify_case(1, Arg3, getAnswer(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arr1[] = {1, 3, 2, 2, 6, 6, 4, 4, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 1, 4, 5, 4, 4, 7, 7, 6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Incorrect"; verify_case(2, Arg3, getAnswer(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 2; int Arr1[] = {1, 2, 2, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 2, 1, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Incorrect"; verify_case(3, Arg3, getAnswer(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 5; int Arr1[] = {6, 15, 29, 28, 7, 13, 13, 23, 28, 13, 30, 27, 14, 4, 14, 19, 27, 20, 20, 19, 10, 15, 7, 7, 19, 29, 4, 24, 10, 23, 30, 6, 24}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {9, 22, 30, 20, 26, 25, 8, 7, 24, 21, 27, 31, 4, 28, 29, 6, 16, 1, 17, 10, 3, 12, 30, 18, 14, 23, 19, 21, 5, 13, 15, 2, 11}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Correct"; verify_case(4, Arg3, getAnswer(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 2; int Arr1[] = {1,1,1,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,1,2,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Correct"; verify_case(5, Arg3, getAnswer(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arg0 = 5; int Arr1[] = {17, 8, 31, 23, 30, 15, 15, 18, 29, 7, 7, 3, 1, 11, 5, 19, 20, 31, 5, 3, 20, 23, 30, 18, 4, 2, 1, 2, 8, 4, 13, 17, 19}; vector<int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {30, 19, 12, 9, 16, 10, 6, 26, 2, 20, 17, 7, 13, 8, 28, 21, 1, 29, 22, 4, 15, 14, 25, 27, 8, 18, 11, 5, 31, 2, 20, 23, 24}; vector<int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Correct"; verify_case(6, Arg3, getAnswer(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	TheKingsRoadsDiv1 ___test;

	___test.run_test(-1);

}

// END CUT HERE
