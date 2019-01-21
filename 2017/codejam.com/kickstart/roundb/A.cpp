#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e4 + 5;

int po[N];
int arr[N];
int n;

void precompute() {
	po[0] = 1;
	for(int i = 1 ; i < N ; i++) {
		po[i] = 2 * po[i-1] % MOD;
	}
}

void read() {
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; i++)
		scanf("%d", arr + i);
}

int solve() {
	int ret = 0;
	for(int i = 1 ; i <= n ; i++) {
		int kiri = i-1;
		int kanan = n-i;

		long long tambah = 1ll * po[kiri] * (arr[i]) % MOD;
		long long kurang = 1ll * po[kanan] * (-arr[i]) % MOD;

		ret = (ret + tambah) % MOD;
		ret = (ret + kurang) % MOD;
	}

	if(ret < 0) ret += MOD;
	return ret;
}

int main() {
	precompute();
	int t; cin >> t;
	for(int tc = 1 ; tc <= t ; tc++) {
		read();
		int ret = solve();
		printf("Case #%d: %d\n", tc, ret);
	}
	return 0;
}