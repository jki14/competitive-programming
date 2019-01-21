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
	long long x, y;
	bool operator<(const pnt &p) const {
		if (x == p.x) return y < p.y;
		return x < p.x;
	}
};
#define square(x) (x)*(x)
#define N 100010
const long long MAX = 1000000000000000LL;
pnt p[N], q[N];
int seq[N], que[N];
long long ans;
int n, ai, aj, ak, al;

long long dis2(const pnt &p1, const pnt &p2) { return square(p2.x-p1.x)+square(p2.y-p1.y); }

int cmp(const int &i, const int &j) {
	if (p[i].y == p[j].y) return p[i].x < p[j].x;
	return p[i].y < p[j].y;
}
int cmp2(const int &i, const int &j) {
	if (p[i].x == p[j].x) return p[i].y < p[j].y;
	return p[i].x < p[j].x;
}

void lstpair(int lft, int rit) {
	int mid, cnt, i, j; long long tl;
	mid = (lft + rit) / 2; if (lft >= rit) return;
	lstpair(lft, mid); lstpair(mid+1, rit);
	for (cnt = 0, i = lft; i <= rit; ++i) if (square(p[que[i]].x-p[que[mid]].x) <= ans) seq[cnt++] = que[i];
	sort(seq, seq+cnt, cmp);
	for (i = 0; i < cnt; ++i) for (j = i+1; j < i+7 && j < cnt; ++j)
		if ((tl = dis2(p[seq[i]], p[seq[j]])) < ans) {
			ans = tl; ai = seq[i]; aj = seq[j];
		}
}

int code(int id) {
	int ret = 0; if (q[id].x < 0) ret += 1;
	if (q[id].y < 0) ret += 2; return ret;
}

void conduct()
{
	int i;
	for (i = 0; i < n; ++i) scanf("%I64d%I64d", &q[i].x, &q[i].y);
	for (i = 0; i < n; ++i) { p[i].x = llabs(q[i].x); p[i].y = llabs(q[i].y); }
	for (i = 0; i < n; ++i) que[i] = i; sort(que, que+n, cmp2); 
	ans = MAX; lstpair(0, n-1);
	//printf("ans:%lld ai:%d aj:%d\n", ans, ai, aj);
	ak = code(ai); al = code(aj); al = 3-al;
	printf("%d %d %d %d\n", ai+1, ak+1, aj+1, al+1);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	while (scanf("%d", &n) != EOF) conduct();
	fclose(stdin); fclose(stdout);
	return 0;
}
