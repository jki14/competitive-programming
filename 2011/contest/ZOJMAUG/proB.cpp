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

#define getmin(x, y) (x)<(y)?(x):(y)
#define N 60
char str[N][N];
int seq[N];
int n, m, ans;

void conduct()
{
	int i, j, k, l, tmp1, tmp2;
	for (i = 0; i < m; ++i) gets(str[i]);
	//for (i = 0; i < m; ++i) printf("%s\n", str[i]);
	for (i = 1, seq[k = 0] = 0; i < m; ++i) {
		for (j = k+1; j > 0; --j) if (strcmp(str[i], str[seq[j-1]]) >= 0) { seq[j] = i; break; }
		if (j == 0) seq[0] = i; if (j == k+1) ++k;
	} ans += m-k-1;
}

int main()
{
	while (scanf("%d%d", &n, &m) != EOF) {
		ans = 0; gets(str[0]);
		while (n--) conduct();
		printf("%d\n", ans);
	}
	return 0;
}
