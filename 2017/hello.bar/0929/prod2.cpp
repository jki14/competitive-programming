#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define sz(x) ((int) (x).size())
typedef double ld;
typedef long long ll;
typedef long long i64;

int n;
const int maxn = 1105;
ld x[maxn], y[maxn];

const int iters = 50;
const int C1 = 5;
const int C2 = 6;

ld f(ld x, ld y) {
    ld res = 0;
    forn (i, n) {
        res += hypotl(::x[i] - x, ::y[i] - y);
    }
    return res;
}

ld lastx, lasty;

ld goy(ld x) {
    ld L = -1e6, R = 1e6;

    forn (iter, iters) {
        ld XL = (C2 * L + C1 * R) / (C2 + C1);
        ld XR = (C1 * L + C2 * R) / (C2 + C1);
        ld YL = f(x, XL);
        ld YR = f(x, XR);
        if (YL < YR)
            R = XR;
        else
            L = XL;
    }
    lasty = (L + R) / 2;
    return f(x, (L + R) / 2);
}

ld gox() {
    ld L = -1e6, R = 1e6;

    forn (iter, iters) {
        ld XL = (C2 * L + C1 * R) / (C2 + C1);
        ld XR = (C1 * L + C2 * R) / (C2 + C1);
        ld YL = goy(XL);
        ld YR = goy(XR);
        if (YL < YR)
            R = XR;
        else
            L = XL;
    }
    lastx = (L + R) / 2;
    return goy((L + R) / 2);
}

void solve() {
    forn (i, n)
        cin >> x[i] >> y[i];
    gox();
    //cerr << "cost " << gox() << '\n';
    cout << lastx << ' ' << lasty << '\n';
}

int main() {
    cerr << fixed;
    cerr.precision(10);
    cout << fixed;
    cout.precision(10);
    while(cin>>n)
        solve();
}
