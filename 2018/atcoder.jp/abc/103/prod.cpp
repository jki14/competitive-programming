#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

struct Request {
    int a, b;
};

static int compare(const Request &lhs, const Request &rhs) {
    return lhs.a < rhs.a;
}

int solution(const int n, vector<Request> reqs) {
    //TODO: check if n and reqs are valid
    sort(reqs.begin(), reqs.end(), compare);
    int m = reqs.size();
    int foo = 0;
    int rig = n + 1;
    for (int i = 0; i < m; ++i) {
        if (reqs[i].a >= rig) {
            foo++;
            rig = reqs[i].b;
        } else {
            rig = min(reqs[i].b, rig);
        }
    }
    if (rig <= n) foo++;
    return foo;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<Request> reqs(m, Request());
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &reqs[i].a, &reqs[i].b);
    }
    printf("%d\n", solution(n, reqs));
    return 0;
}
