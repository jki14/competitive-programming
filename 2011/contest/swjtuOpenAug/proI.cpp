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

#define N 110
#define M 20
const double inf = 1e8;
const double eps = 1e-6;
double a[N][N], b[N], c[M][M];
int n, m, r, tot;

void input()
{
	int i, j;
	for (i = 0; i < n; ++i) for (j = 0; j < m; ++j) scanf("%lf", &c[i][j]);
}

void gauss()
{
	int i, j, k; double l;
	for (i = 0; i < tot; ++i) {
		l = -inf;
		for (j = k = i; j < tot; ++j) if (fabs(a[j][i]) > l) { l = fabs(a[j][i]); k = j; }
		for (j = i; j < tot; ++j) { l = a[i][j]; a[i][j] = a[k][j]; a[k][j] = l; }
		l = b[i]; b[i] = b[k]; b[k] = l;
		if (fabs(a[i][i]) < eps) continue;
		for (j = 0; j < tot; ++j) if (i != j) {
			l = a[j][i] / a[i][i]; a[j][i] = 0; /*printf("l:%.3f\n", l);*/
			for (k = i+1; k < tot; ++k) a[j][k] -= a[i][k] * l; b[j] -= b[i] * l;
		}
	}
	for (i = 0; i < tot; ++i) b[i] /= a[i][i];
}

void conduct(int time)
{
	int i, j, k, l, cnt;
	if (time) printf("\n");
	tot = n*m;
	for (i = 0; i < n; ++i) for (j = 0; j < m; ++j) {
		for (cnt = k = 0; k < n; ++k) for (l = 0; l < m; ++l) if (abs(i-k)+abs(j-l) <= r) {
			a[i*m+j][k*m+l] = 1.0; cnt++;
		} else a[i*m+j][k*m+l] = 0.0;
		b[i*m+j] = c[i][j] * cnt;
	}
	//for (i = 0; i < tot; ++i) { for (j = 0; j < tot; ++j) printf("%.0f ", a[i][j]); printf("\n");} printf("\n");
	//for (i = 0; i < tot; ++i) printf("%.1f ", b[i]); printf("\n");
	gauss();
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) printf("%8.2f", b[i*m+j]); printf("\n");
	}
}

int main()
{
	int time; time = 0;
	while (scanf("%d%d%d", &m, &n, &r) != EOF && (n || m || r)) {
		input(); conduct(time++);
	}
	return 0;
}
