#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct interval_t {
    int lef, rig;
};

int WatsonAndIntervals(const vector<interval_t> &intervals) {
    map<int, int> renumber;
    for (const interval_t &interval : intervals) {
        renumber.insert(make_pair(interval.lef, 0));
        renumber.insert(make_pair(interval.rig + 1, 0));
    }
    int n = intervals.size();
    int m = 0;
    for (auto it = renumber.begin(); it != renumber.end(); ++it) {
        it->second = m++;
    }
    vector<int> realp(m, 0);
    for (auto it = renumber.begin(); it != renumber.end(); ++it) {
        realp[it->second] = it->first;
    }
    vector<int> score(n, 0);
    vector<int> delta(m, 0);
    vector<int> magic(m, 0);
    for (int i = 0; i < n; ++i) {
        int posin = renumber[intervals[i].lef];
        int posout = renumber[intervals[i].rig + 1];
        delta[posin] += 1;
        magic[posin] ^= i;
        delta[posout] -= 1;
        magic[posout] ^= i;
    }
    int covered = 0;
    int stacked = 0;
    int magiced = 0;
    for (int i = 0; i < m; ++i) {
        if (stacked > 0) {
            covered += realp[i] - realp[i - 1];
        }
        if (stacked == 1) {
            score[magiced] += realp[i] - realp[i - 1];
        }
        stacked += delta[i];
        magiced ^= magic[i];
    }
    return covered - *max_element(score.begin(), score.end());
}

int main(){
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n, m;
        cin >> n;
        vector<int> x(n, 0);
        vector<int> y(n, 0);
        int a, b, c1, c2;
        cin >> x[0] >> y[0] >> a >> b >> c1 >> c2 >> m;
        for (int j = 1; j < n; ++j) {
            x[j] = (x[j - 1] * 1LL * a + y[j - 1] * 1LL * b + c1) % m;
            y[j] = (y[j - 1] * 1LL * a + x[j - 1] * 1LL * b + c2) % m;
        }
        vector<interval_t> intervals(n, interval_t());
        for (int j = 0; j < n; ++j) {
            intervals[j].lef = min(x[j], y[j]);
            intervals[j].rig = max(x[j], y[j]);
        }
        cout << "Case #" << i + 1 << ": " << WatsonAndIntervals(intervals) << endl;
        cout.flush();
    }
    return 0;
}
