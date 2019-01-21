#include <iostream>
#include <utility>
#include <vector>
using namespace std;

vector<int> GBusCount(const vector<pair<int, int>> buses, const vector<int> queries) {
    //TODO: check parameters are valid
    int num_bus = buses.size();
    int num_city = 0;
    int num_query = queries.size();
    for (int i = 0; i < num_bus; ++i) {
        num_city = max(buses[i].second + 1, num_city);
    }
    for (int i = 0; i < num_query; ++i) {
        num_city = max(queries[i] + 1, num_city);
    }
    vector<int> deltas(num_city, 0);
    for (int i = 0; i < num_bus; ++i) {
        deltas[buses[i].first]++;
        if (buses[i].second < num_city - 1) {
            deltas[buses[i].second + 1]--;
        }
    }
    vector<int> presum(deltas.begin(), deltas.end());
    for (int i = 1; i < num_city; ++i) {
        presum[i] += presum[i - 1];
    }
    vector<int> foo(num_query, 0);
    for (int i = 0; i < num_query; ++i) {
        foo[i] = presum[queries[i]];
    }
    return foo;
}

int main(){
    int c;
    cin >> c;
    for (int i = 0; i < c; ++i) {
        int n;
        cin >> n;
        vector<pair<int, int>> buses(n, pair<int, int>(0, 0));
        for (int j = 0; j < n; ++j) {
            cin >> buses[j].first >> buses[j].second;
            buses[j].first--;
            buses[j].second--;
        }
        int m;
        cin >> m;
        vector<int> queries(m, 0);
        for (int j = 0; j < m; ++j) {
            cin >> queries[j];
            queries[j]--;
        }
        vector<int> foo = GBusCount(buses, queries);
        cout << "Case #" << i + 1 << ":";
        for (const int el : foo) {
            cout << " " << el;
        }
        cout << endl;
    }
    return 0;
}
