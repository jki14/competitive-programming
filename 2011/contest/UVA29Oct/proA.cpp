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

#define N 30
int seq[N];
char str[N], ans[N];
long long base[N];
int n; long long m;

void init()
{
	base[0] = base[1] = 1;
	for (long long i = 2LL; i <= 20LL; ++i) base[i] = base[i-1]*i;
}

void conduct()
{
	int i, j, k;
	scanf("%s%lld", str, &m); m--; n = strlen(str);
	for (i = 0; i < n; ++i) seq[i] = i;
	for (i = 0; i < n; ++i) {
		for (k = 0; m >= base[n-i-1]; ++k) m = m - base[n-i-1];
		for (j = i+k, k = seq[i+k]; j > i; --j) seq[j] = seq[j-1]; seq[i] = k;
	} for (i = 0; i < n; ++i) ans[seq[i]] = str[i]; ans[n] = '\0';
	printf("%s\n", ans);
}

int main()
{
	init(); int time; scanf("%d", &time);
	for (int i = 1; i <= time; ++i) {
		printf("Case %d: ", i);
		conduct();
	} return 0;
}
