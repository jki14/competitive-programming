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

#define N 1010
#define M 1000010
int v[N][N], h[M], seq[N], pre[N];
int n, m, ans;

void divide(int *seq, int n)
{
	int i, j;
	pre[0] = seq[0];
	for (i = 1; i < n; ++i) pre[i] = pre[i-1] + seq[i];
	for (i = 0; i < n-2 && pre[i] < M; ++i) if (h[pre[i]]) {
		h[pre[i]]--;
		for (j = i+1; j < n-1 && pre[j]-pre[i] < M; ++j) if (h[pre[j]-pre[i]]) {
			h[pre[j]-pre[i]]--;
			if (h[pre[n-1]-pre[j]]) ans++;
			h[pre[j]-pre[i]]++;
		} h[pre[i]]++;
	}
}

void conduct()
{
	int i, j, a, b, c;
	for (i = 0; i < n; ++i) for (j = 0; j < m; ++j) scanf("%d", &v[i][j]);
	scanf("%d%d%d", &a, &b, &c); memset(h, 0, sizeof(h));
	h[a]++; h[b]++; h[c]++; ans = 0;
	for (i = 0; i < n; ++i) { seq[i] = 0; for (j = 0; j < m; ++j) seq[i] += v[i][j]; }
	divide(seq, n);
	for (i = 0; i < m; ++i) { seq[i] = 0; for (j = 0; j < n; ++j) seq[i] += v[j][i]; }
	divide(seq, m);
	printf("%d\n", ans);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	while (scanf("%d%d", &n, &m) != EOF) conduct();
	fclose(stdin); fclose(stdout);
	return 0;
}
