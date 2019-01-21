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
int p[N][N];
char str[N];
int n, m;
const int dr[4] = { 0, 1, 0, -1 };
const int dc[4] = { 1, 0, -1, 0 };

bool valid(int tr, int tc, int col, int row) {
	if (tr < 0 || tr >= row) return false;
	if (tc < 0 || tc >= col) return false;
	if (p[tr][tc] >= 0) return false; return true;
}

bool check(int col, int row) {
	for (int i = 0; i < row-1; ++i) if (str[p[i][col]] != str[p[i+1][col]]) return false;
	return true;
}

bool judge(int col, int row) {
	int tr, tc, ori, i, j;
	memset(p, 0xff, sizeof(p));
	for (tr = tc = ori = i = 0; i < n; ++i) {
		p[tr][tc] = i;
		if (!valid(tr+dr[ori], tc+dc[ori], col, row)) ori = (ori+1)%4;
		tr += dr[ori]; tc += dc[ori];
	} for (i = 0; i < col; ++i) if (!check(i, row)) break;
	if (i == col) return true; else return false;
}

void conduct()
{
	int i;
	scanf("%s", str); n = strlen(str);
	for (m = 0; m < n; ++m) if (m*m > n) break; m--;
	for (i = m; i > 1; --i) if (!(n%i) && (judge(i, n/i) || judge(n/i, i))) break;
	if (i > 1) printf("%d\n", i+n/i); else printf("-1\n");
}

int main()
{
	int time; scanf("%d", &time);
	for (int i = 1; i <= time; ++i) {
		printf("Case %d: ", i);
		conduct();
	} return 0;
}
