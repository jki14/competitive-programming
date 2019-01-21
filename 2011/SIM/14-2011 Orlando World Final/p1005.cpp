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

#define N 2010
int hash[N][N], g[N][N];
int n, m, wi, hi, req;

void conduct()
{
	int i, j, tw, th, edg, ret, tv, rh, rw;
	memset(hash, 0, sizeof(hash)); edg = wi+hi;
	for (i = 0; i < n; ++i) {
		scanf("%d%d", &tw, &th);
		hash[th-tw+wi][th+tw]++;
	}
	for (i = 0; i <= edg; ++i) { g[i][0] = 0; g[0][i] = 0; }
	for (i = 1; i <= edg; ++i) for (j = 1; j <= edg; ++j) g[i][j] = hash[i][j]+g[i-1][j]+g[i][j-1]-g[i-1][j-1]; 
	//for (i = edg; i >= 0; --i) { for (j = 0; j <= edg; ++j) printf("%d ", g[i][j]); printf("\n"); }
	while (req--) {
		scanf("%d", &m); m++; ret = 0;
		for (i = 1; i <= edg; ++i) for (j = 1; j <= edg; ++j) {
			if ((i+j+wi)%2) continue;
			th = (j+i-wi)/2; tw = (j-i+wi)/2;
			tv = g[i][j];
			if (i-2*m+1 >= 0) tv -= g[i-2*m+1][j];
			if (j-2*m+1 >= 0) tv -= g[i][j-2*m+1];
			if (i-2*m+1 >= 0 && j-2*m+1 >= 0) tv += g[i-2*m+1][j-2*m+1];
			if (tv > ret || (tv == ret && (th < rh || (th == rh && tw < rw)))) {
				ret = tv; rh = th; rw = tw;
			}
		} printf("%d (%d,%d)\n", ret, rw, rh-m+1);
	} 
}

int main() {
	int time = 0;
	while (scanf("%d%d%d%d", &wi, &hi, &n, &req) != EOF && wi) {
		printf("Case %d:\n", ++time);
		conduct();
	} return 0;
}
