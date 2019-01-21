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

const long long MOD = 1000000007;
#define N 1010
char str[N];
long long up[N], dn[N], f[N][N];
int n;

void conduct()
{
	int i, j, k; long long tot;
	f[1][1] = 1; up[0] = 0; up[1] = 1; dn[1] = 1; dn[2] = 0; tot = 1; n = strlen(str);
	for (i = 0; i < n; ++i) {
		j = i+2;
		for (k = 1; k <= j; ++k)
			if (str[i] == 'I') f[j][k] = up[k-1];
			else if (str[i] == 'D') f[j][k] = dn[k];
			else f[j][k] = tot;
		for (up[0] = 0, k = 1; k <= j; ++k) up[k] = (up[k-1] + f[j][k]) % MOD;
		for (dn[j+1] = 0, k = j; k > 0; --k) dn[k] = (dn[k+1] + f[j][k]) % MOD;
		tot = up[j];
	} printf("%lld\n", tot);
}

int main()
{
	while (scanf("%s", str) != EOF) conduct();
	return 0;
}
