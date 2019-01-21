#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

double LuckyDip(const vector<int> &items, const int k) {
    //TODO: check items is valid
    const int num_items = items.size();
    vector<int> sorted_items(items.begin(), items.end());
    sort(sorted_items.begin(), sorted_items.end());
    vector<double> prefix_sum(num_items + 1, 0.);
    for (int i = 0; i < num_items; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + sorted_items[i];
    }
    double current = prefix_sum[num_items] / num_items;
    int rerolled = 0;
    for (int i = 0; i < k; ++i) {
        double prev = current;
        while (rerolled < num_items && sorted_items[rerolled] < prev * 1.)
            ++rerolled;
        current = (prev * rerolled + prefix_sum[num_items] - prefix_sum[rerolled]) / num_items;
    }
    return current;
}

int main() {
    int c;
    cin >> c;
    for (int i = 0; i < c; ++i) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n, 0);
        for (int j = 0; j < n; ++j) {
            cin >> a[j];
        }
        cout << "Case #" << i + 1 << ": " << setprecision(13) << fixed << LuckyDip(a, k) << endl;
    }
    return 0;
}
