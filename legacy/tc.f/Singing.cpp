#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
using namespace std;

#define min(x,y) (((x)<(y))?(x):(y))

#define N 3000
#define M 1100000

const int inf=0x3fffffff;
const int S=0;
const int T=2900;

int n,m;
int ec[M],ef[M],eu[M],ev[M],be[M],nxt[M],num;
int nbs[N],cur[N],dis[N],q[N];

void AddEdge(const int &u,const int &v,const int &cc){
	nxt[++num]=nbs[u];nbs[u]=num;be[num]=num+1;
	eu[num]=u;ev[num]=v;ec[num]=cc;ef[num]=0;
	nxt[++num]=nbs[v];nbs[v]=num;be[num]=num-1;
	eu[num]=v;ev[num]=u;ec[num]=0;ef[num]=0;
}

int bfs(const int &s,const int &t){
	int head,tail,u,v,i;
	head=tail=0;q[tail++]=s;
	memset(dis,0,sizeof(dis));dis[s]=1;
	while(head<tail)
		for(u=q[head++],i=nbs[u];i;i=nxt[i]){v=ev[i];
			if(ec[i]-ef[i]>0 && !dis[v]){
				dis[v]=dis[u]+1;q[tail++]=v;
				if(v==t)return 1;
			}
		}
	return 0;
}

int Dinic(const int &s,const int &t){
	int flow=0,tmp,i,u,tail;
	while(bfs(s,t)){
		u=s,tail=0;memcpy(cur,nbs,sizeof(nbs));
		while(cur[s]){
			if(u!=t && cur[u] && ec[cur[u]]-ef[cur[u]]>0
				&& dis[u] && dis[u]+1==dis[ev[cur[u]]]){
				q[tail++]=cur[u];u=ev[cur[u]];
			}else if(u==t){
				for(tmp=inf,i=tail-1;i>=0;i--)tmp=min(tmp,ec[q[i]]-ef[q[i]]);
				for(flow+=tmp,i=tail-1;i>=0;i--){
					ef[q[i]]+=tmp;
					ef[be[q[i]]]-=tmp;
					if(!(ec[q[i]]-ef[q[i]]))tail=i;
				}
				u=eu[q[tail]];
			}else{
				while(tail>0 && u!=s && !cur[u])u=eu[q[--tail]];
				cur[u]=nxt[cur[u]];
			}
		}
	}
	return flow;
}

class Singing {
	public:
	int solve(int arg_n, int low, int hig, vector <int> pitch){
		n=arg_n; m=pitch.size();
		memset(nbs, 0, sizeof(nbs)); num=0;
		for(int i=1; i<low; i++)AddEdge(S, i, inf);
		for(int i=n; i>hig; i--)AddEdge(i, T, inf);
		for(int i=1; i<m; i++){
			if(pitch[i-1]!=pitch[i]){
				int u=pitch[i-1], v=pitch[i];
				//if(u>v)swap(u, v);
				AddEdge(u, v, 1);
				AddEdge(v, u, 1);
			}
		}
		return Dinic(S, T);
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 2; int Arr3[] = {1,2,3,2,1,2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; verify_case(0, Arg4, solve(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 3; int Arg2 = 7; int Arr3[] = {4,4,5,5,6,5,3,6}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 0; verify_case(1, Arg4, solve(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 2; int Arg2 = 5; int Arr3[] = {5,3,1,6,4,2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; verify_case(2, Arg4, solve(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 4; int Arg2 = 5; int Arr3[] = {1,4,3,5,2,5,7,5,9}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 3; verify_case(3, Arg4, solve(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 100; int Arg1 = 20; int Arg2 = 80; int Arr3[] = {2,27,3,53,53,52,52,60,85,89,100,53,60,2,3,53,100,89,40,42,2,53,2,85}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 5; verify_case(4, Arg4, solve(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE 
int main() {
	Singing __test;
	__test.run_test(-1);
}
// END CUT HERE
