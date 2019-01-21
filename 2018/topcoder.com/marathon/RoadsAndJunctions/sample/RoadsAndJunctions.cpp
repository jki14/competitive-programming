// C++11
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class RoadsAndJunctions {
public:
    int NC;
    vector<int> buildJunctions(int S, vector<int> cities, double junctionCost, double failureProbability) {
        // store number of cities for building the roads
        NC = cities.size() / 2;
        // build one junction at (0,0)
        return vector<int>({0, 0});
    }
    vector<int> buildRoads(vector <int> junctionStatus) {
        // build a road from the single junction to each city
        // (we assume that it was built, but don't check it)
        vector<int> ret(2 * NC);
        for (int i = 0; i < NC; ++i) {
            ret[2 * i] = NC;
            ret[2 * i + 1] = i;
        }
        return ret;
    }
};
// -------8<------- end of solution submitted to the website -------8<-------

template<class T> void getVector(vector<T>& v) {
    for (int i = 0; i < v.size(); ++i)
        cin >> v[i];
}

int main() {
    RoadsAndJunctions rj;
    int S, C;
    cin >> S >> C;
    vector<int> cities(C);
    getVector(cities);
    double junctionCost, failureProbability;
    cin >> junctionCost >> failureProbability;

    vector<int> ret = rj.buildJunctions(S, cities, junctionCost, failureProbability);
    cout << ret.size() << endl;
    for (int i = 0; i < (int)ret.size(); ++i)
        cout << ret[i] << endl;
    cout.flush();
    
    int J;
    cin >> J;
    vector<int> junctionStatus(J);
    getVector(junctionStatus);

    ret = rj.buildRoads(junctionStatus);
    cout << ret.size() << endl;
    for (int i = 0; i < (int)ret.size(); ++i)
        cout << ret[i] << endl;
    cout.flush();
}
