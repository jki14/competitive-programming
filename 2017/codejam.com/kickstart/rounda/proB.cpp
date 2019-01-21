#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool PatternsOverlap(const string &pattern_a, const string &pattern_b) {
    //TODO: check if pattern_a and pattern_b are valid
    int n = pattern_a.length();
    int m = pattern_b.length();
    vector<vector<bool>> matched(n + 1, vector<bool>(m + 1, false));
    vector<int> colstar(m + 1, 0x3f3f3f3f);
    matched[0][0] = true;
    for (int i = 1; i <= n; ++i) {
        if (pattern_a[i - 1] != '*') break;
        matched[i][0] = true;
    }
    for (int i = 1; i <= m; ++i) {
        if (pattern_b[i - 1] != '*') break;
        matched[0][i] = true;
        colstar[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        int nonstar = 0x3f3f3f3f;
        if (matched[i - 1][0]) nonstar = 0;
        for (int j = 1; j <= m; ++j) {
            if (matched[i - 1][j]) {
                nonstar = 0;
            } else if (pattern_b[j - 1] != '*') {
                nonstar++;
            }
            if (matched[i][j - 1]) {
                colstar[j] = 0;
            } else if (pattern_a[i - 1] != '*') {
                colstar[j]++;
            }
            if (pattern_a[i - 1] != '*' && pattern_b[j - 1] != '*') {
                if (matched[i - 1][j - 1] && pattern_a[i - 1] == pattern_b[j - 1]) {
                    matched[i][j] = true;
                    //cerr << "+matched[" << i << "][" << j << "] = true;" << endl;
                }
            } else {
                if ((pattern_a[i - 1] == '*' && nonstar <= 4)
                        || (pattern_b[j - 1] == '*' && colstar[j] <= 4)) {
                    matched[i][j] = true;
                    //cerr << "*matched[" << i << "][" << j << "] = true;" << endl;
                    //cerr << "nonstar = " << nonstar << endl;
                    //cerr << "colstar[" << j << "] = " << colstar[j] << endl;
                }
            }
        }
    }
    return matched[n][m];
}

int main() {
    int c;
    cin >> c;
    for (int i = 0; i < c; ++i) {
        string lhs, rhs;
        cin >> lhs >> rhs;
        cout << "Case #" << i + 1 << ": ";
        if (PatternsOverlap(lhs, rhs)) {
            cout << "TRUE";
        } else {
            cout << "FALSE";
        }
        cout << endl;
    }
    return 0;
}
