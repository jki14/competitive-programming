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
#include<deque>
#include<set>
#include<map>
using namespace std;

#define square(x) (x)*(x)
struct pnt { long long x, y; };
#define N 500010
const double eps = 1e-6;
pnt p[N], q[N*2], cen;
int seq[2*N], rt[N], stk[N];
bool col[N];
int n;
long long wid, r;

map<long long, int> st;

void input()
{
	int i;
	for (i = 0; i < n; ++i) scanf("%lld%lld", &p[i].x, &p[i].y);
	scanf("%lld%lld", &cen.x, &cen.y); cen.x *= 2; cen.y *= 2; r *= 2;
	for (i = 0; i < n; ++i) { p[i].x *= 2; p[i].y *= 2; }
}

int root(int x) { 
	int i;
	if (rt[x] == x) return x;
	stk[stk[0] = 1] = x;
	while (rt[x] != x) { x = rt[x]; stk[++stk[0]] = x; }
	for (i = 1; i <= stk[0]; ++i) rt[stk[i]] = x; return x;
}

int cmp(const int &x, const int &y) { 
	if (q[x].x < q[y].x || (q[x].x == q[y].x && x % 2 == 0)) return 1; else return 0;
}

double getdis(const pnt &p1, const pnt &p2) { return sqrt(square(p2.x-p1.x) + square(p2.y-p1.y)); }

void conduct()
{
	int i, ans;
	map<long long, int>::iterator pos, lft, rit;
	st.clear();
	for (i = 0; i < n; ++i) { q[i*2] = q[i*2+1] = p[i]; q[i*2].x = p[i].x; q[i*2+1].x = p[i].x + wid; }
	//for (i = 0; i < 2*n; ++i) printf("q[%d]:%.3f %.3f\n", i, q[i].x, q[i].y);
	for (i = 0; i < 2*n; ++i) seq[i] = i; sort(seq, seq+2*n, cmp);
	for (i = 0; i < n; ++i) rt[i] = i;
	for (i = 0; i < 2*n; ++i) 
		if (seq[i]%2) {
			//printf("%.3f %.3f\n", p[seq[i]/2].x, p[seq[i]/2].y);
			pos = st.find(p[seq[i]/2].y); 
			if (pos != st.end() && pos->second == seq[i]/2) st.erase(pos);
		} else {
			//printf("%.3f %.3f\n", p[seq[i]/2].x, p[seq[i]/2].y);
			if ((pos = st.find(p[seq[i]/2].y)) != st.end()) {
				if (root(seq[i]/2) != root(pos->second)) rt[rt[pos->second]] = rt[seq[i]/2];
				pos->second = seq[i]/2;
			}
			else { st.insert(pair<long long, int>(p[seq[i]/2].y, seq[i]/2)).second; pos = st.find(p[seq[i]/2].y); }
			lft = pos; rit = pos; if (lft != st.begin()) lft--; rit++;
			if (pos != st.begin() && fabs(pos->first - lft->first) <= wid) 
				if (root(pos->second) != root(lft->second)) rt[rt[lft->second]] = rt[pos->second]; else;
			if (rit != st.end() && fabs(pos->first - rit->first) <= wid) 
				if (root(pos->second) != root(rit->second)) rt[rt[rit->second]] = rt[pos->second]; else;
			//for (pos = st.begin(); pos != st.end(); ++pos) printf("[%d][%.3f] ", pos->second, pos->first); 
			//printf("\n");
		}
	//for (i = 0; i < n; ++i) printf("rt[%d]=%d\n", i, root(i));
	memset(col, false, sizeof(col));
	for (i = 0; i < n; ++i) if (square(r) - square(p[i].x-cen.x) >= square(p[i].y-cen.y)) col[root(i)] = true;
	for (i = ans = 0; i < n; ++i) if (col[root(i)]) ans++;
	printf("%d\n", ans);
}

int main()
{
	while (scanf("%d%lld%lld", &n, &r, &wid) != EOF) {
		input();
		conduct();
	} return 0;
}
