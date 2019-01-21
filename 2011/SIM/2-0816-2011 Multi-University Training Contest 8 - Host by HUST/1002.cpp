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

const int dr[4] = { -1, 0, 1, 0 };
const int dc[4] = { 0, 1, 0, -1 };
#define N 510
bool vst[N][N], ps[N][N][4];
int n, m, st, ed;

void input()
{
	int i, j, info;
	scanf("%d%d%d%d", &n, &m, &st, &ed);
	for (i = 0; i < n; ++i) { ps[i][0][3] = false; ps[i][m-1][1] = false; }
	for (i = 0; i < m; ++i) { ps[0][i][0] = false; ps[n-1][i][2] = false; }
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m-1; ++j) {
			scanf("%d", &info); ps[i][j][1] = ps[i][j+1][3] = 1 - info;
		}
		if (i != n-1) for (j = 0; j < m; ++j) {
			scanf("%d", &info); ps[i][j][2] = ps[i+1][j][0] = 1 - info;
		}
	}
	ps[0][st][0] = true; ps[n-1][ed][2] = true;
}

void visit(int row, int col, int ori, int tr, int tc, int to)
{
	//printf("-----------------\n");
	int r, c, o, i, cnt = r * c * 3;
	r = row; c = col; o = ori;
	while (r - tr || c - tc || o - to) {
		vst[r][c] = true; 
		for (i = 1; i < 13; i += 3) if (ps[r][c][(o+i)%4]) break;
		//printf("r:%d c:%d o:%d i:%d\n", r, c, o, i);
		o = (o+i) % 4; r += dr[o]; c += dc[o];
	}
}

void conduct()
{
	int i, j;
	memset(vst, 0, sizeof(vst));
	visit(0, st, 2, n, ed, 2); visit(n-1, ed, 0, -1, st, 0);
	for (i = 0; i < n; ++i) for (j = 0; j < m; ++j) if (!vst[i][j]) { printf("NO\n"); return; }
	printf("YES\n");
}

int main() {
	int time;
	scanf("%d", &time);
	while (time--) { input(); conduct(); }
	return 0;
}
