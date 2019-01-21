#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

double solution(const int n, const int ps, const int pr, const int pi, const int pu, const int pw, const int pd, const int pl){
    //TODO check if parameters are all valid.
    vector<vector<vector<double>>> f(n + n, vector<vector<double>>(n + 1, vector<double>(1001, 0.0)));
    f[0][0][pi] = 1.0;
    for(int i = 0; i < n + n; ++i){
        for(int j = max(i - n + 1, 0); j <= i && j < n; ++j){
            for(int k = 0; k <= 1000; ++k){
                double contribute;
                //sunny-win
                contribute = f[i][j][k] * (k * 0.001) * (ps * 0.001);
                f[i + 1][j + 1][k] += contribute * (1.0 - pw * 0.001);
                f[i + 1][j + 1][min(k + pu, 1000)] += contribute * (pw * 0.001);
                //sunny-lose
                contribute = f[i][j][k] * (k * 0.001) * (1.0 - ps * 0.001);
                f[i + 1][j][k] += contribute * (1.0 - pl * 0.001);
                f[i + 1][j][max(k - pd, 0)] += contribute * (pl * 0.001);
                //raining-win
                 contribute = f[i][j][k] * (1.0 - k * 0.001) * (pr * 0.001);
                f[i + 1][j + 1][k] += contribute * (1.0 - pw * 0.001);
                f[i + 1][j + 1][min(k + pu, 1000)] += contribute * (pw * 0.001);
                //raining-lose
                contribute = f[i][j][k] * (1.0 - k * 0.001) * (1.0 - pr * 0.001);
                f[i + 1][j][k] += contribute * (1.0 - pl * 0.001);
                f[i + 1][j][max(k - pd, 0)] += contribute * (pl * 0.001);
            }
        }
    }
    double foo = 0.0;
    for(int i = n; i < n + n; ++i){
        for(int k = 0; k <= 1000; ++k){
            foo += f[i][n][k];
        }
    }
    return foo;
}

int main(){
    int case_num;
    scanf("%d", &case_num);
    for(int case_id = 1; case_id <= case_num; ++case_id){
        int k;
        double ps, pr, pi, pu, pw, pd, pl;
        scanf("%d%lf%lf%lf%lf%lf%lf%lf", &k, &ps, &pr, &pi, &pu, &pw, &pd, &pl);
        printf("Case #%d: %.6f\n", case_id, solution(k, ps * 1000.0, pr * 1000.0, pi * 1000.0, pu * 1000.0, pw * 1000.0, pd * 1000.0, pl * 1000.0));
        fflush(stdout);
    }
    return 0;
}
