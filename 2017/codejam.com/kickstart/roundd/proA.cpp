#include <iostream>
#include <vector>
using namespace std;

struct BusSchedule{
    int firsttime;
    int interval;
    int timecost;
};

int earliestarrive(const int t, const BusSchedule &bus) {
    const int round = max((t - bus.firsttime + bus.interval - 1) / bus.interval, 0);
    return bus.firsttime + bus.interval * round + bus.timecost;
}

int GoSightseeing(const int Ts, const int Tf,
        const vector<BusSchedule> &bus){
    const int num_city = bus.size() + 1;
    vector<vector<int>> earliest(num_city - 1, vector<int>());
    earliest[0].resize(2);
    earliest[0][0] = 0;
    earliest[0][1] = Ts;
    if (earliest[0].back() > Tf)earliest[0].pop_back();
    for (int i = 0; i < num_city - 2; ++i) {
        const int max_visited = earliest[i].size() - 1;
        if (max_visited < 0) break;
        earliest[i + 1].resize(max_visited + 2);
        for (int j = 0; j <= max_visited; ++j) {
            earliest[i + 1][j] = earliestarrive(earliest[i][j], bus[i]);
        }
        earliest[i + 1][max_visited + 1] = earliest[i + 1][max_visited] + Ts;
        for (int j = max_visited; j > 0; --j) {
            earliest[i + 1][j] = min(earliest[i + 1][j], earliest[i + 1][j - 1] + Ts);
        }
        while(earliest[i + 1].back() > Tf)earliest[i + 1].pop_back();
    }
    for (int i = earliest[num_city - 2].size() - 1; i >= 0; --i){
        if(earliestarrive(earliest[num_city - 2][i], bus[num_city-2])<=Tf){
            return i;
        }
    }
    return -1;
}

int main(){
    int c;
    cin >> c;
    for (int i = 0; i < c; ++i) {
        int n, Ts, Tf;
        cin >> n >> Ts >> Tf;
        vector<BusSchedule> bus(n - 1, BusSchedule());
        for (int j = 0; j < n - 1; ++j) {
            cin >> bus[j].firsttime >> bus[j].interval >> bus[j].timecost;
        }
        int foo = GoSightseeing(Ts, Tf, bus);
        if (foo >= 0) {
            cout << "Case #" << i + 1 << ": " << foo <<endl;
        } else {
            cout << "Case #" << i + 1 << ": IMPOSSIBLE" << endl;
        }
    }
    return 0;
}
