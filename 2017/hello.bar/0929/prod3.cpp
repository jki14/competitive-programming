#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef double ld;

using namespace std;

ld xx, yy;
ld x[12000];
ld y[12000];
int n;
const int IT1 = 70;

const double eps=1e-9;

ld get(ld xx, ld yy) {
        ld sum = 0;
        for (int i = 0; i < n; ++i)
                sum += sqrt((xx - x[i]) * (xx - x[i]) + (yy - y[i]) * (yy - y[i]));
        return sum;
}

ld gety(ld xx) {
        ld lx = -1e6;
        ld rx = 1e6;
        for (int it = 0; it < IT1; ++it) {
                ld m1 = lx + 4 * (rx - lx) / 9;
                ld m2 = m1 + (rx - lx) / 9;
                if (get(xx, m1) > get(xx, m2)+eps)
                        lx = m1;
                else
                        rx = m2;
        }
        yy = (lx + rx) / 2;
        return get(xx, yy);
}

void solve() {
        for (int i = 0; i < n; ++i)
                cin >> x[i] >> y[i];
        ld lx = -1e6;
        ld rx = 1e6;
        for (int it = 0; it < IT1; ++it) {
                ld m1 = lx + 4 * (rx - lx) / 9;
                ld m2 = m1 + (rx - lx) / 9;
                if (gety(m1) > gety(m2)+eps)
                        lx = m1;
                else
                        rx = m2;
        }
        xx = (lx + rx) / 2;
        gety(xx);
        cout.setf(ios::fixed);
        cout.precision(10);
        cout << xx << " " << yy << "\n";
}

int main() {
        while(cin>>n){
                solve();
        }
        return 0;
}

