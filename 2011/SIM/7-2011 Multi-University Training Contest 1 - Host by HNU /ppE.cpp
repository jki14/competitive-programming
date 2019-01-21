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
#define getmin(x, y) (x)<(y)?(x):(y)
struct node { int d, l, next; };
#define N 210
const int MAX = 10010;
node w[N*N];
int dis[N][N], rd[N], heap[N], ati[N], cnt[N];
int x[N], y[N], r[N];
bool use[N];
int n, rc;

void input()
{
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) scanf("%d%d%d", &x[i], &y[i], &r[i]);
}

bool judge(int p1, int p2)
{
	if (square(x[p2]-x[p1]) + square(y[p2]-y[p1]) <= square(r[p2]+r[p1])) return true;
	return false;
}

int getele()
{
	int ret, i, j, ele;
	ret = heap[1]; ele = heap[heap[0]--];
	for (i = 1, j = (i << 1); j <= heap[0]; i = j, j = (i << 1)) {
		if (j < heap[0] && dis[heap[j]] > dis[heap[j+1]]) j++;
		if (dis[ele] > dis[heap[j]]) ati[heap[i] = heap[j]] = i; else break;
	}
	heap[i] = ele; ati[ele] = i;
	return ret;
}

void update(int idx)
{
	int ele, i, j;
	ele = heap[idx];
	for (i = idx, j = (i >> 1); j; i = j, j = (i >> 1))
		if (dis[ele] < dis[heap[j]]) ati[heap[i] = heap[j]] = i; else break;
	heap[i] = ele; ati[ele] = i;
}

void dijkstra(int* dis, int s)
{
	int i, j, k;
	memset(ati, 0, sizeof(ati));
	for (i = 1; i <= n; ++i) dis[i] = MAX; dis[s] = 0;
	for (heap[ati[s] = heap[0] = 1] = s; heap[0];)
	{
		j = getele(); ati[j] = 0;
		for (i = rd[j]; i; i = w[i].next) if (dis[w[i].d] > dis[j] + w[i].l) {
			k = w[i].d; if (!ati[k]) heap[ati[k] = ++heap[0]] = k;
			dis[k] = dis[j] + w[i].l; update(ati[k]);
		}
	}
}

void floyd()
{
	int i, j, k;
	//for (i = 1; i <= n; ++i) for (j = 1; j <= n; ++j) dis[i][j] = len[i][j];
	for (i = 1; i <= n; ++i) dis[i][i] = 0;
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= n; ++j)
			for (k = 1; k <= n; ++k) dis[j][k] = getmin(dis[j][k], dis[j][i] + dis[i][k]);
}

void conduct()
{
	int i, j, ans;
	memset(rd, 0, sizeof(rd)); rc = 0;
	for (i = 1; i <= n; ++i) for (j = i+1; j <= n; ++j) if (judge(i, j)) {
		rc++; w[rc].d = j; w[rc].l = 1; w[rc].next = rd[i]; rd[i] = rc; cnt[i]++;
		rc++; w[rc].d = i; w[rc].l = 1; w[rc].next = rd[j]; rd[j] = rc; cnt[j]++;
	}
	memset(use, true, sizeof(use));
	for (i = 1; i <= n; ++i) if (cnt[i] > 1) dijkstra(dis[i], i); else use[i] = false; ans = MAX;
	for (i = 1; i <= n; ++i) if (use[i]) ans = getmin(ans, dis[i][1] + dis[i][2] + dis[i][3]);
	if (dis[1][2] == MAX || dis[1][3] == MAX) { printf("-1\n"); return; }
	//dijkstra(dis1, pre1, 1); dijkstra(dis2, pre2, 2); dijkstra(dis3, pre3, 3);
	//for (i = 1; i <= n; ++i) printf("dis1[%d]=%d\n", i, dis1[i]);
	printf("%d\n", n-ans-1);
}

int main()
{
	int time; scanf("%d", &time);
	while (time--) { input(); conduct(); }
	return 0;
}	
