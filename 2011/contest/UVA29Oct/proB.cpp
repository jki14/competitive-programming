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

struct pnt {
	int x, y, tp;
	bool operator<(const pnt &p) const {
		if (x == p.x) if (y == p.y) return tp < p.tp;
			      else return y < p.y;
		else return x < p.x;
	}
};
#define N 50010
int x[N], y[N];
int n, m, tot;
const int dx[6][4] = {{  0, 1, 0, -1 },
		       { 0, 2, 3, 1  },
		       { 0, 2, 4, 2  },
		       { 0, 1, 3, 2  },
		       { 0, 1, -1, -2},
		       { 0, 2, 1, -1 }};
const int dy[6][4] = {{ 0, -2, -4, -2 },
		      { 0, -1, -3, -2 },
		      { 0,  1,  0, -1 },
		      { 0,  2,  3,  1 },
		      { 0, -2, -3, -1 },
		      { 0, -1, -3, -2 }};
map<pnt, int> hsh;

bool valid(int tx, int ty) {
	if (tx <= 0 || tx > m) return false;
	if (ty <= 0 || ty > n) return false;
	return true;
}

bool judge(int tx, int ty, int tp, int pos) {
	int i; tx -= dx[tp][pos]; ty -= dy[tp][pos];
	for (i = 0; i < 4; ++i) if (!valid(tx+dx[tp][i], ty+dy[tp][i])) break;
	if (i == 4) return true; return false;
}

pnt trans(int tx, int ty, int tp, int pos) {
	pnt ret = { tx - dx[tp][pos], ty - dy[tp][pos], tp };
	return ret;
}

void conduct()
{
	int cnt, i, j, k, upj, dnj;
	pnt pos; long long ans;
	map<pnt, int>::iterator cur;
	scanf("%d%d%d", &n, &m, &tot);
	for (i = 0; i < tot; ++i) scanf("%d%d", &x[i], &y[i]);
	hsh.clear(); cnt = 0;
	for (i = 1; i <= n; ++i) {
		if (i <= 4 || i >= n-3) {
			for (j = 1; j <= m; ++j) for (k = 0; k < 6; ++k) if (!judge(i, j, k, 0)) {
				pos = (pnt){ i, j, k };
				cnt++; hsh.insert(pair<pnt, int>(pos, 1));
			}
		} else {
			upj = min(4, m); dnj = max(m-3, 5);
			for (j = 1; j <= upj; ++j) for (k = 0; k < 6; ++k) if (!judge(i, j, k, 0)) {
				pos = (pnt){ i, j, k };
				cnt++; hsh.insert(pair<pnt, int>(pos, 1));
			} for (j = dnj; j <= m; ++j) for (k = 0; k < 6; ++k) if (!judge(i, j, k, 0)) {
				pos = (pnt){ i, j, k };
				cnt++; hsh.insert(pair<pnt, int>(pos, 1));
			}
		}
	} for (i = 0; i < tot; ++i) for (j = 0; j < 6; ++j) for (k = 0; k < 4; ++k) {
		pos = trans(x[i], y[i], j, k);
		if (valid(pos.x, pos.y) && hsh.find(pos) == hsh.end()) {
			cnt++; hsh.insert(pair<pnt, int>(pos, 1));
		}
	} ans = (long long)n * (long long)m * 6LL - (long long)cnt;
	ans = ans * 8; printf("%lld\n", ans);
}

int main()
{ 
	int time; scanf("%d", &time);
	for (int i = 1; i <= time; ++i) {
		printf("Case %d: ", i);
		conduct();
	} return 0;
}
