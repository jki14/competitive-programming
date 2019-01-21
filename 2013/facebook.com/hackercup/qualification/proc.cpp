#include <cstdio>
#include <set>
#include <unordered_set>
#include <vector>
using namespace std;

int solution(const vector<int> a, const int n){
    //TODO: check if a and n are valid
    int m = a.size();
    vector<int> b(m * 2 + 1, 0);
    unordered_set<int> chest;
    for (int i = m - 1; i >= 0; --i) {
        if (chest.count(a[i])) {
            b[i] = m;
        } else {
            b[i] = a[i];
            chest.insert(a[i]);
        }
    }
    int cur = 0;
    for (int i = m; i < (int)b.size(); ++i) {
        while(chest.count(cur))
            ++cur;
        b[i] = cur;
        chest.insert(cur);
        chest.erase(b[i - m]);
        if (cur > b[i - m]) {
            cur = b[i - m];
        }
    }
    if ((int)b.size() < n) {
        return b[m + (n - 1 - m) % (m + 1)];
    } else {
        return b[n - 1];
    }
}

int main() {
    int case_num;
    scanf("%d", &case_num);
    for (int case_id = 1; case_id <= case_num; ++case_id) {
        int n, m;
        scanf("%d%d", &n, &m);
        int x, y, z, r;
        scanf("%d%d%d%d", &x, &y, &z, &r);
        vector<int> a(m, x);
        for (int i = 1; i < m; ++i) {
            a[i] = (y * 1LL * a[i - 1] + z) % r;
        }
        printf("Case #%d: %d\n", case_id, solution(a, n));
    }
    return 0;
}
