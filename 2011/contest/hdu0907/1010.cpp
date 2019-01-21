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

#define getmax(x, y) (x)>(y)?(x):(y)
struct node { int d, next; };
#define N 100010
#define M 500010
int stp[N], seq[M], pos[M];
long long clk[M], len[M], ans[M];
int n, m, req;

void input()
{
	int i;
	scanf("%d%d%d", &n, &m, &req);
	for (i = 1; i <= m; ++i) scanf("%d%lld%lld", &pos[i], &clk[i], &len[i]);
}

int cmp(const int &x, const int &y) { return clk[x] > clk[y]; }

void conduct()
{
	int i, j, k, idx, maxk;
	long long tmp;
	for (i = 1; i <= m; ++i) seq[i] = i; sort(seq+1, seq+m+1, cmp);
	for (i = 1; i <= n; ++i) stp[i] = 0; for (i = 0; i <= m; ++i) ans[i] = 0;
	for (i = 1; i <= m; ++i) ans[++stp[pos[seq[i]]]] += len[seq[i]];
	for (maxk = 0, i = 1; i <= n; ++i) maxk = getmax(maxk, stp[i]);
	for (i = 2; i <= maxk; ++i) ans[i] += ans[i-1];
	while (req--) { scanf("%d", &idx); if (idx <= maxk) printf("%I64d\n", ans[idx]); else printf("%I64d\n", ans[maxk]); }
}

int main()
{
	int time; scanf("%d", &time);
	for (int i = 1; i <= time; ++i) { 
		printf("Case #%d:\n", i);
		input(); conduct(); 
	}
	return 0;
}
