#include <iostream>
#include <limits>
#include <set>
#include <vector>
using namespace std;

bool Kicksort(const vector<int> &original) {
    const int n = original.size();
    vector<int> seq(n, 0);
    int gap_left, gap_right;
    bool goright;
    if (n & 1) {
        goright = true;
        gap_left = n / 2;
        gap_right = n / 2 - 1;
    } else {
        goright = false;
        gap_left = (n - 1) / 2 + 1;
        gap_right = (n - 1) / 2;
    }
    for (int i = 0; i < n; ++i) {
        if (goright) {
            seq[i] = original[++gap_right];
            goright = false;
        } else {
            seq[i] = original[--gap_left];
            goright = true;
        }
    }
    vector<int> minsuffix(n, 0);
    vector<int> maxsuffix(n, 0);
    minsuffix[n - 1] = seq[n - 1];
    maxsuffix[n - 1] = seq[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        minsuffix[i] = min(seq[i], minsuffix[i + 1]);
        maxsuffix[i] = max(seq[i], maxsuffix[i + 1]);
    }
    for (int i = 0; i < n - 1; ++i) {
        if (seq[i] < minsuffix[i + 1] || seq[i] >= maxsuffix[i]) {
            //pass
        } else {
            return false;
        }
    }
    return true;
}

int main(){
    int c;
    cin >> c;
    for (int i = 0; i < c; ++i) {
        int n;
        cin >> n;
        vector<int> a(n, 0);
        for (int j = 0; j < n; ++j) {
            cin >> a[j];
        }
        if (Kicksort(a)) {
            cout << "Case #" << i + 1 << ": YES" <<endl;
        } else {
            cout << "Case #" << i + 1 << ": NO" <<endl;
        }
    }
    return 0;
}

