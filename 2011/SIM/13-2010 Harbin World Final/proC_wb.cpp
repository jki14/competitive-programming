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
int seq[2*N], n, nc, nr;
long long wi, hi, lft[N], rit[N], y[N], val[2*N], cc[N], cr[N];
bool f[N][N];

int cmp1(const int &i, const int &j) {
	if (y[i] == y[j]) return lft[i] > lft[j];
	return y[i] > y[j];
}

int cmp2(const int &i, const int &j) { return val[i] < val[j]; }
int cmp3(const int &i, const int &j) { return val[i] < val[j]; }

void conduct()
{
	int i, j; long long pre, ans, tc;
	for (i = 0; i < n; ++i) scanf("%lld%lld%lld%lld", &lft[i], &y[i], &rit[i], &y[i]);
	for (i = 0; i < n; ++i) { val[i*2] = lft[i]; val[i*2+1] = rit[i]; }
	for (i = 0; i < 2*n; ++i) seq[i] = i; sort(seq, seq+2*n, cmp2);
	for (pre = -1, nc = i = 0; i < 2*n; ) {
		cc[nc] = val[seq[i]]-pre-1; if (cc[nc]) nc++; pre = val[seq[i]];
		for (; i < 2*n && val[seq[i]] == pre; ++i)
			if (seq[i]%2) rit[seq[i]/2] = nc; else lft[seq[i]/2] = nc;
		cc[nc++] = 1;
	} cc[nc] = wi-pre-1; if (cc[nc]) nc++;
	for (i = 0; i < n; ++i) { val[i] = y[i]; seq[i] = i; }sort(seq, seq+n, cmp3);
	for (pre = -1, nr = i = 0; i < n; ) {
		cr[nr] = val[seq[i]]-pre-1; if (cr[nr]) nr++; pre = val[seq[i]];
		for (; i < n && val[seq[i]] == pre; ++i) y[seq[i]] = nr;
		cr[nr++] = 1;
	} cr[nr] = hi-pre-1; if (cr[nr]) nr++; memset(f, 1, sizeof(f));
	for (i = 0; i < n; ++i) for (j = lft[i]; j <= rit[i]; ++j) f[y[i]][j] = 0;
	for (i = 0; i <= nr; ++i) f[i][nc] = 0; for (i = 0; i <= nc; ++i) f[nr][i] = 0; f[nr-1][nc] = f[nr][nc-1] = 1;
	//for (i = nr-1; i >= 0; --i) { for (j = 0; j < nc; ++j) printf("%d", f[i][j]); printf("\n"); }
	for (ans = 0, i = nr-1; i >= 0; --i) {
		for (tc = 0, j = nc-1; j >= 0; --j) if (f[i][j]) {
			f[i][j] = (f[i+1][j] || f[i][j+1]);
			if (!f[i][j]) tc += cc[j];
		} ans += tc * cr[i];
		//if (tc) printf("i:%d tc:%lld\n", i, tc);
	} printf("%lld\n", ans);
}

/*void conduct()
{
	int i; long long ans, len, pre, nl, nr;
	for (i = 0; i < n; ++i) scanf("%lld%lld%lld%lld", &lft[i], &y[i], &rit[i], &y[i]);
	for (i = 0; i < n; ++i) seq[i] = i; sort(seq, seq+n, cmp1);
	if (y[seq[0]] == hi-1 && rit[seq[0]] == wi-1) len = wi; else len = 0; pre = hi;
	for (ans = i = 0; i < n; ) {
		ans += len * (pre-y[seq[i]]-1); pre = y[seq[i]]; nl = nr = len;
		for (; i < n && y[seq[i]] == pre; ++i)
			if (lft[seq[i]] >= wi-len) nr -= rit[seq[i]]-lft[seq[i]]+1;
			else if (rit[seq[i]] >= wi-nl-1) { nr -= rit[seq[i]]+nl+1-wi; nl = wi-lft[seq[i]]; }
		ans += nr; len = nl;
		//printf("pre:%lld len:%lld ans:%lld nr:%lld\n", pre, len, ans, nr);
	} ans += len * pre; printf("%lld\n", ans);
}*/

int main()
{	
	int time = 0;
	while (scanf("%lld%lld%d", &hi, &wi, &n) != EOF && (hi || wi || n)) {
		printf("Case %d: ", ++time); conduct();
	} return 0;
}
