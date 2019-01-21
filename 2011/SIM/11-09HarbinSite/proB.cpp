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

#define N 100010
int seq[N], a[N], next[N], f[N];
int n;

int getmax(int x, int y) { return x > y ? x : y; }

int cmp(const int &x, const int &y)
{
	if (a[x] == a[y]) return x < y;
	return a[x] < a[y];
}

void conduct()
{
	int i;
	for (i = 0; i < n; ++i) scanf("%d", &a[i]);
	for (i = 0; i < n; ++i) seq[i] = i; sort(seq, seq+n, cmp);
	for (i = 0; i < n; ++i) next[i] = 0;
	for (i = 0; i < n-1; ++i) if (a[seq[i]] == a[seq[i+1]]) next[seq[i]] = seq[i+1];
	f[n] = 0;
	//printf("next:"); for (i = 0; i < n; ++i) printf("%d ", next[i]); printf("\n");
	for (i = n-1; i >= 0; --i) {
		f[i] = f[i+1];
		if (next[i]) f[i] = getmax(f[i], f[next[i]] + (a[i] == 999? 3 : 1));
	} printf("%d\n", f[0]);
}

int main()
{
	while (scanf("%d", &n) != EOF && n) conduct();
	return 0;
}
