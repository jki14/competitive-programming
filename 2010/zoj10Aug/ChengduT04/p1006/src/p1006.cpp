#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
#include <map>
using namespace std;

const int MAXN = 55;
const int MAXL = MAXN * MAXN;
struct Point {
	int x, y;
}house[MAXN];
int N, M, num, U[MAXL], D[MAXL], L[MAXL], R[MAXL], head, S[MAXN], col[MAXL], cnt;
double d[MAXN][MAXN], dl[MAXL];
double dist (Point a, Point b) {
	return sqrt((double)(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void init (int c) {
	memset(S, 0, sizeof(S));
	for (int i = 0; i <= c; ++i) {
		U[i] = D[i] = i;
		L[i] = i - 1;
		R[i] = i + 1;
		col[i] = i;
	}
	head = 0;
	L[0] = c;
	R[c] = 0;
	cnt = c + 1;
}
void build (double rd) {
	int lid, rid;
	for (int i = 1; i <= N; ++i) {
		lid = rid = cnt;
		for (int j = 1; j <= N; ++j) {
			if (d[i][j] <= rd) {
				U[cnt] = U[j];
				D[cnt] = j;
				L[cnt] = rid;
				R[cnt] = lid;
				D[U[j]] = cnt;
				U[j] = cnt;
				L[lid] = cnt;
				R[rid] = cnt;
				col[cnt] = j;
				S[j]++;
				rid = cnt++;
			}
		}
	}
}
void remove (int id) {
	for (int i = D[id]; i != id; i = D[i]) {
		R[L[i]] = R[i];
		L[R[i]] = L[i];
		S[col[i]]--;
	}
}
void resume (int id) {
	for (int i = U[id]; i != id; i = U[i]) {
		R[L[i]] = i;
		L[R[i]] = i;
		S[col[i]]++;
	}
}
bool hash[MAXN];
int price () {
	int ret = 0;
	memset(hash, 0, sizeof(hash));
	for (int i = R[head]; i != head; i = R[i]) if (!hash[col[i]]) {
		ret++;
		hash[col[i]] = 1;
		for (int j = D[i]; j != i; j = D[j]) {
			for (int k = R[j]; k != j; k = R[k]) {
				hash[col[k]] = 1;
			}
		}
	}
	return ret;
}
bool dfs (int step) {
	if (step + price() > M) return false;
	if (R[head] == head) return true;
	int max = MAXN, id;
	for (int i = R[head]; i != head; i = R[i]) {
		if (S[i] < max) {
			max = S[i];
			id = i;
		}
	}
	for (int i = D[id]; i != id; i = D[i]) {
		remove(i);
		for (int j = R[i]; j != i; j = R[j]) {
			remove(j);
		}
		if (dfs(step + 1)) {
			return true;
		}
		for (int j = L[i]; j != i; j = L[j]) {
			resume(j);
		}
		resume(i);
	}
	return false;
}
void solve () {
	int mid, low, hight;
	low = 0;
	hight = num - 1;
	while (low < hight) {
		mid = (low + hight) >> 1;
		init(N);
		build(dl[mid]);
		if (dfs(0)) {
			hight = mid;
		}
		else {
			low = mid + 1;
		}
	}
	printf("%.6lf\n", dl[low]);
}
int main () {
	int kase;
	scanf("%d", &kase);
	while (kase--) {
		scanf("%d%d", &N, &M);
		for (int i = 1; i <= N; ++i) {
			scanf("%d%d", &house[i].x, &house[i].y);
		}
		num = 0;
		for (int i = 1; i <= N; ++i) {
			for (int j = i; j <= N; ++j) {
				d[i][j] = d[j][i] = dl[num++] = dist(house[i], house[j]);
			}
		}
		sort(dl, dl + num);
		num = unique_copy(dl, dl + num, dl) - dl;
		solve();
	}
	return 0;
}
