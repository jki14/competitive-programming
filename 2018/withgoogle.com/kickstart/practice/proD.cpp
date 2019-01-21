#include <iostream>
#include <numeric>
#include <utility>
#include <vector>
using namespace std;

struct Threshold{
    long long threshold;
    long long tailing;
};

static long long CountSub(const vector<int> &original, const long long threshold) {
    const int n = original.size();
    long long current = 0LL;
    long long foo = 0LL;
    int left = 0;
    for (int i = 0; i < n; ++i) {
        current += original[i];
        while (current > threshold) {
            current -= original[left];
            left++;
        }
        foo += (i - left + 1) * 1LL;
    }
    return foo;
}

static long long SumSub(const vector<int> &original, const long long threshold) {
    const int n = original.size();
    long long current = 0LL;
    long long contribute = 0LL;
    long long foo = 0LL;
    int left = 0;
    for (int i = 0; i < n; ++i) {
        current += original[i];
        contribute += original[i] * (i - left + 1);
        while (current > threshold) {
            contribute -= current;
            current -= original[left];
            left++;
        }
        foo += contribute;
    }
    return foo;
}

static Threshold GetThreshold (const vector<int> &original, const long long k) {
    long long sum = accumulate(original.begin(), original.end(), 0LL);
    Threshold foo;
    long long lef = 0LL, rig = sum;
    while (lef <= rig) {
        long long mid = (lef + rig) / 2;
        long long cnt = CountSub(original, mid);
        if (cnt <= k) {
            if (mid == rig || CountSub(original, mid + 1) > k) {
                foo.threshold = mid;
                if (cnt == k) {
                    foo.tailing = 0LL;
                    return foo;
                } else {
                    foo.tailing = k - cnt;
                }
            }
            lef = mid + 1LL;
        } else {
            rig = mid - 1LL;
        }
    }
    lef = foo.threshold + 1LL;
    rig = sum;
    while (lef <= rig) {
        long long mid = (lef + rig) / 2;
        long long cnt = CountSub(original, mid);
        if (cnt > k) {
            if (mid == lef || CountSub(original, mid - 1) <= k) {
                foo.tailing *= mid;
                return foo;
            }
            rig = mid - 1LL;
        } else {
            lef = mid + 1LL;
        }
    }
    //Branch should never works
    return foo;
}

static long long Calculate(const vector<int> &original, const long long k) {
    if (k == 0LL) return 0LL;
    Threshold threshold = GetThreshold(original, k);
    return SumSub(original, threshold.threshold) + threshold.tailing;
}

vector<long long> SumsOfSums(const vector<int> &original, const vector<pair<long long, long long>> &requests) {
    //TODO: check if original and requests are valid
    const int n = original.size();
    const int m = requests.size();
    vector<long long> foo(m, 0LL);
    for (int i = 0; i < m; ++i) {
        foo[i] = Calculate(original, requests[i].second) - Calculate(original, requests[i].first - 1LL);
    }
    return foo;
}

int main(){
    int c;
    cin >> c;
    for (int i = 0; i < c; ++i) {
        int n, m;
        cin >> n >> m;
        vector<int> original(n, 0);
        for (int j = 0; j < n; ++j) {
            cin >> original[j];
        }
        cout << "Case #" << i + 1 << ":" << endl;
        vector<pair<long long, long long>> requests(m, pair<long long, long long>(0, 0));
        for (int j = 0; j < m; ++j) {
            cin >> requests[j].first;
            cin >> requests[j].second;
        }
        vector<long long> foo = SumsOfSums(original, requests);
        for (const long long row : foo) {
            cout << row << endl;
        }
    }
    return 0;
}
