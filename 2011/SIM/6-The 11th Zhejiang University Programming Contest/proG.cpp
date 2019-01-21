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

#define N 20010
#define M 110
bool pr[N];
int l[M][M], lz[M];

void init()
{
	int i, j;
	memset(pr, true, sizeof(pr)); pr[0] = pr[1] = false;
	for (i = 2; i <= 100; ++i) for (j = 2; i*j <= 100; ++j) pr[i*j] = false;
	for (i = 101; i <= 20000; ++i) {
		for (j = 1; j <= 100; ++j) if (!(i%j)) break;
		if (j <= 100) pr[i] = false;
	}
	for (lz[0] = 0, i = 1; i <= 100; ++i) if (pr[i] && (i-3) % 4 == 0) lz[i] = lz[i-1] + 1; else lz[i] = lz[i-1];
	for (i = 1; i <= 100; ++i) for (l[i][0] = 0, j = 1; j <= 100; ++j) 
		if (pr[i*i+j*j]) l[i][j] = l[i][j-1] + 1; else l[i][j] = l[i][j-1];
	//for (i = 0; i <= 10; ++i) printf("lz[%d]=%d\n", i, lz[i]);
	//for (i = 0; i <= 10; ++i) printf("pr[%d]=%d\n", i, pr[i]);
}

int getgcd(int x, int y) { if (!y) return x; else return getgcd(y, x%y); }

int main()
{
	int x1, x2, y1, y2, i, j, ans, bot, tmp, gcd;
	init();
	int time; scanf("%d", &time);
	while (time--) { 
		scanf("%d%d%d%d", &x1, &x2, &y1, &y2); 
		ans = 0; bot = (x2-x1+1) * (y2-y1+1);
		if (y1 < 0 && y1 * y2 >= 0) { tmp = y2; y2 = -y1; y1 = -tmp; }
		if (x1 < 0 && x1 * x2 >= 0) { tmp = x2; x2 = -x1; x1 = -tmp; }
		for (i = y1; i <= y2; ++i) if (i) {
			j = abs(i);
			if (x1 <= 0) ans += l[i][abs(x1)] + l[i][x2]; else ans += l[i][x2] - l[i][x1-1];
		}
		if (x1 <= 0) ans += lz[abs(x1)] + lz[x2]; else ans += lz[x2] - lz[x1-1];
		if (y1 <= 0) ans += lz[abs(y1)] + lz[y2]; else ans += lz[y2] - lz[y1-1];
		gcd = getgcd(ans, bot);
		printf("%d/%d\n", ans/gcd, bot/gcd);
	}
}
