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

struct node { int next, d, l; };
#define M 20010
#define N 10010
#define MAX LONG_MAX
int rd[N], dis[N], hp[N], ati[N];
node w[M];
bool vst[N];
int n, m, rc;

void insert(int st, int ed, int len) {
	rc++; w[rc].d = ed; w[rc].l = len; w[rc].next = rd[st]; rd[st] = rc;
}

int getele() {
	int ret, i, j, ele;
	ret = hp[1]; ele = hp[hp[0]--];
	for (i = 1, j = (i<<1); j <= hp[0]; i = j, j = (i<<1)) {
		if (j < hp[0] && dis[hp[j]] > dis[hp[j+1]]) j++;
		if (dis[hp[ele]] > dis[hp[j]]) { hp[i] = hp[j]; ati[hp[i]] = i; } else break;
	} hp[i] = ele; ati[hp[i]] = i; return ret;
}

void update(int x) {
	int i, j, ele; ele = hp[x];
	for (i = x, j = (i<<1); j <= hp[0]; i = j, j = (i<<1)) {
		if (j < hp[0] && dis[hp[j]] > dis[hp[j+1]]) j++;
		if (dis[hp[ele]] > dis[hp[j]]) { hp[i] = hp[j]; ati[hp[i]] = i; } else break;
	} hp[i] = ele; ati[hp[i]] = i;
}

int dijkstra(int x) {
	int i, u, v, len, ret;
	memset(dis, 0, sizeof(dis)); memset(vst, 0, sizeof(vst));
	for (i = 1; i <= n; ++i) hp[i] = i; hp[0] = n; hp[1] = x; hp[x] = 1;
	for (i = 1; i <= n; ++i) ati[i] = i; ati[x] = 1; ati[1] = x;
	while (hp[0]) {
		u = getele(); vst[u] = 1;
		for (i = rd[u]; i; i = w[i].next) {
			v = w[i].d; len = w[i].l;
			if (vst[v]) continue;
			if (dis[v] < dis[u]+len) { dis[v] = dis[u]+len; update(ati[v]); }
		}
	} 
	for (ret = 0, i = 1; i <= n; ++i) if (ret < dis[i]) ret = dis[i]; return ret;
}

void conduct()
{
	int i, st, ed, len, ret;
	memset(rd, 0, sizeof(rd)); rc = 0;
	for (i = 0; i < m; ++i) {
		scanf("%d%d%d", &st, &ed, &len);
		insert(st, ed, len); insert(ed, st, len);
	} ret = MAX;
	for (i = 1; i <= n; ++i) ret = min(ret, dijkstra(i));
	printf("%d\n", ret+1);
}

int main()
{
	while (scanf("%d%d", &n, &m) != EOF) conduct();
	return 0;
}
