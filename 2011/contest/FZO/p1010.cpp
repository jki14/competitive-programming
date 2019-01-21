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
int t[N], d[N], seq[N];
int n;

int cmp(const int &x, const int &y) { return t[x] > t[y]; }

void conduct()
{
	int t1, t2, i;
	scanf("%d", &n); for (i = 0; i < n; ++i) scanf("%d %d", &d[i], &t[i]);
	for (i = 0; i < n; ++i) seq[i] = i; sort(seq, seq+n, cmp);
	for (t1 = t2 = i = 0; i < n; ++i) {
		t1 = max(t1, t2 + d[seq[i]] + t[seq[i]]);
		t2 += d[seq[i]];
	} printf("%d\n", t1);
}

int main()
{
	int time, i; scanf("%d", &time);
	for (i = 1; i <= time; ++i) {
		printf("Case %d: ", i); conduct();
	} return 0;
}
