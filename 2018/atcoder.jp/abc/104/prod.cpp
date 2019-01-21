#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int kMod = 1000000007;

int solution(const string &s) {
    //TODO: check if s is valid
    int n = s.length();
    vector<int> f(4, 0);
    f[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 2; j >= 0; --j) {
            if (s[i] == '?') {
                f[j + 1] = (f[j + 1] * 3LL + f[j]) % kMod;
            } else if (s[i] == 'A' + j) {
                f[j + 1] = (f[j + 1] + f[j]) % kMod;
            }
        }
        if (s[i] == '?') f[0] = f[0] * 3LL % kMod;
    }
    return f[3];
}

int main() {
    string s;
    cin >> s;
    cout << solution(s) <<endl;
    return 0;
}
