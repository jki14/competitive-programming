#include <algorithm>
#include <cstdio>
#include <numeric>
#include <vector>
using namespace std;

int solution(const vector<int> &p, const vector<int> &c, const int g) {
    //TODO: check if p and c are valid
    int n = p.size();
    int foo = accumulate(p.begin(), p.end(), 0);
    int tail = 1 << n;
    for (int k = 0; k < tail; ++k) {
        int cost = 0;
        int need = g;
        for (int i = 0; i < n; ++i) {
            if ((k >> i) & 1) {
                cost += p[i];
                need -= p[i] * (i + 1) + c[i];
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            if (need <= 0) break;
            if (((k >> i) & 1) == 0) {
                int num = min((need + i) / (i + 1), p[i] - 1);
                cost += num;
                need -= num * (i + 1);
            }
        }
        if (need <= 0)
            foo = min(cost, foo);
    }
    return foo;
}

int main() {
    int n, g;
    scanf("%d%d", &n, &g);
    g /= 100;
    vector<int> p(n, 0);
    vector<int> c(n, 0);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &p[i], &c[i]);
        c[i] /= 100;
    }
    printf("%d\n", solution(p, c, g));
    return 0;
}
