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

#define N 4010
int cnt[N];
bool pri[N];
int n, m;

void init()
{
	int i, j;
	memset(pri, true, sizeof(pri));
	for (i = 2; i < N; ++i) for (j = 2; i * j < N; ++j) pri[i*j] = false;
}

void conduct(int k)
{
	int i, x, y;
	if (n > m) { i = n; n = m; m = i; }
	memset(cnt, 0, sizeof(cnt));
	for (i = 2; i < N && n > 1; ++i) while (pri[i] && !(n%i)) { cnt[i]++; n /= i; }
	x = 0; y = 0;
	for (i = 2; i < N; ++i) if (pri[i]) {
		if (cnt[i] || !(m % i)) { x++; }
		while (!(m % i)) { cnt[i]--; m /= i; }
		y += abs(cnt[i]);
	}
	if (n > 1) { x++; y++;} if (m > 1) { x++; y++; }
	if (n > 1 && m > 1 && n == m) { x--; y -= 2; }
	printf("%d. %d:%d\n", k, x, y);
}

int main()
{
	int time; time = 0; init();
	while (scanf("%d%d", &n, &m) != EOF && (n || m)) conduct(++time);
	return 0;
}
