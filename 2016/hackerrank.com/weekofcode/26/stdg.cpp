#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1E7 + 100;
const int MOD = 1E9 + 7;
long long a[MAXN];
long long f[MAXN];
long long bin(long long x, long long y) {
    if (y == 0) {
        return 1;
    }
    long long u = bin(x, y/2);
    if (y % 2 == 0) {
        return u*u % MOD;
    }
    else {
        return u*u % MOD * x % MOD;
    }
}


int main() {
int n, m;
cin >> n >> m;
long long all = (bin(2, m) - 1 + MOD) % MOD;
a[1] = all;
for (int i = 2; i <= n; i++) {
    a[i] = a[i - 1] * (all - i + 1 + MOD) % MOD;
}
f[0] = 1;
for (int i = 2; i <= n; i++) {
    f[i] = a[i - 1] - f[i - 1] - ((long long)i - 1)*(all - (i - 2) + MOD) % MOD *f[i - 2] % MOD;
    if (f[i] >= 0) {
        f[i] %= MOD;
    }
    else {
        f[i] = MOD + f[i] % MOD;
    }
}
long long ans = (a[n] - f[n] + MOD) % MOD;
cout << ans << endl;
return 0;
}
