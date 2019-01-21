#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

inline static long long subsum(const int lef, const int rig, const vector<long long> &s) {
    return s[rig] - s[lef - 1];
}

long long solution(const vector<int> &a) {
    int n = a.size();
    vector<long long> s(n + 1, 0LL);
    for (int i = 0; i < n; ++i) {
        s[i + 1] = s[i] + a[i] * 1LL;
    }
    long long foo = 0x3f3f3f3f3f3f3f3fLL;
    int lef = 1;
    int rig = 3;
    for (int mid = 2; mid <= n; ++mid) {
        while(lef + 1 < mid && abs(subsum(1, lef, s) - subsum(lef + 1, mid, s)) >=  abs(subsum(1, lef + 1, s) - subsum(lef + 2, mid, s)))
            lef++;
        while(rig + 1 < n && abs(subsum(mid + 1, rig, s) - subsum(rig + 1, n , s)) >= abs(subsum(mid + 1, rig + 1, s) - subsum(rig + 2, n, s)))
            rig++;
        foo = min(
            max(max(max(subsum(1, lef, s), subsum(lef + 1, mid, s)), subsum(mid + 1, rig, s)), subsum(rig + 1, n, s))
                - min(min(min(subsum(1, lef, s), subsum(lef + 1, mid, s)), subsum(mid + 1, rig, s)), subsum(rig + 1, n, s))
        , foo);
    }
    return foo;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n, 0);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    printf("%lld\n", solution(a));
    return 0;
}
