#include "bits/stdc++.h"
using namespace std;

typedef pair<int, int> pii;

struct edge_t {
    int u, v, w;
    edge_t (const int _u, const int _v, const int _w) {
        this->u = _u;
        this->v = _v;
        this->w = _w;
    }
};

int main() {
    int l;
    while (scanf("%d", &l) != EOF) {
        vector<edge_t> edges;
        int n = 0;
        for (int i = 1; i <= l; i <<= 1) {
            n++;
        }
        int m = 1 << (n - 1);
        for (int i = 2; i <= n; i++) {
            m >>= 1;
            edges.push_back(edge_t(i, i + 1, 0));
            edges.push_back(edge_t(i, i + 1, m));
        }
        int p = 0;
        m = 1 << (n - 1);
        for (int i = 1; i <= n; ++i) {
            if (l & m) {
                edges.push_back(edge_t(1, i + 1, p));
                p |= m;
            }
            m >>= 1;
        }
        if (n + 1 > 20) {
            vector<pii> x, y, xy;
            for (vector<edge_t>::iterator it = edges.begin(); it != edges.end(); ) {
                if (it->v == n) {
                    x.push_back(make_pair(it->u, it->w));
                    it = edges.erase(it);
                } else if (it->v == n + 1) {
                    if (it->u != n) {
                        y.push_back(make_pair(it->u, it->w));
                    } else {
                        xy.push_back(make_pair(it->u, it->w));
                    }
                    it = edges.erase(it);
                } else {
                    it++;
                }
            }
            for (const pii &lhs : x) {
                for (const pii &rhs : xy) {
                    y.push_back(make_pair(lhs.first, lhs.second + rhs.second));
                }
            }
            for (const pii &combined : y) {
                edges.push_back(edge_t(combined.first, n, combined.second));
            }
            n--;
        }
        printf("%d %lu\n", n + 1, edges.size());
        for (const edge_t &e : edges) {
            printf("%d %d %d\n", e.u, e.v, e.w);
        }
    }
    return 0;
}
