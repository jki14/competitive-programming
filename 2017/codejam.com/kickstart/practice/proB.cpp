#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

double Vote(const int n, const int m) {
    //TODO: check if n and m are valid
    vector<vector<double>> dp(n + m + 1, vector<double>(n + 1, 0.0));
    dp[1][1] = n * 1.0 / (n + m);
    for (int i = 1; i < n + m; ++i) {
        for (int j = 1; j <= i && j <= n; ++j) {
            int voted_b = (i - j) / 2;
            int voted_a = voted_b + j;
            if (voted_a + voted_b != i) continue;
            if (voted_a > n) break;
            if (voted_b > m) continue;
            // vote - A
            dp[i + 1][j + 1] += dp[i][j] * (n - voted_a) / (n + m - i);
            // vote - B
            if (j - 1 > 0)
                dp[i + 1][j - 1] += dp[i][j] * (m - voted_b) / (n + m - i);
        }
    }
    double foo = 0.0;
    for (int j = 1; j <= n; ++j) {
        foo += dp[n + m][j];
    }
    return foo;
}

int main(){
    int c;
    cin >> c;
    for (int i = 0; i < c; ++i) {
        int n, m;
        cin >> n >> m;
        cout << "Case #" << i + 1 << ": " << setprecision(14) << fixed << Vote(n, m) << endl;
    }
    return 0;
}
